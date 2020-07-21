/*
Curso:Programacion Orientada a Objetos
Nombre: Juan Fernando Obando Castillo       <jobandoc3@est.ups.edu.ec>
Fecha:29-06-2020
Practica Temperatura
*/
#include "temperatura.h"
#include "ui_temperatura.h"
#include <QDebug>
#include <QMouseEvent>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    //Conectar para transformar de centigrados a Fahrenheit y Kelvin
    connect(ui->dialCent,SIGNAL(valueChanged(int)),
            this,SLOT(centToFahr(int)));
    //Conectar para transformar de Fahrenheit a centigrados y Kelvin
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this,SLOT(fahtToCent(int)));
    //Conectar para transformar de Kelvin a centigrados y Fahrenheit
    connect(ui->dialKelvin,SIGNAL(valueChanged(int)),
            this,SLOT(kelvToCent(int)));
    //Conectar para cambiar cuando presione el mouse en el dial Cent
    connect(ui->dialCent,SIGNAL(sliderPressed()),
            this,SLOT(cambiarMouse()));
    //Conectar para cambiar cuando deje de presionar
    //el mouse en el dial Cent
    connect(ui->dialCent,SIGNAL(sliderReleased()),
            this,SLOT(cambiarMouse()));
    //Conectar para cambiar cuando presione el mouse en el dial Fahr
    connect(ui->dialFahr,SIGNAL(sliderPressed()),
            this,SLOT(cambiarMouse()));
    //Conectar para cambiar cuando deje de presionar
    //el mouse en el dial Fahr
    connect(ui->dialFahr,SIGNAL(sliderReleased()),
            this,SLOT(cambiarMouse()));
    //Conectar para cambiar cuando presione el mouse en el dial Kelvin
    connect(ui->dialKelvin,SIGNAL(sliderPressed()),
            this,SLOT(cambiarMouse()));
    //Conectar para cambiar cuando deje de presionar
    //el mouse en el dial Kelvin
    connect(ui->dialKelvin,SIGNAL(sliderReleased()),
            this,SLOT(cambiarMouse()));
    //Establecer valores de inicio  en los dial y los label
    //Por defecto todos los valores cuando cent valga 0°
    ui->dialFahr->setValue(32);
    ui->dialKelvin->setValue(273);
    ui->lblCentigrados->setText("0\n°C");
    ui->lblFahr->setText("32\n°F");
    ui->lblKelvin->setText("273.15 \n°K");
}

Temperatura::~Temperatura()
{
    delete ui;
}
//Slot de centigrados a Fahr y Kelvin
void Temperatura::centToFahr(int valor)
{
    if(ui->dialCent->hasFocus()){
        double f=valor*9.0/5 +32;
        double kel=valor+273.15;
        QString fahr=QString::number(f); //Convertir el Double a Qstring
        QString kelvin=QString::number(kel);
        QString cent=QString::number(valor);
        ui->dialFahr->setValue(f);
        ui->dialKelvin->setValue(kel);
        ui->lblFahr->setText(fahr+"\n°F");
        ui->lblKelvin->setText(kelvin+ "\n°K");
        ui->lblCentigrados->setText(cent+"\n°C");
    }
}

//Slot de Fahr a Centigrados y Kelvin
void Temperatura::fahtToCent(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float c=(valor-32)*5.0/9;
        float k=(valor-32)*5.0/9+(273.15);
        QString fahr=QString::number(valor); //Convertir el Double a Qstring
        QString kelvin=QString::number(k);
        QString cent=QString::number(c);
        ui->dialCent->setValue(c);
        ui->dialKelvin->setValue(k);
        ui->lblFahr->setText(fahr+"\n°F"); //Utilizo el double transformado a QString
        ui->lblKelvin->setText(kelvin+ "\n°K");
        ui->lblCentigrados->setText(cent+"\n°C");

    }
}

//Slot de Kelvin a Centigrados y Fahr
void Temperatura::kelvToCent(int valor)
{
    if(ui->dialKelvin->hasFocus()){
        float c = (valor - 273.15);
        float f =(valor-273.15)*9.0/5+32;
        QString fahr=QString::number(f); //Convertir el Double a Qstring
        QString kelvin=QString::number(valor);
        QString cent=QString::number(c);
        ui->dialCent->setValue(c);
        ui->dialFahr->setValue(f);
        ui->lblFahr->setText(fahr+"\n°F");
        ui->lblKelvin->setText(kelvin+ "\n°K");
        ui->lblCentigrados->setText(cent+"\n°C");
    }
}

//Slot para Cambiar el cursor cuando presione el mouse
void Temperatura::cambiarMouse()
{
    if(ui->dialCent->hasFocus()){
        if(ui->dialCent->cursor()==Qt::OpenHandCursor){
            ui->dialCent->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialCent->setCursor(Qt::OpenHandCursor);
        }
    }
    if(ui->dialFahr->hasFocus()){
        if(ui->dialFahr->cursor()==Qt::OpenHandCursor){
            ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialFahr->setCursor(Qt::OpenHandCursor);
        }
    }
    if(ui->dialKelvin->hasFocus()){
        if(ui->dialKelvin->cursor()==Qt::OpenHandCursor){
            ui->dialKelvin->setCursor(Qt::ClosedHandCursor);
        }
    }else{
        ui->dialKelvin->setCursor(Qt::OpenHandCursor);
    }
}





