#ifndef FUNCTIONTEST_H
#define FUNCTIONTEST_H

#include <QWidget>

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
    void on_pushButton_clicked();

private:
    Ui::FunctionTest *ui;
};
#endif // FUNCTIONTEST_H
