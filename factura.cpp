#include "factura.h"

Factura::Factura()
{
    numeroPedido = "";
    codigoCliente = "";
    horaLoader = "";
    horaBalancer = "";
    horaAlisto = "";
    horaEmpaque = "";
    horaFacturacion = "";
    numeroAlistador = "";
    codigoArticulo = "";
    duracionAlistador = "";
    infoArticulos = new LSInfo();

}


LSInfo::LSInfo()
{
    primerNodo = ultimoNodo = nullptr;
}

// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void LSInfo::imprimir(void)
{
     NodoInfo *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza

     while (tmp != NULL){

           tmp->imprimir();
           tmp = tmp->siguiente;

     }
     qDebug()<<"\n\n";
}

NodoInfo* LSInfo::find(QString _codigo)
{
     NodoInfo *tmp = primerNodo;

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

int LSInfo::largoLista(void)
{
     NodoInfo *tmp = primerNodo;

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
NodoInfo::NodoInfo (QString _codigo, QString _ubicacion, QString _duracion){
    siguiente = nullptr;
    ubicacion = _ubicacion;
    codigo = _codigo;
    duracion = _duracion;
}

// funcion que inserta un nodo nuevo en la lista
// entradas: los datos a guardar
// salidas: no tiene
bool LSInfo::insertarAlInicio(QString _codigo, QString _ubicacion, QString _duracion)
{
     bool insertado = false;
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoInfo(_codigo, _ubicacion, _duracion);
         insertado = true;
     }
     else
     {
         NodoInfo *nuevo = new NodoInfo(_codigo, _ubicacion, _duracion);
         nuevo->siguiente = primerNodo;
         primerNodo = nuevo;
         insertado = true;
     }
     return insertado;
}

void NodoInfo::imprimir(void){

    qDebug()<<"\tCodigo:\t"<<this->codigo;
    qDebug()<<"\tUbicacion:\t"<<this->ubicacion;
    qDebug()<<"\tDuracion: "<<this->duracion<<"\n";

}

bool LSInfo::isInList(QString codigo){

    NodoInfo *tmp = primerNodo;

    while(tmp != nullptr){

        if (tmp->codigo == codigo)
            return true; //El dato buscado si estaba en la lista
        tmp = tmp->siguiente;

    }
    return false; //Se termino el ciclo y el dato no se encontro
}
