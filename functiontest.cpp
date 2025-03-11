#include "functiontest.h"
#include "./ui_functiontest.h"

using namespace std;

FunctionTest::FunctionTest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FunctionTest)
{
    ui->setupUi(this);
    this->setWindowTitle("PUF设备与加解密功能测试");
    QIcon icon(":/icon/encryptoDecrypto.ico");
    this->setWindowIcon(icon);
    serialPort_ = std::make_unique<SerialPort>();

    connect(ui->portBox,&PortScannerComboBox::clicked,this,&FunctionTest::on_portBox_clicked);
}

FunctionTest::~FunctionTest()
{
    delete ui;
}

void FunctionTest::on_portBox_clicked()
{
    QStringList ports = SerialPort::availablePorts();
    QStringList oldPorts;
    for(int i = 0; i < ui->portBox->count(); i++){
        oldPorts << ui->portBox->itemText(i);
    }

    if(!ports.empty() && ports != oldPorts){
        ui->portBox->clear();
        ui->portBox->addItems(ports);
    }
}

void FunctionTest::on_connectButton_clicked()
{
    QString greenSheet = "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5,"
                         " radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                         " border-radius: 12px;";
    QString redSheet = "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5,"
                       " radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                       " border-radius: 12px;";

    if(ui->connectButton->text() == "打开"){
        QString com = ui->portBox->currentText();
        int baudRate = ui->baudRateBox->currentText().toInt();
        QString parity = ui->parityBox->currentText();
        QString dataBits = ui->dataBitsBox->currentText();
        QString stopBits = ui->stopBitsBox->currentText();

        if(this->serialPort_->open(com,baudRate,parity,dataBits,stopBits)){
            ui->statusLabel->setStyleSheet(greenSheet);
            ui->connectButton->setText("关闭");
        }else{
            QMessageBox::warning(nullptr, "串口打开失败", "无法打开串口!");
        }
    }else{
        this->serialPort_->close();
        ui->statusLabel->setStyleSheet(redSheet);
        ui->connectButton->setText("打开");
    }
}


void FunctionTest::on_checkBox_clicked()
{
    // connect(serialPort_.get(),&SerialPort::dataReceived,this,[this](const QByteArray &data){
    //     qDebug() << "Data received:" << data;
    // }, Qt::UniqueConnection); //[todo] uniqueConnection不能和lambda表达式一起用

    // 1、连接到信号接收并输出到textEdit
    // 2、给serialPort类增加一个标记，每回都更新，然后新建一个方法，在接收到的时候，判断对应的类，在达成条件时更改复选框。
    QByteArray testData = "AT_default";
    serialPort_->writeData(testData);  //封装一个方法，先输出到txtEdit，然后再write
}

