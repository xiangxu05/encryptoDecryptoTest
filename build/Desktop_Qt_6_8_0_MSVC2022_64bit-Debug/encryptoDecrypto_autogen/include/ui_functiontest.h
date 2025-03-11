/********************************************************************************
** Form generated from reading UI file 'functiontest.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONTEST_H
#define UI_FUNCTIONTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "portscannercombobox.h"

QT_BEGIN_NAMESPACE

class Ui_FunctionTest
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *functionTestTab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    PortScannerComboBox *portBox;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit;
    QWidget *fileEncrypto;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QWidget *FunctionTest)
    {
        if (FunctionTest->objectName().isEmpty())
            FunctionTest->setObjectName("FunctionTest");
        FunctionTest->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FunctionTest->sizePolicy().hasHeightForWidth());
        FunctionTest->setSizePolicy(sizePolicy);
        FunctionTest->setMinimumSize(QSize(800, 600));
        FunctionTest->setMaximumSize(QSize(800, 600));
        FunctionTest->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(FunctionTest);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(FunctionTest);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256 QWidget \347\232\204\345\205\250\345\261\200\346\240\267\345\274\217 */\n"
"QWidget {\n"
"    background-color: transparent;\n"
"    color: #333333;\n"
"    font-family: \"Microsoft YaHei\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QGroupBox \346\240\267\345\274\217 */\n"
"QGroupBox {\n"
"    background: transparent;\n"
"    color: #333333;\n"
"    font-size: 14px;\n"
"    border: 1px solid #D0D0D0;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    margin-top: 20px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 10px;\n"
"    background: transparent;\n"
"    color: #333333;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QPushButton \346\240\267\345\274\217 */\n"
"QPushButton {\n"
"    background: #F5F5F5;\n"
"    color: #333333;\n"
"    border: 1px solid #D0D0D0;\n"
"    border-r"
                        "adius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: 400;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background: #D0D0D0;\n"
"    color: #000000;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-bottom: 3px solid #0088FF;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #C0C0C0;\n"
"    color: #000000;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QComboBox \346\240\267\345\274\217 */\n"
"QComboBox {\n"
"    background: #FFFFFF;\n"
"    color: #333333;\n"
"    border: 1px solid #D0D0D0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: #FFFFFF;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #0088FF;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: #FFFFFF;\n"
"    color: #1E1E1E;\n"
"    border: 1px solid #D0D0D0;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QTabWidget \346\240\267\345"
                        "\274\217 */\n"
"QTabWidget {\n"
"    background: transparent;\n"
"    color: #1E1E1E;\n"
"    font-size: 14px;\n"
"    border-radius: 8px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QTabWidget \351\235\242\346\235\277\346\240\267\345\274\217 */\n"
"QTabWidget::pane {\n"
"    border: none;\n"
"    background: #F5F5F5;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QTabBar \346\240\267\345\274\217 */\n"
"QTabBar::tab {\n"
"    background: transparent;\n"
"    color: #333333;\n"
"    padding: 12px 20px;\n"
"    margin: 3px;\n"
"    border-radius: 6px;\n"
"    border: none;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #D0D0D0;\n"
"    color: #000000;\n"
"    font-weight: bold;\n"
"    border-bottom: 3px solid #0088FF;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #C0C0C0;\n"
"    color: #000000;\n"
"    border: none;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: left;\n"
"}"));
        functionTestTab = new QWidget();
        functionTestTab->setObjectName("functionTestTab");
        functionTestTab->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(functionTestTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        groupBox = new QGroupBox(functionTestTab);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        portBox = new PortScannerComboBox(groupBox);
        portBox->addItem(QString());
        portBox->addItem(QString());
        portBox->setObjectName("portBox");
        portBox->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(portBox);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setMinimumSize(QSize(0, 0));
        comboBox_2->setEditable(false);

        horizontalLayout_4->addWidget(comboBox_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(label_3, 0, Qt::AlignmentFlag::AlignHCenter);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(comboBox_3);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(label_4, 0, Qt::AlignmentFlag::AlignHCenter);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setMinimumSize(QSize(0, 0));

        horizontalLayout_6->addWidget(comboBox_4);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(label_5, 0, Qt::AlignmentFlag::AlignHCenter);

        comboBox_5 = new QComboBox(groupBox);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setMinimumSize(QSize(0, 0));

        horizontalLayout_7->addWidget(comboBox_5);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(24, 24));
        label_6->setMaximumSize(QSize(24, 24));
        label_6->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius:12px;"));

        horizontalLayout_8->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(pushButton);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 2);
        horizontalLayout_8->setStretch(2, 1);
        horizontalLayout_8->setStretch(3, 10);

        verticalLayout->addLayout(horizontalLayout_8);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 2);
        verticalLayout->setStretch(6, 1);
        verticalLayout->setStretch(7, 2);
        verticalLayout->setStretch(8, 1);
        verticalLayout->setStretch(9, 2);
        verticalLayout->setStretch(10, 1);
        verticalLayout->setStretch(11, 10);

        horizontalLayout_9->addWidget(groupBox);

        groupBox_2 = new QGroupBox(functionTestTab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_10 = new QHBoxLayout(groupBox_2);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");

        verticalLayout_4->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout_4->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName("checkBox_3");

        verticalLayout_4->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName("checkBox_4");

        verticalLayout_4->addWidget(checkBox_4);


        horizontalLayout_10->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName("checkBox_8");

        verticalLayout_5->addWidget(checkBox_8);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName("checkBox_5");

        verticalLayout_5->addWidget(checkBox_5);

        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName("checkBox_7");

        verticalLayout_5->addWidget(checkBox_7);

        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName("checkBox_6");

        verticalLayout_5->addWidget(checkBox_6);


        horizontalLayout_10->addLayout(verticalLayout_5);


        horizontalLayout_9->addWidget(groupBox_2);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_9);

        groupBox_3 = new QGroupBox(functionTestTab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName("textEdit");
        textEdit->setReadOnly(true);

        verticalLayout_3->addWidget(textEdit);


        verticalLayout_2->addWidget(groupBox_3);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 2);
        tabWidget->addTab(functionTestTab, QString());
        fileEncrypto = new QWidget();
        fileEncrypto->setObjectName("fileEncrypto");
        fileEncrypto->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(fileEncrypto);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        tabWidget->addTab(fileEncrypto, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(FunctionTest);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FunctionTest);
    } // setupUi

    void retranslateUi(QWidget *FunctionTest)
    {
        FunctionTest->setWindowTitle(QCoreApplication::translate("FunctionTest", "FunctionTest", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FunctionTest", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("FunctionTest", "\344\270\262\345\217\243\345\217\267", nullptr));
        portBox->setItemText(0, QCoreApplication::translate("FunctionTest", "COM1", nullptr));
        portBox->setItemText(1, QCoreApplication::translate("FunctionTest", "COM2", nullptr));

        label_2->setText(QCoreApplication::translate("FunctionTest", "\346\263\242\347\211\271\347\216\207", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("FunctionTest", "115200", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("FunctionTest", "110", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("FunctionTest", "300", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("FunctionTest", "600", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("FunctionTest", "1200", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("FunctionTest", "2400", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("FunctionTest", "4800", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("FunctionTest", "9600", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("FunctionTest", "14400", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("FunctionTest", "19200", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("FunctionTest", "38400", nullptr));
        comboBox_2->setItemText(11, QCoreApplication::translate("FunctionTest", "56000", nullptr));
        comboBox_2->setItemText(12, QCoreApplication::translate("FunctionTest", "57600", nullptr));
        comboBox_2->setItemText(13, QCoreApplication::translate("FunctionTest", "128000", nullptr));
        comboBox_2->setItemText(14, QCoreApplication::translate("FunctionTest", "256000", nullptr));

        label_3->setText(QCoreApplication::translate("FunctionTest", "\346\240\241\351\252\214\344\275\215", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("FunctionTest", "NONE", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("FunctionTest", "ODD", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("FunctionTest", "EVEN", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("FunctionTest", "MARK", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("FunctionTest", "SPACE", nullptr));

        label_4->setText(QCoreApplication::translate("FunctionTest", "\346\225\260\346\215\256\344\275\215", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("FunctionTest", "8 bit", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("FunctionTest", "7 bit", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("FunctionTest", "6 bit", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("FunctionTest", "5 bit", nullptr));

        label_5->setText(QCoreApplication::translate("FunctionTest", "\345\201\234\346\255\242\344\275\215", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("FunctionTest", "1 bit", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("FunctionTest", "1.5 bit", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("FunctionTest", "2 bit", nullptr));

        label_6->setText(QString());
        pushButton->setText(QCoreApplication::translate("FunctionTest", "\346\211\223\345\274\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FunctionTest", "\345\212\237\350\203\275\346\265\213\350\257\225", nullptr));
        checkBox->setText(QCoreApplication::translate("FunctionTest", "AT_default \351\273\230\350\256\244\345\233\236\344\274\240\346\250\241\345\274\217", nullptr));
        checkBox_2->setText(QCoreApplication::translate("FunctionTest", "AT_init \345\210\235\345\247\213\345\214\226PUF", nullptr));
        checkBox_3->setText(QCoreApplication::translate("FunctionTest", "AT_source \346\237\245\347\234\213helpdata\345\200\274", nullptr));
        checkBox_4->setText(QCoreApplication::translate("FunctionTest", "AT_strongSRAM \345\274\272PUF\346\250\241\345\274\217", nullptr));
        checkBox_8->setText(QCoreApplication::translate("FunctionTest", "AT_sourceSRAM SRAM\346\272\220\345\200\274", nullptr));
        checkBox_5->setText(QCoreApplication::translate("FunctionTest", "AT_delay \346\227\266\345\273\266\346\265\213\350\257\225\346\250\241\345\274\217", nullptr));
        checkBox_7->setText(QCoreApplication::translate("FunctionTest", "AT_File \347\224\250\346\210\267\346\226\207\344\273\266\346\240\207\347\255\276\347\256\241\347\220\206\346\250\241\345\274\217", nullptr));
        checkBox_6->setText(QCoreApplication::translate("FunctionTest", "AT_Statu \350\256\276\345\244\207\347\212\266\346\200\201\346\237\245\350\257\242", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FunctionTest", "\346\225\260\346\215\256\346\230\276\347\244\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(functionTestTab), QCoreApplication::translate("FunctionTest", "\345\212\237\350\203\275\346\265\213\350\257\225\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(fileEncrypto), QCoreApplication::translate("FunctionTest", "\346\226\207\344\273\266\345\212\240\350\247\243\345\257\206\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FunctionTest: public Ui_FunctionTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONTEST_H
