#ifndef DELTREEWIDGET_H
#define DELTREEWIDGET_H

#include <QTreeWidget>
#include <QKeyEvent>
#include <QTreeWidgetItem>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

class delTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    delTreeWidget(QWidget *parent = nullptr) : QTreeWidget(parent)
    {
        // 设置焦点策略，确保控件可以接收键盘事件
        setFocusPolicy(Qt::StrongFocus);
    }

protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        if (event->key() == Qt::Key_Delete) // 检查是否是Del键
        {
            QTreeWidgetItem *currentItem = this->currentItem();
            if (currentItem)
            {
                QString basePath;
                if(this->headerItem()->text(0) == "未加密文件"){
                    basePath = "./files/encrypto/";
                }else{
                    basePath = "./files/decrypto/";
                }
                QString itemText = currentItem->text(0);  // 获取选中的项的文本（文件/文件夹名）
                QString fullPath = basePath + itemText;  // 构造完整路径

                QFileInfo fileInfo(fullPath);  // 获取文件/目录信息
                qDebug() << fullPath;
                if (fileInfo.exists()) {  // 确保路径存在
                    QString absolutePath = fileInfo.absoluteFilePath();  // 获取绝对路径
                    if (fileInfo.isDir()) {  // 如果是文件夹
                        QDir dir(absolutePath);
                        if (dir.removeRecursively()) {  // 递归删除文件夹
                            qDebug() << "Deleted directory:" << absolutePath;
                            delete currentItem;  // 删除树中的项
                        } else {
                            qDebug() << "Failed to delete directory:" << absolutePath;
                        }
                    } else {  // 如果是文件
                        QFile file(absolutePath);
                        if (file.remove()) {  // 删除文件
                            qDebug() << "Deleted file:" << absolutePath;
                            delete currentItem;  // 删除树中的项
                        } else {
                            qDebug() << "Failed to delete file:" << absolutePath;
                        }
                    }
                }else{
                    qDebug() << "FileInfo not exists!";
                }
            }
        } else {
            // 调用基类的keyPressEvent处理其他按键
            QTreeWidget::keyPressEvent(event);
        }
    }
};

#endif // DELTREEWIDGET_H
