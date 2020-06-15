#include "mainwindow.h"
#include "loaderthread.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QByteArray texto;
    //LoaderThread *l = new LoaderThread();
    //l->_init_(&mutexColaPedidos);
    //l->cargarClientes(); ***
    //l->cargarArticulos(); ***
    //texto = l->leerArchivo("C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Pedidos\\Sin procesar\\d.txt");
    //l->listaClientes->imprimir();
    //texto = l->leerArchivo("C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Articulos.txt");
    //l->listaArticulos->imprimir();
    //l->cargarPedido(); ***
    //l->cargarPedido(); ***
    //l->start();

    MainWindow w;
    w.show();

    return a.exec();
}
