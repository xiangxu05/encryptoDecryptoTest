#ifndef FUNCTIONTEST_H
#define FUNCTIONTEST_H

#include <QWidget>
#include <QListWidget>
#include <QFrame>
#include <QStringList>
#include <QPainterPath>
#include <QDebug>
#include <QThread>
#include <QIcon>
#include <QMessageBox>

#include "portScannerComboBox.h"
#include "serialPort.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class FunctionTest;
}
QT_END_NAMESPACE

class FunctionTest : public QWidget
{
    Q_OBJECT

public:
    FunctionTest(QWidget *parent = nullptr);
    ~FunctionTest();

public slots :
    void on_portBox_clicked();

private slots:
    void on_connectButton_clicked();

    void on_checkBox_clicked();

private:
    Ui::FunctionTest *ui;
    std::unique_ptr<SerialPort> serialPort_;
};
#endif // FUNCTIONTEST_H
