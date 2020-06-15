#ifndef FABRICAS_H
#define FABRICAS_H

#include "loaderthread.h"
#include "isPedidoCompleto.h"

#include <QThread>
#include <QtCore>

struct Fabrica : QThread
{
public:
    char tipo;
    ColaPedidos * colaFabrica;
    PedidoCompletado * verificarPedido;
    LDArticulos* articulos;

    QMutex *mutexFabrica;

    QLabel *lblPersonal;

    bool activo;
    bool pausa;
    int tiempoFabricacion;

    //Metodos
    Fabrica();
    void __init__(char, PedidoCompletado*, LDArticulos*, QLabel*);

    NodoLDA * findCategoriaArticulo(QString codigo);
    int setTime(Pedido*, bool);
    int tiempoEnFabrica(ColaPedidos*);

    void run();
    void pause();
    void resume();
    void finish();
};

#endif // FABRICAS_H
