/*
Curso:Programacion Orientada a Objetos
Nombre: Juan Fernando Obando Castillo       <jobandoc3@est.ups.edu.ec>
Fecha:29-06-2020
Practica Temperatura
*/
#include "temperatura.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Temperatura w;
    w.show();
    return a.exec();
}
