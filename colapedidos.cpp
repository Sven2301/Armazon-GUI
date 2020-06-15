#include "colapedidos.h"
#include <QDebug>

ColaPedidos::ColaPedidos(){

    frente = nullptr;
    pedidosTotales = 0;
    pedidosActuales = 0;
}

NodoCP::NodoCP(Pedido* _pedido){

    siguiente = nullptr;
    pedido = _pedido;
}

void ColaPedidos::encolar (Pedido *pedido)//Puntero con a nodo LS
{
if (vacia())
         frente = new NodoCP (pedido);
      else
      {
            // referencia al primero para recorrer la lista
            NodoCP* actual = frente;
            // recorre la lista hasta llegar al penultimo nodo
            while (actual->siguiente != nullptr)
                          actual = actual->siguiente;

            // Crea nuevo nodo, lo apunta con uN
            NodoCP* nuevo = new NodoCP (pedido);
            //le quita el enlace al que era ultimo
            actual->siguiente = nuevo;
        }
}


// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria

NodoCP* ColaPedidos::desencolar(void)
{
      // si no hay elementos, no borra nada, retorna null
      if (vacia())
      {
         return nullptr;
      }
      else
      {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          NodoCP* borrado = frente;
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          frente = frente->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = nullptr;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
      }
}

bool ColaPedidos::vacia (void)
{
     if (frente == nullptr)
        return true;
     else
         return false;
}

void ColaPedidos::imprimir(void)
{
     qDebug() << "Frente\n";
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     NodoCP *tmp = frente;

     // mientras tmp no sea nulo, avanza
     while (tmp != nullptr)
     {
           // imprime el dato del nodo en el que esta tmp
           tmp->pedido->imprimir();
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     qDebug() << "Final\n";
}


NodoCP* ColaPedidos::verFrente()
{
      return frente;
}
