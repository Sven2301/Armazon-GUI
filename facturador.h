#ifndef FACTURADOR_H
#define FACTURADOR_H
#include <QThread>
#include <QtCore>
#include <QLabel>
#include "colapedidos.h"


struct Facturador;

struct Facturador : QThread
{
public:

    QLabel *lblPersonal;
    QLabel *lblColaPorFacturar;
    ColaPedidos *colaPorFacturar;
    int totalFacturados;

    bool activo;
    bool pausa;

    //Metodos
    Facturador();
    void __init__(ColaPedidos*, QLabel*, QLabel*);

    void facturar(Pedido*);
    void escribirArchivo(QString, QByteArray);
    void run();
    void pause();
    void resume();
};

#endif // FACTURADOR_H
