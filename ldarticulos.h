#ifndef LDARTICULOS_H
#define LDARTICULOS_H
#include <QString>
#include <QDebug>

// Prototipos de estructuras
struct NodoLDA;
struct LDArticulos;

/*
Estructura lista doblemente enlazada
guarda la informacion de
cada articulo en cada
uno de sus nodos
*/
struct LDArticulos{

public:
    //Atributos
    NodoLDA *primerNodo;
    NodoLDA *ultimoNodo;

    //Metodos
    LDArticulos();
    int largoLista();
    bool insertarAlInicio(QString, QString, QString, int, int, int, int);
    bool isInList(QString);
    void imprimir();
};



/*
Estructura nodo de lista doblemente enlazada que guarda
la informacion de un articulo
*/
struct NodoLDA{

public:
    //Atributos
    NodoLDA *siguiente = nullptr;
    NodoLDA *anterior = nullptr;
    QString strCodigo = "";
    QString strCategoria = "";
    QString strUbicacion = "";
    int tiempoFabricacion = 0;
    int cantidad = 0;
    int fila = 0;
    int columna = 0;

    //Metodos
    NodoLDA(QString, QString, QString, int, int, int, int);
    void imprimir();

};

#endif // LDARTICULOS_H
