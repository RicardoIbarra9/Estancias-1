#ifndef CCARRO_H
#define CCARRO_H

#include <QMainWindow>

namespace Ui {
class CCarro;
}

class QSerialPort;

class CCarro : public QMainWindow
{
    Q_OBJECT

public:
    explicit CCarro(QWidget *parent = nullptr);
    ~CCarro();

private slots:
    void on_Adelante_clicked();

    void on_Atras_clicked();

    void on_Derecha_clicked();

    void on_Izquierda_clicked();

    void on_pushButton_clicked();

private:
    Ui::CCarro *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
};

#endif // CCARRO_H
