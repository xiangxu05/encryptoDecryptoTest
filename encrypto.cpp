#include "encrypto.h"

encrypto* encrypto::instance = nullptr;

encrypto::encrypto() : QObject(nullptr)
{
}

encrypto::~encrypto()
{
}

encrypto* encrypto::getInstance()
{
    if (instance == nullptr) {
        instance = new encrypto();
    }
    return instance;
}

int binary_bits_required(int value) {
    if (value == 0) {
        return 1;
    }
    else {
        int bits = 0;
        while (value > 0) {
            value >>= 1;
            bits++;
        }
        return bits;
    }
}

std::bitset<32> getBitsFromEnd(const std::bitset<32>& binaryBits, int numBits) {//获取后半部分的二进制位
    std::bitset<32> mask((1 << numBits) - 1);
    return binaryBits & mask;
}

std::bitset<32> getBitsFromStart(const std::bitset<32>& binaryBits, int numBits) {//获取前半部分的二进制位
    std::bitset<32> mask((1 << numBits) - 1);
    return (binaryBits >> (32 - numBits)) & mask;
}

QString encrypto::getEncryptoKey(int time){
    quint32 timestamp = QDateTime::currentSecsSinceEpoch();
    std::bitset<32> timestampBitset(timestamp);

    int lifeSpan = binary_bits_required(time);
    int curTime = getBitsFromEnd(timestampBitset, lifeSpan).to_ulong();
    timestampBitset = (std::bitset <32>(getBitsFromStart(timestampBitset, 32 - lifeSpan).to_ulong() - 1) << lifeSpan);

    info.Key = QString::fromStdString(timestampBitset.to_string());
    info.lifespan = time + curTime + 1;
    info.curtime = lifeSpan;

    return info.Key;
}

QString encrypto::getDecryptoKey(){
    quint32 timestamp = QDateTime::currentSecsSinceEpoch();
    std::bitset<32> timestampBitset(timestamp - info.lifespan);

    timestampBitset = (std::bitset <32>(getBitsFromStart(timestampBitset, 32 - info.curtime).to_ulong()) << info.curtime);
    info.Key = QString::fromStdString(timestampBitset.to_string());
    return info.Key;
}

QByteArray encrypto::generateFixedLengthKey(const QString &key) {
    // 将 QString 转换为 QByteArray
    QByteArray keyData = key.toUtf8();

    // 使用 EVP 接口进行 SHA-256 哈希
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    if (!mdctx) {
        qWarning() << "Failed to create EVP_MD_CTX";
        return QByteArray();
    }

    if (EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr) != 1) {
        qWarning() << "Failed to initialize digest";
        EVP_MD_CTX_free(mdctx);
        return QByteArray();
    }

    if (EVP_DigestUpdate(mdctx, keyData.constData(), keyData.size()) != 1) {
        qWarning() << "Failed to update digest";
        EVP_MD_CTX_free(mdctx);
        return QByteArray();
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLen = 0;

    if (EVP_DigestFinal_ex(mdctx, hash, &hashLen) != 1) {
        qWarning() << "Failed to finalize digest";
        EVP_MD_CTX_free(mdctx);
        return QByteArray();
    }

    EVP_MD_CTX_free(mdctx);

    // 将哈希结果转换为 QByteArray
    return QByteArray(reinterpret_cast<char*>(hash), hashLen);
}

bool encrypto::encryptFile(const QString &inputFile, const QString &outputFile, const QString &key) {
    // 生成固定长度的密钥
    QByteArray fixedKey = generateFixedLengthKey(key);

    QFile inFile(inputFile);
    if (!inFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open input file:" << inFile.errorString();
        return false;
    }

    QFile outFile(outputFile);
    if (!outFile.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open output file:" << outFile.errorString();
        inFile.close();
        return false;
    }

    // 初始化加密上下文
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        qWarning() << "Failed to create cipher context";
        inFile.close();
        outFile.close();
        return false;
    }

    // 设置加密模式和密钥
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, reinterpret_cast<const unsigned char*>(fixedKey.constData()), reinterpret_cast<const unsigned char*>(iv.constData())) != 1) {
        qWarning() << "Failed to initialize encryption";
        EVP_CIPHER_CTX_free(ctx);
        inFile.close();
        outFile.close();
        return false;
    }

    // 读取文件内容并加密
    QByteArray inData, outData;
    bool updateOk, finalOk;
    int bytesWritten;

    // 读取文件内容
    inData = inFile.read(4096);
    while (!inData.isEmpty()) {
        // 更新加密数据
        outData.resize(inData.size() + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
        updateOk = EVP_EncryptUpdate(ctx, reinterpret_cast<unsigned char *>(outData.data()), &bytesWritten,
                                     reinterpret_cast<const unsigned char *>(inData.constData()), inData.size());
        if (!updateOk) {
            qWarning() << "Encryption update failed";
            EVP_CIPHER_CTX_free(ctx);
            inFile.close();
            outFile.close();
            return false;
        }
        outData.resize(bytesWritten);
        outFile.write(outData);
        inData = inFile.read(4096);
    }

    // 最终化加密
    outData.resize(EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    finalOk = EVP_EncryptFinal_ex(ctx, reinterpret_cast<unsigned char *>(outData.data()), &bytesWritten);
    if (!finalOk) {
        qWarning() << "Encryption finalization failed";
        EVP_CIPHER_CTX_free(ctx);
        inFile.close();
        outFile.close();
        if (QFile::remove(outputFile)) {
            qInfo() << "Original file removed successfully.";
        } else {
            qWarning() << "Failed to remove original file.";
        }
        return false;
    }
    outData.resize(bytesWritten);
    outFile.write(outData);

    // 清理
    EVP_CIPHER_CTX_free(ctx);
    inFile.close();
    outFile.close();

    // 加密成功后，删除原始文件
    if (QFile::remove(inputFile)) {
        qInfo() << "Original file removed successfully.";
    } else {
        qWarning() << "Failed to remove original file.";
        return false;
    }

    return true;
}

bool encrypto::decryptFile(const QString &inputFile, const QString &outputFile, const QString &key) {
    // 生成固定长度的密钥
    QByteArray fixedKey = generateFixedLengthKey(key);

    QFile inFile(inputFile);
    if (!inFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open input file:" << inFile.errorString();
        return false;
    }

    QFile outFile(outputFile);
    if (!outFile.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open output file:" << outFile.errorString();
        inFile.close();
        return false;
    }

    // 初始化解密上下文
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        qWarning() << "Failed to create cipher context";
        inFile.close();
        outFile.close();
        return false;
    }

    // 设置解密模式和密钥
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, reinterpret_cast<const unsigned char*>(fixedKey.constData()), reinterpret_cast<const unsigned char*>(iv.constData())) != 1) {
        qWarning() << "Failed to initialize decryption";
        EVP_CIPHER_CTX_free(ctx);
        inFile.close();
        outFile.close();
        return false;
    }

    // 读取文件内容并解密
    QByteArray inData, outData;
    bool updateOk, finalOk;
    int bytesWritten;

    // 读取文件内容
    inData = inFile.read(4096);
    while (!inData.isEmpty()) {
        // 更新解密数据
        outData.resize(inData.size() + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
        updateOk = EVP_DecryptUpdate(ctx, reinterpret_cast<unsigned char *>(outData.data()), &bytesWritten,
                                     reinterpret_cast<const unsigned char *>(inData.constData()), inData.size());
        if (!updateOk) {
            qWarning() << "Decryption update failed";
            EVP_CIPHER_CTX_free(ctx);
            inFile.close();
            outFile.close();
            return false;
        }
        outData.resize(bytesWritten);
        outFile.write(outData);
        inData = inFile.read(4096);
    }

    // 最终化解密
    outData.resize(EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    finalOk = EVP_DecryptFinal_ex(ctx, reinterpret_cast<unsigned char *>(outData.data()), &bytesWritten);
    if (!finalOk) {
        qWarning() << "Decryption finalization failed";
        EVP_CIPHER_CTX_free(ctx);
        inFile.close();
        outFile.close();
        if (QFile::remove(outputFile)) {
            qInfo() << "Original file removed successfully.";
        } else {
            qWarning() << "Failed to remove original file.";
        }
        return false;
    }
    outData.resize(bytesWritten);
    outFile.write(outData);

    // 清理
    EVP_CIPHER_CTX_free(ctx);
    inFile.close();
    outFile.close();

    // 解密成功后，删除原始文件
    if (QFile::remove(inputFile)) {
        qInfo() << "Original file removed successfully.";
    } else {
        qWarning() << "Failed to remove original file.";
        return false;
    }

    return true;
}
