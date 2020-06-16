#ifndef BALANCER_H
#define BALANCER_H
#include "loaderthread.h"
#include "fabricas.h"
#include "isPedidoCompleto.h"
#include "pedido.h"
#include "bodegaAlisto.h"

#include <QtCore>

// Prototipos de estructuras
struct Balancer;

struct Balancer : public QThread
{
public:
    //Atributos
    ColaPedidos* colaPedidos;
    ColaPedidos* colaPedidosPrioridad;
    ColaPedidos* colaAlisto;
    QMutex *mutexColaPedidos;
    QMutex *mutexColaPedidosP;
    QLabel *lblColaPedidos;
    QLabel *lblBalanceador;
    QLabel *lblColaAlisto;
    QLabel *lblF1;
    QLabel *lblF2;
    QLabel *lblF3;
    QLabel *lblF4;
    LDArticulos* articulos;
    int pedidosProcesadosTotales;
    int pedidosProcesadosActuales;
    bool activo;
    bool pausa;

    Fabrica * f1;
    Fabrica * f2;
    Fabrica * f3;
    Fabrica * fComodin;
    PedidoCompletado * verificarPedido;

public:
    //Metodos
    Balancer();
    void __init__(QMutex*, QMutex*, ColaPedidos*, ColaPedidos*, ColaPedidos*, LDArticulos*,
                  Fabrica*, Fabrica*,Fabrica*,Fabrica*, QLabel*, QLabel*, QLabel*,
                  QLabel*, QLabel*, QLabel*, QLabel*);

    void run();

    void pedidoConPrioridad(ColaPedidos*);
    int cantArticuloFaltante(NodoLSP*);
    bool pedidoCompleto(NodoCP*);
    void direccionarAFabrica(Pedido*);
    char findCategoriaArticulo(QString codigo);

    void pause();
    void resume();
    void finish();
};

#endif // BALANCER_H
