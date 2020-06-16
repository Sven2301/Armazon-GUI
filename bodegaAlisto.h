#ifndef BODEGAALISTO_H
#define BODEGAALISTO_H

#include "loaderthread.h"
#include "alistadores.h"
#include <QThread>
#include <QtCore>

struct BodegaAlisto;
struct ColaAlistadores;
struct NodoCA;

struct BodegaAlisto : QThread
{
public:
    ColaPedidos * colaAlisto;
    ColaAlistadores * colaAlistadores;
    ColaPedidos * colaAlistado;
    LDArticulos* articulos;
    QMutex *mutexAlistadores;
    QLabel *lblColaAlisto;

    Alistador *a1, *a2, *a3, *a4, *a5, *a6;

    bool activo;
    bool pausa;

    //Metodos
    BodegaAlisto();
    void __init__(LDArticulos*, ColaPedidos*, QLabel*, QLabel*, QLabel*, QLabel*, QLabel*, QLabel*, QLabel*, QLabel*);

    NodoCA* alistadorDisponible(void);
    int largoLista(void);
    void run();
    void pause();
    void resume();
    void finish();
};


// Estructuras para la cola de Alistadores
struct ColaAlistadores {

       NodoCA *frente;
public:
       //Metodos
       ColaAlistadores();
       void encolar (Alistador*);
       NodoCA* desencolar (void);
       NodoCA* verFrente(void);
       bool vacia(void);
       void imprimir(void);
};


struct NodoCA {

       Alistador * alistador;
       NodoCA * siguiente;// puntero para enlazar nodos

public:
       //Metodos
       NodoCA(Alistador*);
};


#endif // BODEGAALISTO_H
