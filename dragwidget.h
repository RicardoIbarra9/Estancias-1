#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>

class QDragEnterEvent;
class QDropEvent;
class QSerialPort;

class DragWidget : public QFrame
{
   public:
    DragWidget(QWidget * parent= nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent * event);
    void dragMoveEvent(QDragMoveEvent * event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
};

#endif // DRAGWIDGET_H
