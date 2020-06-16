#ifndef ALISTADORES_H
#define ALISTADORES_H

#include "loaderthread.h"
#include <QThread>
#include <QtCore>

struct Alistador : QThread
{
public:
    int id;
    Pedido * pedido;
    LDArticulos* articulos;
    int duracionAlistador;
    ColaPedidos * colaAlistado;
    QLabel *lblPedidosAlistados;
    QLabel *lblColaAlistado;

    int pedidosAlistados;
    int pedidosActuales;

    QMutex *mutexAlistador;
    bool activo;
    bool pausa;

    //Metodos
    Alistador();
    void __init__(int, LDArticulos*, ColaPedidos*, QLabel*, QLabel*);
    QString getDuracion(QString);
    void findDuracionArticulo(QString codigo);
    void findArticuloPedido(Pedido*);
    void addInfoArticulos(Pedido*);
    void run();
    void pause();
    void resume();
    void finish();
};

#endif // ALISTADORES_H
