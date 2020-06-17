#include "bodegaAlisto.h"

BodegaAlisto::BodegaAlisto() {}

void BodegaAlisto::__init__(LDArticulos * _articulos, ColaPedidos * _colaAlistado, QLabel *_lblAlisto,
                            QLabel *lblAlistador1, QLabel *lblAlistador2, QLabel *lblAlistador3, QLabel *lblAlistador4,
                            QLabel *lblAlistador5, QLabel *lblAlistador6, QLabel *_lblcolaAlistado)
{
    colaAlisto = new ColaPedidos;
    colaAlistadores = new ColaAlistadores;
    colaAlistado = _colaAlistado;
    mutexAlistadores = new QMutex();
    lblColaAlisto = _lblAlisto;
    articulos = _articulos;
    activo = true;
    pausa = false;

    a1 = new Alistador;
    a2 = new Alistador;
    a3 = new Alistador;
    a4 = new Alistador;
    a5 = new Alistador;
    a6 = new Alistador;
    a1->__init__(1, articulos, colaAlistado, lblAlistador1, _lblcolaAlistado);
    a2->__init__(2, articulos, colaAlistado, lblAlistador2, _lblcolaAlistado);
    a3->__init__(3, articulos, colaAlistado, lblAlistador3, _lblcolaAlistado);
    a4->__init__(4, articulos, colaAlistado, lblAlistador4, _lblcolaAlistado);
    a5->__init__(5, articulos, colaAlistado, lblAlistador5, _lblcolaAlistado);
    a6->__init__(6, articulos, colaAlistado, lblAlistador6, _lblcolaAlistado);
    colaAlistadores->encolar(a1);
    colaAlistadores->encolar(a2);
    colaAlistadores->encolar(a3);
    colaAlistadores->encolar(a4);
    colaAlistadores->encolar(a5);
    colaAlistadores->encolar(a6);


}

void BodegaAlisto::run()
{
    while (activo) {
        while (pausa){
            sleep(1);
        }

        if(mutexAlistadores->tryLock()){
            if (!colaAlisto->vacia()){
                qDebug() << "\n***** BODEGA *****\n";
                colaAlisto->imprimir();

                NodoCA * alistadorLibre = alistadorDisponible();

                if(alistadorLibre != NULL){
                    NodoCP * tmp = colaAlisto->desencolar();

                    colaAlisto->pedidosActuales -= 1;
                    lblColaAlisto->setText(QString::number(colaAlisto->pedidosActuales) + " / " + QString::number(colaAlisto->pedidosTotales));

                    alistadorLibre->alistador->pedido = tmp->pedido;

                    alistadorLibre->alistador->resume();
                    alistadorLibre->alistador->start();

                    colaAlistadores->encolar(alistadorLibre->alistador);
                }else
                    qDebug() << "No hay alistador disponible \n";

            }
            /*else{
                qDebug() << "\nEsperando un pedido (BODEGA)";
            }*/
            mutexAlistadores->unlock();
        }
        sleep(1);

    }
}

NodoCA* BodegaAlisto::alistadorDisponible(){
    int i = 0;
    NodoCA * ocupado;
    NodoCA * tmp = colaAlistadores->frente;

    while (tmp != nullptr) {
        if(i >= largoLista())
            return NULL;
        if(tmp->alistador->pedido == NULL)
            return colaAlistadores->desencolar();

        ocupado = colaAlistadores->desencolar();
        colaAlistadores->encolar(ocupado->alistador);
        i++;
        tmp = tmp->siguiente;
    }
    //qDebug() << "Alistador: "<< tmp->alistador->id;
    return NULL;
}

int BodegaAlisto::largoLista(void)
{
     NodoCA *tmp = colaAlistadores->frente;

     // mientras tmp no sea nulo, avanza
     int i=0;
     while (tmp != NULL){
           i++;
           tmp = tmp->siguiente;
     }
     return i;
}

void BodegaAlisto::pause()
{
    pausa = true;
}

void BodegaAlisto::resume()
{
    pausa = false;
}

void BodegaAlisto::finish()
{
    activo = false;
}

//-------------------------------------------------
// Cola para los Alistadores

ColaAlistadores::ColaAlistadores(){frente = nullptr;}

NodoCA::NodoCA(Alistador * _alistador){

    siguiente = nullptr;
    alistador = _alistador;
}

void ColaAlistadores::encolar (Alistador * alistador)//Puntero con a nodo LS
{
if (vacia())
         frente = new NodoCA (alistador);
      else
      {
            NodoCA* actual = frente;
            while (actual->siguiente != nullptr)
                          actual = actual->siguiente;

            NodoCA* nuevo = new NodoCA (alistador);
            actual->siguiente = nuevo;
        }
}

NodoCA* ColaAlistadores::desencolar(void)
{
      if (vacia())
      {
         return nullptr;
      }
      else
      {
          NodoCA* borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = nullptr;
          return borrado;
      }
}

bool ColaAlistadores::vacia (void)
{
     if (frente == nullptr)
        return true;
     else
         return false;
}

void ColaAlistadores::imprimir(void)
{
     qDebug() << "Frente\n";
     NodoCA *tmp = frente;

     while (tmp != nullptr)
     {
           tmp->alistador->pedido->imprimir();
           tmp = tmp->siguiente;
     }
     qDebug() << "Final\n";
}

NodoCA* ColaAlistadores::verFrente()
{
      return frente;
}


