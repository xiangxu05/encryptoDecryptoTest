#include "functiontest.h"
#include "./ui_functiontest.h"
#include "portScannerComboBox.h"

#include <string>
#include <QListWidget>
#include <QFrame>
#include <QStringList>
#include <QPainterPath>
#include <QDebug>

using namespace std;

FunctionTest::FunctionTest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FunctionTest)
{
    ui->setupUi(this);
    this->setWindowTitle("PUF设备与加解密功能测试");

    connect(ui->portBox,&PortScannerComboBox::clicked,this,&FunctionTest::on_portBox_clicked);
}

FunctionTest::~FunctionTest()
{
    delete ui;
}

void FunctionTest::on_pushButton_clicked()
{
    qDebug() << "11";
}

void FunctionTest::on_portBox_clicked()
{
    qDebug() << "11";
}

