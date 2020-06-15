#include "lsclientes.h"

LSClientes::LSClientes()
{
    primerNodo = ultimoNodo = nullptr;
}

// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void LSClientes::imprimir(void)
{
     NodoLSC *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza

     while (tmp != NULL){

           tmp->imprimir();
           tmp = tmp->siguiente;

     }
     qDebug()<<"\n\n";
}

NodoLSC* LSClientes::find(int _codigo)
{
     NodoLSC *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza

     while (tmp != nullptr){

           if (tmp->codigo == _codigo){
               qDebug()<<"Nodo encontrado\n";
               tmp->imprimir();
               return tmp;
           }
           tmp = tmp->siguiente;

     }
     return nullptr;
}

int LSClientes::largoLista(void)
{
     NodoLSC *tmp = primerNodo;

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
NodoLSC::NodoLSC (QString _nombre, int _codigo, int _prioridad){
    siguiente = nullptr;
    nombre = _nombre;
    codigo = _codigo;
    prioridad = _prioridad;
}

// funcion que inserta un nodo nuevo en la lista
// entradas: los datos a guardar
// salidas: no tiene
bool LSClientes::insertarAlInicio(QString _nombre, int _codigo, int _prioridad)//QString, int, int
{
     bool insertado = false;
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoLSC(_nombre, _codigo, _prioridad);
         insertado = true;
     }
     else
     {
         NodoLSC *nuevo = new NodoLSC(_nombre, _codigo, _prioridad);
         nuevo->siguiente = primerNodo;
         primerNodo = nuevo;
         insertado = true;
     }
     return insertado;
}

void NodoLSC::imprimir(void){

    qDebug()<<"\tNombre:\t"<<this->nombre;
    qDebug()<<"\tCodigo:\t"<<this->codigo;
    qDebug()<<"\tPrioridad: "<<this->prioridad<<"\n";

}

bool LSClientes::isInList(int dato){

    NodoLSC *tmp = primerNodo;

    while(tmp != nullptr){

        if (tmp->codigo == dato)
            return true; //El dato buscado si estaba en la lista
        tmp = tmp->siguiente;

    }
    return false; //Se termino el ciclo y el dato no se encontro
}
