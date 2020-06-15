#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H
#include "pedido.h"

struct NodoCP;
struct ColaPedidos;

struct ColaPedidos {

       NodoCP *frente;
       int pedidosActuales;
       int pedidosTotales;
public:

       ColaPedidos();
       void encolar (Pedido*);
       NodoCP* desencolar (void);
       NodoCP* verFrente(void);
       bool vacia(void);
       void imprimir(void);

};


struct NodoCP {

       Pedido * pedido; // parte de datos
       NodoCP * siguiente;// puntero para enlazar nodos

       // constructor
public:
      NodoCP(Pedido*);
      void imprimir();

};

#endif // COLAPEDIDOS_H
