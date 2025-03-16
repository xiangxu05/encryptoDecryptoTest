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
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QFileSystemWatcher>
#include <QTreeWidget>
#include <QPainter>
#include <QPixmap>

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
    void serialDateReceived(const QString& data);
    void judgeReceived(const QString& data);
    void onFileChanged(const QString& path);
private slots:
    void on_connectButton_clicked();

    void on_defaltCheckBox_clicked();

    void on_initCheckBox_clicked();

    void on_sourceCheckBox_clicked();

    void on_strongCheckBox_clicked();

    void on_SRAMCheckBox_clicked();

    void on_delayCheckBox_clicked();

    void on_fileCheckBox_clicked();

    void on_statuCheckBox_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column);
private:
    Ui::FunctionTest *ui;
    std::unique_ptr<SerialPort> serialPort_;
    QFileSystemWatcher watcher;
    void writeToSerial(const QByteArray& data);
    void addDirectoryContentsToTreeWidget(const QString& path, QTreeWidget* treeWidget);
};
#endif // FUNCTIONTEST_H
