#include "serialport.h"
#include <QDebug>

SerialPort::SerialPort(QObject *parent)
    : QObject(parent), m_serialPort(new QSerialPort(this)), m_timer(new QTimer(this))
{
    m_timer->setSingleShot(true);
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPort::handleReadyRead);
    connect(m_timer, &QTimer::timeout, this, &SerialPort::handleTimeout);
}

SerialPort::~SerialPort()
{
    close();
    delete m_serialPort;
}

bool SerialPort::open(const QString &portName, int baudRate, const QString &parity, const QString &dataBits, const QString &stopBits)
{
    if (m_serialPort->isOpen()) {
        close();
    }

    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(baudRate);

    // 设置校验位
    m_serialPort->setParity(stringToParity(parity));

    // 设置数据位
    m_serialPort->setDataBits(stringToDataBits(dataBits));

    // 设置停止位
    m_serialPort->setStopBits(stringToStopBits(stopBits));

    // 设置流控制
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (!m_serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open serial port:" << m_serialPort->errorString();
        return false;
    }

    qDebug() << "Serial port opened:" << portName;
    return true;
}

void SerialPort::close()
{
    if (m_serialPort->isOpen()) {
        m_serialPort->close();
        qDebug() << "Serial port closed";
    }
}

bool SerialPort::writeData(const QByteArray &data)
{
    if (!m_serialPort->isOpen()) {
        qDebug() << "Serial port is not open";
        return false;
    }

    qint64 bytesWritten = m_serialPort->write(data);
    if (bytesWritten == -1) {
        qDebug() << "Failed to write data to serial port:" << m_serialPort->errorString();
        return false;
    }

    if (bytesWritten != data.size()) {
        qDebug() << "Partial data written to serial port:" << bytesWritten << "of" << data.size();
    }

    m_serialPort->flush(); // 确保数据发送
    return true;
}

QStringList SerialPort::availablePorts()
{
    QStringList ports;
    const auto &portInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : portInfos) {
        ports << info.portName();
    }
    return ports;
}

bool SerialPort::isOpen() const
{
    return m_serialPort->isOpen();
}

void SerialPort::handleReadyRead()
{
    if (!m_serialPort->bytesAvailable()) {
        return;
    }

    QByteArray newData = m_serialPort->readAll();
    if (!newData.isEmpty()) {
        m_tempData.append(newData); // 累加字节数据
        m_timer->start(100); // 重新启动定时器，超时时间设为 100 毫秒
    }
}

void SerialPort::handleTimeout()
{
    if (!m_tempData.isEmpty()) {
        QStringDecoder decoder(QStringDecoder::System);
        QString receivedString = decoder.decode(m_tempData);
        // qDebug() << m_tempData;
        if(receivedString.isEmpty() || receivedString != "\n"){
            if(receivedString.endsWith("\n")){
                receivedString.chop(1);
            }
            emit dataReceived(receivedString);
            m_tempData.clear(); // 清空缓冲区
        }
    }
}

// 辅助函数：将字符串转换为 QSerialPort::Parity
QSerialPort::Parity SerialPort::stringToParity(const QString &parity)
{
    if (parity == "EVEN")
        return QSerialPort::EvenParity;
    else if (parity == "ODD")
        return QSerialPort::OddParity;
    else if (parity == "MARK")
        return QSerialPort::MarkParity;
    else if (parity == "SPACE")
        return QSerialPort::SpaceParity;
    else
        return QSerialPort::NoParity;
}

// 辅助函数：将字符串转换为 QSerialPort::DataBits
QSerialPort::DataBits SerialPort::stringToDataBits(const QString &dataBits)
{
    if (dataBits == "5 bits")
        return QSerialPort::Data5;
    else if (dataBits == "6 bits")
        return QSerialPort::Data6;
    else if (dataBits == "7 bits")
        return QSerialPort::Data7;
    else if (dataBits == "8 bits")
        return QSerialPort::Data8;
    else
        return QSerialPort::Data8;
}

// 辅助函数：将字符串转换为 QSerialPort::StopBits
QSerialPort::StopBits SerialPort::stringToStopBits(const QString &stopBits)
{
    if (stopBits == "1 bit")
        return QSerialPort::OneStop;
    else if (stopBits == "1.5 bits")
        return QSerialPort::OneAndHalfStop;
    else if (stopBits == "2 bits")
        return QSerialPort::TwoStop;
    else
        return QSerialPort::OneStop;
}

