#ifndef EMPACADOR_H
#define EMPACADOR_H

#include "colapedidos.h"
#include <QThread>
#include <QtCore>
#include <QLabel>

struct Empacador;

struct Empacador : QThread
{
public:
    ColaPedidos * colaAlistado;
    ColaPedidos * colaPorFacturar;
    QMutex *mutexEmpacador;
    QLabel *lblEmpacados;
    QLabel *lblColaAlistado;
    int totalEmpacados;


    bool activo;
    bool pausa;

    //Metodos
    Empacador();
    void __init__(QLabel*, QLabel*);

    int cantArticulos(Pedido*);
    void run();
    void pause();
    void resume();
    void finish();
};

#endif // EMPACADOR_H
