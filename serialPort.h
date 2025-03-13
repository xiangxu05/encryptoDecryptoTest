#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QTimer>
#include <QStringConverter>
#include <QStringDecoder>

class SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(QObject *parent = nullptr);
    ~SerialPort();

    // 打开串口
    bool open(const QString &portName, int baudRate, const QString &parity, const QString &dataBits, const QString &stopBits);

    // 关闭串口
    void close();

    // 写入数据
    bool writeData(const QByteArray &data);

    // 获取可用的串口列表
    static QStringList availablePorts();

    // 检查串口是否打开
    bool isOpen() const;

signals:
    // 接收到数据时发出的信号
    void dataReceived(const QString &data);

private slots:
    // 处理串口接收到的数据
    void handleReadyRead();
    void handleTimeout();
private:
    QSerialPort *m_serialPort;
    QTimer *m_timer;
    QByteArray m_tempData;
    // 辅助函数：将字符串转换为 QSerialPort::Parity
    QSerialPort::Parity stringToParity(const QString &parity);

    // 辅助函数：将字符串转换为 QSerialPort::DataBits
    QSerialPort::DataBits stringToDataBits(const QString &dataBits);

    // 辅助函数：将字符串转换为 QSerialPort::StopBits
    QSerialPort::StopBits stringToStopBits(const QString &stopBits);
};

#endif // SERIALPORT_H
