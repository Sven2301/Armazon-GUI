#include "fabricas.h"

Fabrica::Fabrica() {}

void Fabrica::__init__(char tipoFabrica, PedidoCompletado * _verificarPedido, LDArticulos * _articulos, QLabel *_lblPersonal)
{
    tipo = tipoFabrica;
    verificarPedido = _verificarPedido;
    articulos = _articulos;
    colaFabrica = new ColaPedidos;
    mutexFabrica = new QMutex();
    activo = true;
    pausa = false;
    tiempoFabricacion = 0;

    lblPersonal = _lblPersonal;
}

void Fabrica::run()
{
    while (activo) {
        while (pausa){
            sleep(1);
        }

        if(mutexFabrica->tryLock()){
            if (!colaFabrica->vacia()){
                qDebug() << "\n***** FABRICA "<< tipo <<"*****\n";
                NodoCP * aux = colaFabrica->frente;

                setTime(aux->pedido,true);

                colaFabrica->desencolar();

                colaFabrica->pedidosActuales -= 1;
                lblPersonal->setText(QString::number(colaFabrica->pedidosActuales) + " / " + QString::number(colaFabrica->pedidosTotales));


                verificarPedido->colaPedidoCompletado->encolar(aux->pedido);

                qDebug() << "\nDesencolando de colaFabrica";
            }
            /*else{
                qDebug() << "\nEsperando un pedido (Fabrica " << tipo << " )";
            }*/
            mutexFabrica->unlock();
        }
        sleep(1);

    }
}

// Retorna el Articulo en inventario buscado
NodoLDA * Fabrica::findCategoriaArticulo(QString codigo)
{
    NodoLDA * tmpArticulo = articulos->primerNodo;

    while(tmpArticulo!=nullptr){
        if(tmpArticulo->strCodigo == codigo){
            return tmpArticulo;
        }
        tmpArticulo = tmpArticulo->siguiente;
    }
    return NULL;
}

// Espera los segundos de fabricacion y retorna el dato
int Fabrica::setTime(Pedido * pedido, bool caso)
{
    NodoLSP * tmp = pedido->listaPedido->primerNodo;
    NodoLDA * tmpArticulo;
    int faltante;

    while (tmp != nullptr) {

        tmpArticulo = findCategoriaArticulo(tmp->codigo);

        if(tmpArticulo->strCategoria == tipo || tipo == '*'){
            if(tmp->cantFaltante > 0){

                faltante = tmp->cantFaltante*tmpArticulo->tiempoFabricacion;

                if(caso){
                    qDebug() << "--------ENTRA---------";
                    qDebug() << "Pedido " << pedido->numeroPedido << ", cliente: " << pedido->codigoCliente;
                    qDebug() << "Tiempo de Espera: " << faltante;
                    pause();
                    sleep(faltante);
                    tmp->completado = true;
                    resume();
                    start();
                    qDebug() << "---------SALE---------";
                }

                return faltante;
            }else
                tmp->completado = true;
        }
        tmp = tmp->siguiente;
    }
    return 0;
}

// Retorna la cantidad de segundos que la colaFabrica tiene que procesar
int Fabrica::tiempoEnFabrica(ColaPedidos * colaFabrica)
{
    NodoCP * tmp = colaFabrica->frente;
    int tiempoEnFabrica = 0;
    while(tmp!= nullptr){
        tiempoEnFabrica += setTime(tmp->pedido, false);
        tmp = tmp->siguiente;
    }
    return tiempoEnFabrica;
}

void Fabrica::pause()
{
    pausa = true;
}

void Fabrica::resume()
{
    pausa = false;
}

void Fabrica::finish()
{
    activo = false;
}
