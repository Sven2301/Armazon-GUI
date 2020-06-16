#include "pedido.h"

Pedido::Pedido(){

    listaPedido = new LSPedido();
    infoFactura = new Factura();
}

LSPedido::LSPedido(){primerNodo = nullptr;}


void Pedido::imprimir(){

    qDebug()<<"Pedido numero: "<<numeroPedido<<"\n\n";
    listaPedido->imprimir();
}
// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void LSPedido::imprimir(void)
{
     NodoLSP *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza
     //int i=0;
     while (tmp != NULL){
         //qDebug()<<"Imprimir el44 "<<tmp<<"\n";
         //qDebug()<<"Imprimir el "<<i++<<"\n";

           tmp->imprimir();
           tmp = tmp->siguiente;

     }
     qDebug()<<"\n\n";
}

int LSPedido::largoLista(void)
{
     NodoLSP *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza
     int i=0;
     while (tmp != NULL){
           i++;
           tmp = tmp->siguiente;


     }
     qDebug()<<"El largo es "<<i<<"\n";
     return i;
}

// Constructor
NodoLSP::NodoLSP (QString _codigo, int _cantidad, QString _ubicacion){
    siguiente = nullptr;
    codigo = _codigo;
    cantidad = _cantidad;
    completado = false;
    cantFaltante = 0;
    ubicacion = _ubicacion;

}

// funcion que inserta un nodo nuevo en la lista
// entradas: los datos a guardar
// salidas: no tiene
bool LSPedido::insertarAlInicio(QString _codigo, int _cantidad, QString _ubicacion)//QString, int, int
{
     bool insertado = false;
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoLSP(_codigo, _cantidad, _ubicacion);
         insertado = true;
     }
     else
     {
         NodoLSP *nuevo = new NodoLSP(_codigo, _cantidad, _ubicacion);
         nuevo->siguiente = primerNodo;
         primerNodo = nuevo;
         insertado = true;
     }
     return insertado;
}

void NodoLSP::imprimir(void){

    qDebug()<<"\tCodigo Articulo:\t"<<codigo;
    qDebug()<<"\tUbicacion:\t"<<ubicacion;
    qDebug()<<"\tCantidad:\t"<<cantidad;
    qDebug()<<"\tCantidad Faltante:\t"<<cantFaltante;
    qDebug()<<"\tFabrica:\t"<<fabrica;
    qDebug()<<"\tCompletado:\t"<<completado<<Qt::endl;
}

bool LSPedido::isInList(QString codigo){

    NodoLSP *tmp = primerNodo;

    while(tmp != nullptr){

        if (tmp->codigo == codigo)
            return true; //El dato buscado si estaba en la lista
        tmp = tmp->siguiente;

    }
    return false; //Se termino el ciclo y el dato no se encontro
}
