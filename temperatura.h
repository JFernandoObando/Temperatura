#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Temperatura; }
QT_END_NAMESPACE

class Temperatura : public QDialog
{
    Q_OBJECT

public:
    Temperatura(QWidget *parent = nullptr);
    ~Temperatura();
public slots:
    void centToFahr(int);  //cent2Fahr ; centigrados a fahrenhei
    void fahtToCent(int);  // De Faharenhei a Centigrados
    void kelvToCent(int);  // De Kelvin a Centigrados
    void cambiarMouse() ;


private:
    Ui::Temperatura *ui;
};
#endif // TEMPERATURA_H
