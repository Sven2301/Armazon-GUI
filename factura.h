#ifndef FACTURA_H
#define FACTURA_H

#include <QString>

struct Factura;

struct Factura
{
public:
    //Atributos
    QString numeroPedido;
    QString codigoCliente;
    QString horaLoader;
    QString horaBalancer;
    QString horaAlisto;
    QString horaEmpaque;
    QString horaFacturacion;
    QString numeroAlistador;
    QString codigoArticulo;
    QString ubicacionArticulo;
    QString duracionAlistador;


public:
    //Metodos
    Factura();
};

#endif // FACTURA_H
