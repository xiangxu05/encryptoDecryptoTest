#ifndef ENCRYPTO_H
#define ENCRYPTO_H
#include <QObject>
#include <QDateTime>
#include <QString>
#include <bitset>
#include <QFile>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/sha.h>

struct Key_Information {
    QString Key;//密钥
    int lifespan;//有效时间期限
    int curtime ;//原始时间期限占的位数
};

class encrypto : public QObject
{
    Q_OBJECT
public:
    // 获取单例实例
    static encrypto* getInstance();

    // 禁止拷贝构造和赋值
    encrypto(const encrypto&) = delete;
    encrypto& operator=(const encrypto&) = delete;

    // 公共方法
    QString getEncryptoKey(int lifespan);
    QString getDecryptoKey();
    bool encryptFile(const QString &inputFile, const QString &outputFile, const QString &key);
    bool decryptFile(const QString &inputFile, const QString &outputFile, const QString &key);
private:
    encrypto();
    ~encrypto();

    // 静态成员变量，用于存储单例实例
    static encrypto* instance;
    Key_Information info;
    QByteArray iv = "1234567890123456";

    QByteArray generateFixedLengthKey(const QString &key);
};

#endif // ENCRYPTO_H
