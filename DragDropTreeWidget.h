#ifndef DRAGDROPTREEWIDGET_H
#define DRAGDROPTREEWIDGET_H
#include <QApplication>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>

class DragDropTreeWidget : public QTreeWidget {
public:
    DragDropTreeWidget(QWidget *parent = nullptr){};
protected:
    void dragEnterEvent(QDragEnterEvent *event) override {
        if (event->mimeData()->hasUrls()) {
            event->acceptProposedAction();
        }
    }

    void dragMoveEvent(QDragMoveEvent *event) override {
        if (event->mimeData()->hasUrls()) {
            event->acceptProposedAction();
        }
    }

    void dropEvent(QDropEvent *event) override {
        if (event->mimeData()->hasUrls()) {
            QList<QUrl> urls = event->mimeData()->urls();
            for (const QUrl &url : urls) {
                QString filePath = url.toLocalFile();
                // if (!filePath.isEmpty()) {
                //     QTreeWidgetItem *item = new QTreeWidgetItem(this);
                //     item->setText(0, filePath);
                // }
                qDebug() << filePath;
            }
            event->acceptProposedAction();
        }
    }
};


#endif // DRAGDROPTREEWIDGET_H
