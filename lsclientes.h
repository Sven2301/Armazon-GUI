#ifndef LSCLIENTES_H
#define LSCLIENTES_H
#include <QString>
#include <QDebug>

// Prototipos de estructuras
struct NodoLSC;
struct LSClientes;

/*
Estructura lista simple
guarda la informacion de
cada cliente en cada
uno de sus nodos
*/
struct LSClientes{

public:
    //Atributos
    NodoLSC *primerNodo = nullptr, *ultimoNodo = nullptr;

    //Metodos
    LSClientes();
    int largoLista();
    NodoLSC *find(int);
    bool insertarAlInicio(QString, int, int);
    bool isInList(int);
    void imprimir();
};



/*
Estrcutrua nodo de lista simple que guarda
la informacion de un cliente
*/
struct NodoLSC{

public:
    //Atributos
    NodoLSC *siguiente = nullptr;
    QString nombre = "";
    int codigo = 0;
    int prioridad = 0;

    //Metodos
    NodoLSC(QString, int, int);
    void imprimir();

};

#endif // LSCLIENTES_H
