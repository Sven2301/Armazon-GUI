#ifndef FACTURA_H
#define FACTURA_H

#include <QString>
#include <QDebug>

struct NodoInfo;
struct LSInfo;
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
    QString duracionAlistador;
    LSInfo *infoArticulos;

    Factura();

};

struct LSInfo{

public:
    //Atributos
    NodoInfo *primerNodo = nullptr, *ultimoNodo = nullptr;

    //Metodos
    LSInfo();
    int largoLista();
    NodoInfo *find(QString);
    bool insertarAlInicio(QString, QString, QString);
    bool isInList(QString);
    void imprimir();
};



/*
Estrcutrua nodo de lista simple que guarda
la informacion de un cliente
*/
struct NodoInfo{

public:
    //Atributos
    NodoInfo *siguiente = nullptr;
    QString codigo;
    QString ubicacion;
    QString duracion;

    //Metodos
    NodoInfo(QString, QString, QString);
    void imprimir();

};

#endif // FACTURA_H
