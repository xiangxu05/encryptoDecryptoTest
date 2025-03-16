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

    QPalette palette;
    QPixmap pixmap(":/icon/background.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    this->setWindowTitle("PUF设备与加解密功能测试");
    QIcon icon(":/icon/encryptoDecrypto.ico");
    this->setWindowIcon(icon);

    int totalWidth = ui->treeWidget->width();
    ui->treeWidget->setColumnWidth(0, totalWidth * 2);
    ui->treeWidget->setColumnWidth(1, totalWidth);
    ui->treeWidget->setColumnWidth(2, totalWidth);
    ui->treeWidget_2->setColumnWidth(0, totalWidth * 2);
    ui->treeWidget_2->setColumnWidth(1, totalWidth);
    ui->treeWidget_2->setColumnWidth(2, totalWidth);

    QDir().mkpath("./files/encrypto");
    QDir().mkpath("./files/decrypto");

    watcher.addPath("./files/encrypto");
    watcher.addPath("./files/decrypto");
    connect(&watcher, &QFileSystemWatcher::directoryChanged, this, &FunctionTest::onFileChanged);
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &FunctionTest::onFileChanged);

    addDirectoryContentsToTreeWidget("./files/encrypto",ui->treeWidget);
    addDirectoryContentsToTreeWidget("./files/decrypto",ui->treeWidget_2);

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
    if(ui->tabWidget->currentWidget() == ui->fileEncrypto){
        ui->textEdit_2->append("[" + getCurrentTime() + "] " + "接收：" + data);
    }else{
        ui->textEdit->append("[" + getCurrentTime() + "] " + "接收：" + data);
    }
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

void FunctionTest::onFileChanged(const QString& path){
    if(path.contains("encrypto")){
        addDirectoryContentsToTreeWidget("./files/encrypto",ui->treeWidget);
    }else{
        addDirectoryContentsToTreeWidget("./files/decrypto",ui->treeWidget_2);
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
    if(ui->tabWidget->currentWidget() == ui->fileEncrypto){
        ui->textEdit_2->append("[" + getCurrentTime() + "] " + "发送：" + data);
    }else{
        ui->textEdit->append("[" + getCurrentTime() + "] " + "发送：" + data);
    }
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

void FunctionTest::addDirectoryContentsToTreeWidget(const QString& path, QTreeWidget* treeWidget) {
    // // 获取第一个顶层项
    // QTreeWidgetItem* topLevelItem = treeWidget->topLevelItem(0);

    // // 获取第一项的文本和子项
    // QString topLevelItemText = topLevelItem->text(0);

    // 清空树形控件的所有项
    treeWidget->clear();

    // // 重新创建第一项
    // QTreeWidgetItem* newTopLevelItem = new QTreeWidgetItem(treeWidget);
    // newTopLevelItem->setText(0, topLevelItemText);  // 恢复第一项的名称

    // treeWidget->addTopLevelItem(newTopLevelItem);
    QDir dir(path);

    // 获取当前目录下的所有文件和文件夹
    QFileInfoList entries = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot, QDir::DirsFirst);

    for (const QFileInfo& entry : entries) {
        // 创建新的 QTreeWidgetItem 项
        QTreeWidgetItem* item = new QTreeWidgetItem();

        // 设置目录或文件的名称
        item->setText(0, entry.fileName());

        // 获取文件的后缀（类型）
        QString fileType = entry.suffix();
        if (fileType.isEmpty()) {
            fileType = "文件夹";  // 没有后缀的文件
        }
        item->setText(1, fileType);

        // 设置文件的大小
        if (entry.isFile()) {
            item->setText(2, QString::number(entry.size()));  // 文件大小，以字符串形式显示
        } else {
            item->setText(2, "N/A");  // 文件夹没有大小，显示 "N/A"
        }

        // 将项添加到树形控件
        treeWidget->addTopLevelItem(item);
    }
}



void FunctionTest::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if (item) {  // 确保 item 不是空指针
        QString basePath = "./files/encrypto/";
        QString itemText = item->text(0);  // 获取选中的项的文本（文件/文件夹名）
        QString fullPath = basePath + itemText;  // 构造完整路径

        QFileInfo fileInfo(fullPath);  // 获取文件/目录信息

        if (fileInfo.exists()) {  // 确保路径存在
            QString absolutePath = fileInfo.absoluteFilePath();  // 获取绝对路径
            QDesktopServices::openUrl(QUrl::fromLocalFile(absolutePath));
        }
    }
}


void FunctionTest::on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if (item) {  // 确保 item 不是空指针
        QString basePath = "./files/decrypto/";
        QString itemText = item->text(0);  // 获取选中的项的文本（文件/文件夹名）
        QString fullPath = basePath + itemText;  // 构造完整路径

        QFileInfo fileInfo(fullPath);  // 获取文件/目录信息

        if (fileInfo.exists()) {  // 确保路径存在
            QString absolutePath = fileInfo.absoluteFilePath();  // 获取绝对路径
            QDesktopServices::openUrl(QUrl::fromLocalFile(absolutePath));
        }
    }
}


void FunctionTest::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if (item) {  // 确保 item 不是空指针
        QString basePath = "./files/encrypto/";
        QString itemText = item->text(0);  // 获取选中的项的文本（文件/文件夹名）
        QString fullPath = basePath + itemText;  // 构造完整路径

        QFileInfo fileInfo(fullPath);  // 获取文件/目录信息

        if (fileInfo.exists()) {  // 确保路径存在
            if (fileInfo.isFile()) {
                QString absolutePath = fileInfo.absoluteFilePath();  // 获取绝对路径
                ui->lineEdit->setText(absolutePath);
            } else if (fileInfo.isDir()) {
                qDebug() << "选中的是目录：" << fileInfo.absoluteFilePath();
            }
        }
    }
}


void FunctionTest::on_treeWidget_2_itemClicked(QTreeWidgetItem *item, int column)
{
    if (item) {  // 确保 item 不是空指针
        QString basePath = "./files/encrypto/";
        QString itemText = item->text(0);  // 获取选中的项的文本（文件/文件夹名）
        QString fullPath = basePath + itemText;  // 构造完整路径

        QFileInfo fileInfo(fullPath);  // 获取文件/目录信息

        if (fileInfo.exists()) {  // 确保路径存在
            if (fileInfo.isFile()) {
                QString absolutePath = fileInfo.absoluteFilePath();  // 获取绝对路径
                ui->lineEdit->setText(absolutePath);
            } else if (fileInfo.isDir()) {
                qDebug() << "选中的是目录：" << fileInfo.absoluteFilePath();
            }
        }
    }
}

