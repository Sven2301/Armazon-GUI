#ifndef LOADERTHREAD_H
#define LOADERTHREAD_H
#include "pedido.h"
#include "lsclientes.h"
#include "ldarticulos.h"
#include "colapedidos.h"
#include <QtCore>
#include <QDir>
#include <QFile>
#include <QMap>
#include <QDateTime>
#include <QLabel>

struct mapValorLetras;
struct Coordenadas;
struct pathName;
struct LoaderThread;

struct LoaderThread : public QThread
{
public:
    //Atributos
    bool activo, pausado, error;
    LSClientes *listaClientes;
    LDArticulos *listaArticulos;
    ColaPedidos *colaPedidos;
    ColaPedidos *colaPedidosPrioridad;
    QMutex *mutexColaPedidos;
    QMutex *mutexColaPedidosP;
    QList <int>numeroPedidos;
    QLabel *lblColaPedidos;

public:
    //Metodos
    LoaderThread();
    ~LoaderThread();
    void _init_ (QMutex*, QMutex*, QLabel*);

    void pausar();
    void reanudar();
    QByteArray leerArchivo(QString);
    void cargarClientes(void);
    void cargarArticulos(void);
    Coordenadas* convertirUbicacion(QString);
    QString renombrarArchivo(QString);
    void copiarArchivo(QString, QString);
    void escribirArchivo(QString, QByteArray);
    void borrarArchivo(QString);
    void cargarPedido(void);
    void run();
};

struct Coordenadas{ int fila; int columna; };

struct pathName{QString path; QString nombreArchivo;};

struct MapaValorLetras{

    QMap <QChar, int> valorLetras;

    MapaValorLetras();
};

#endif // LOADERTHREAD_H
