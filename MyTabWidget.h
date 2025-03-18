#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H

#include <QApplication>
#include <QTabWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QMimeData>
#include <QFile>
#include <QDir>
#include <QMessageBox>

class MyTabWidget : public QTabWidget {
    Q_OBJECT
public:
    MyTabWidget(QWidget *parent = nullptr) : QTabWidget(parent) {
        this->setAcceptDrops(true);
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        QPoint pos = event->pos();  // 获取鼠标点击的位置
        if(pos.x() >355 && pos.x() < 755 && pos.y() > 0 && pos.y() < 40){
            qDebug() << "Mouse clicked at position:" << pos;
            QDesktopServices::openUrl(QUrl("https://blog.xxsay.online/"));
        }
        QTabWidget::mousePressEvent(event);  // 保持原有行为
    }

    void dragEnterEvent(QDragEnterEvent *event) override{
        if (event->mimeData()->hasFormat("text/uri-list")) {
            event->acceptProposedAction();
        }
    };
    void dragMoveEvent(QDragMoveEvent *event) override{
        if (event->mimeData()->hasUrls()) {
            event->acceptProposedAction();
        }
    };
    void dropEvent(QDropEvent *event) override{
        QList<QUrl> urls = event->mimeData()->urls();
        if (urls.empty())
            return;

        QString fileName = urls.first().toLocalFile();
        if (fileName.isEmpty())
            return;

        // 获取当前目录下的 files/encrypto 文件夹路径
        QDir targetDir(QDir::currentPath() + "/files/encrypto");

        // 如果目标文件夹不存在，则创建它
        if (!targetDir.exists()) {
            if (!targetDir.mkpath(".")) {
                qDebug() << "Failed to create target directory:" << targetDir.path();
                return;
            }
        }

        // 获取文件名
        QFileInfo fileInfo(fileName);
        QString targetFilePath = targetDir.filePath(fileInfo.fileName());

        // 复制文件到目标文件夹
        if (QFile::copy(fileName, targetFilePath)) {
            qDebug() << "File copied to:" << targetFilePath;
        } else {
            qDebug() << "Failed to copy file:" << fileName;
            // 可选：显示错误消息
            QMessageBox::warning(this, "复制文件失败", "无法复制文件：" + fileName);
        }

        event->acceptProposedAction();
    };
};

#endif // MYTABWIDGET_H
