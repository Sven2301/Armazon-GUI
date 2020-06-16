#include "ldarticulos.h"

LDArticulos::LDArticulos()
{
    primerNodo = nullptr;
    ultimoNodo = nullptr;
}

// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void LDArticulos::imprimir(void)
{
     NodoLDA *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza
     int i=0;
     while (tmp != NULL){
         qDebug()<<"Imprimir el "<<i++<<"\n";

           tmp->imprimir();
           tmp = tmp->siguiente;

     }
     qDebug()<<"\n\n";
}

int LDArticulos::largoLista(void)
{
     NodoLDA *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza
     int i=0;
     while (tmp != NULL){
           i++;
           tmp = tmp->siguiente;


     }
     qDebug()<<"El largo es "<<i<<"\n";
     return i;
}

// funcion que inserta un nodo nuevo en la lista
// entradas: los datos a guardar
// salidas: no tiene
bool LDArticulos::insertarAlInicio(QString _codigo, QString _ubicacion, QString _categoria, int _tiempoFabricacion, int _cantidad, int _fila, int _columna)
{
     bool insertado = false;
     // si no hay elementos
     if (primerNodo == nullptr)
     {
          //ambos apuntan al nuevo en memoria
         primerNodo = new NodoLDA(_codigo, _ubicacion, _categoria, _tiempoFabricacion, _cantidad, _fila, _columna);
         insertado = true;
     }

     else
     {

         NodoLDA *nuevo = new NodoLDA(_codigo, _ubicacion, _categoria, _tiempoFabricacion, _cantidad, _fila, _columna);
         nuevo->siguiente = primerNodo;
         primerNodo->anterior = nuevo;
         primerNodo = nuevo;
         insertado = true;
     }

     return insertado;
}

QString LDArticulos::getUbicacion(QString codigo){


    NodoLDA *tmp = primerNodo;

    while(tmp != nullptr){


        if (tmp->strCodigo.toUpper() == codigo.toUpper()){

            return tmp->strUbicacion;
        }
        tmp = tmp->siguiente;
    }

    return "";
}

bool LDArticulos::isInList(QString dato){

    NodoLDA *tmp = primerNodo;

    if (tmp == nullptr)
        return false;

    while(tmp != nullptr){

        if (tmp->strCodigo == dato)
            return true; //El dato buscado si estaba en la lista
        tmp = tmp->siguiente;

    }
    return false; //Se termino el ciclo y el dato no se encontro

}

void NodoLDA::imprimir(void){

    qDebug()<<"\tCodigo:\t"<<strCodigo<<"\n";
    qDebug()<<"\tCantidad:\t"<<cantidad<<"\n";
    qDebug()<<"\tTiempo:\t"<<tiempoFabricacion<<"\n";
    qDebug()<<"\tCategoria:"<<strCategoria<<"\n";
    qDebug()<<"\tUbicacion:"<<strUbicacion<<"\n";

}

// Constructor
NodoLDA::NodoLDA (QString _codigo, QString _ubicacion, QString _categoria, int _tiempoFabricacion, int _cantidad, int _fila, int _columna){
    siguiente = nullptr;
    anterior = nullptr;
    strCodigo = _codigo;
    strUbicacion = _ubicacion;
    strCategoria = _categoria;
    tiempoFabricacion = _tiempoFabricacion;
    cantidad = _cantidad;
    fila = _fila;
    columna = _columna;
}
