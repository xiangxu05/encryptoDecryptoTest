#ifndef PORTSCANNERCOMBOBOX_H
#define PORTSCANNERCOMBOBOX_H

#include <QComboBox>
#include <QMouseEvent>

class PortScannerComboBox : public QComboBox {
    Q_OBJECT

public:
    PortScannerComboBox(QWidget *parent = nullptr) : QComboBox(parent) {}

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) {
        if (event->button() == Qt::LeftButton) {
            emit clicked();
        }
        QComboBox::mousePressEvent(event);
    }
};


#endif // PORTSCANNERCOMBOBOX_H
