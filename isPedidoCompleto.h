#ifndef ISPEDIDOCOMPLETO_H
#define ISPEDIDOCOMPLETO_H

#include "loaderthread.h"
#include <QThread>
#include <QtCore>

// Prototipos de estructuras
struct PedidoCompletado;
//struct LSPedidoCompletado;
//struct NodoLSPCompletado;


struct PedidoCompletado : QThread
{
public:
    ColaPedidos * colaPedidoCompletado;
    ColaPedidos * colaAlisto;
    QMutex *mutexPedido;
    QLabel *lblColaAlistado;
    bool activo;
    bool pausa;

    //Metodos
    PedidoCompletado();
    void __init__(ColaPedidos*, QLabel*);
    bool isCompleted(Pedido*);
    void imprimir();

    void run();
    void pause();
    void resume();
    void finish();
};


#endif // ISPEDIDOCOMPLETO_H
