#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H

#include <QApplication>
#include <QTabWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

class MyTabWidget : public QTabWidget {
    Q_OBJECT
public:
    MyTabWidget(QWidget *parent = nullptr) : QTabWidget(parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) override {
        QPoint pos = event->pos();  // 获取鼠标点击的位置
        if(pos.x() >355 && pos.x() < 755 && pos.y() > 0 && pos.y() < 40){
            qDebug() << "Mouse clicked at position:" << pos;
            QDesktopServices::openUrl(QUrl("https://blog.xxsay.online/"));
        }
        QTabWidget::mousePressEvent(event);  // 保持原有行为
    }
};

#endif // MYTABWIDGET_H
