#ifndef PEDIDO_H
#define PEDIDO_H
#include <QString>
#include <QDebug>
#include "factura.h"

// Prototipos de estructuras
struct NodoLSP;
struct LSPedido;
struct Pedido;

struct Pedido
{
    LSPedido *listaPedido;
    int numeroPedido = 0;
    int codigoCliente = 0;
    Factura *infoFactura;

public:
    Pedido();
    void imprimir();
};

struct LSPedido{

public:
    //Atributos
    NodoLSP *primerNodo = nullptr;

    //Metodos
    LSPedido();
    int largoLista();
    bool insertarAlInicio(QString, int);
    bool isInList(QString);
    void imprimir();
};



/*
Estrcutrua nodo de lista simple que guarda
la informacion de un cliente
*/
struct NodoLSP{

public:
    //Atributos
    NodoLSP *siguiente = nullptr;
    QString codigo = "";
    int cantidad = 0;
    bool completado = false;
    int cantFaltante = 0;

    //Metodos
    NodoLSP(QString, int);
    void imprimir();

};

#endif // PEDIDO_H
