#include "functiontest.h"
#include "./ui_functiontest.h"

using namespace std;

QString getCurrentTime() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    return currentDateTime.toString("yyyy-MM-dd HH:mm:ss.zzz");
}

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
    connect(serialPort_.get(),&SerialPort::dataReceived,this,&FunctionTest::serialDateReceived);
    connect(serialPort_.get(),&SerialPort::dataReceived,this,&FunctionTest::judgeReceived);
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

void FunctionTest::serialDateReceived(const QString& data){
    ui->textEdit->append("[" + getCurrentTime() + "] " + "接收：" +data);
}

void FunctionTest::judgeReceived(const QString& data){
    if(ui->textEdit->toPlainText().contains("test end")){
        ui->defaltCheckBox->setChecked(true);
    }else if(ui->textEdit->toPlainText().contains("Successful store helpData")){
        ui->initCheckBox->setChecked(true);
    }else if(ui->textEdit->toPlainText().contains("查看helpdata值")){
        ui->sourceCheckBox->setChecked(true);
    }else if(ui->textEdit->toPlainText().contains("strong end")){
        ui->strongCheckBox->setChecked(true);
    }else if(ui->textEdit->toPlainText().contains("获取SRAM单元位置上的原始值")){
        ui->SRAMCheckBox->setChecked(true);
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

void FunctionTest::writeToSerial(const QByteArray& data)
{
    ui->textEdit->append("[" + getCurrentTime() + "] " + "发送：" + data);
    serialPort_->writeData(data);
}

void FunctionTest::on_defaltCheckBox_clicked()
{
    ui->defaltCheckBox->setChecked(false);
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    timer.setInterval(500);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    ui->textEdit->clear();
    // 1、连接到信号接收并输出到textEdit
    // 2、给serialPort类增加一个标记，每回都更新，然后新建一个方法，在接收到的时候，判断对应的类，在达成条件时更改复选框。
    QByteArray testData = "AT_default";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "test1";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "test2";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "test end";
    writeToSerial(testData);
}


void FunctionTest::on_initCheckBox_clicked()
{
    ui->initCheckBox->setChecked(false);
    ui->textEdit->clear();
    QByteArray testData = "AT_init";
    writeToSerial(testData);
}


void FunctionTest::on_sourceCheckBox_clicked()
{
    ui->sourceCheckBox->setChecked(false);
    ui->textEdit->clear();
    QByteArray testData = "AT_source";
    writeToSerial(testData);
}


void FunctionTest::on_strongCheckBox_clicked()
{
    ui->strongCheckBox->setChecked(false);
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    timer.setInterval(500);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    ui->textEdit->clear();

    QByteArray testData = "AT_strongSram";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "test1";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "test2";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "strong end";
    writeToSerial(testData);
}


void FunctionTest::on_SRAMCheckBox_clicked()
{
    ui->SRAMCheckBox->setChecked(false);
    ui->textEdit->clear();
    QByteArray testData = "AT_sourceSram";
    writeToSerial(testData);
}


void FunctionTest::on_delayCheckBox_clicked()
{
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    timer.setInterval(500);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    ui->textEdit->clear();

    QByteArray testData = "AT_delay";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "10";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "20";
    writeToSerial(testData);
    timer.start();
    loop.exec();

    testData = "delay end";
    writeToSerial(testData);
}


void FunctionTest::on_fileCheckBox_clicked()
{
    ui->textEdit->clear();
    QByteArray testData = "AT_File";
    writeToSerial(testData);
}


void FunctionTest::on_statuCheckBox_clicked()
{
    ui->textEdit->clear();
    QByteArray testData = "AT_Statu";
    writeToSerial(testData);
}

