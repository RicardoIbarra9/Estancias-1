#include "ccarro.h"
#include "ui_ccarro.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>



CCarro::CCarro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CCarro)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "COM11";
    arduino = new QSerialPort;

    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    arduino->setPortName(arduino_port_name);
    arduino->open(QSerialPort::WriteOnly);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);
}

CCarro::~CCarro()
{
    delete ui;
}


void CCarro::on_Adelante_clicked()
{
    if(arduino->isWritable()){
        arduino->write("F");

    }else{
        qDebug() << "Couldn't write to serial!";
    }
}

void CCarro::on_Atras_clicked()
{
    if(arduino->isWritable()){
        arduino->write("B");
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}

void CCarro::on_Derecha_clicked()
{
    if(arduino->isWritable()){
         arduino->write("R");
     }else{
         qDebug() << "Couldn't write to serial!";
     }
}

void CCarro::on_Izquierda_clicked()
{
    if(arduino->isWritable()){
        arduino->write("L");
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}

void CCarro::on_pushButton_clicked()
{
    if(arduino->isWritable()){
         arduino->write("S");
     }else{
         qDebug() << "Couldn't write to serial!";
     }
}
