#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(QObject *parent = nullptr);
    ~SerialPort();

    // 打开串口
    bool open(const QString &portName, int baudRate = 115200);

    // 关闭串口
    void close();

    // 写入数据
    bool writeData(const QByteArray &data);

    // 读取数据
    QByteArray readData();

    // 获取可用的串口列表
    QStringList availablePorts();

    // 检查串口是否打开
    bool isOpen() const;

signals:
    // 接收到数据时发出的信号
    void dataReceived(const QByteArray &data);

private slots:
    // 处理串口接收到的数据
    void handleReadyRead();

private:
    QSerialPort *m_serialPort;
};

#endif // SERIALPORT_H
