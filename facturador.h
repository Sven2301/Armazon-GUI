#ifndef FACTURADOR_H
#define FACTURADOR_H
#include <QThread>
#include <QtCore>
#include <QLabel>
#include "colapedidos.h"
#include "factura.h"


struct Facturador;

struct Facturador : QThread
{
public:

    QLabel *lblPersonal;
    QLabel *lblColaPorFacturar;
    ColaPedidos *colaPorFacturar;
    int totalFacturados;
    int actualFacturando;

    bool activo;
    bool pausa;

    //Metodos
    Facturador();
    void __init__(ColaPedidos*, QLabel*, QLabel*);

    void facturar(Pedido*);
    QString writeMsg(LSInfo*);
    void escribirArchivo(QString, QByteArray);
    void run();
    void pause();
    void resume();
};

#endif // FACTURADOR_H
