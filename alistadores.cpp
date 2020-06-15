#include "alistadores.h"

Alistador::Alistador() {}

void Alistador::__init__(int _id, LDArticulos * _articulos, ColaPedidos * _colaAlistado,
                         QLabel *_lblPersonal, QLabel* _lblAlistado)
{
    id = _id;
    pedido = nullptr;
    mutexAlistador = new QMutex();
    articulos = _articulos;
    duracionAlistador = 0;
    colaAlistado = _colaAlistado;
    lblPedidosAlistados = _lblPersonal;
    lblColaAlistado = _lblAlistado;
    activo = true;
    pausa = false;
    pedidosAlistados = 0;
}

void Alistador::run()
{
    while (activo) {
        while (pausa){
            sleep(1);
        }

        if(mutexAlistador->tryLock()){
            if (pedido != nullptr){
                findArticuloPedido(pedido);

                qDebug() << "--------ENTRA ALISTADOR " << id << "---------";
                qDebug() << "\nTiempo que dura el Alistador: " << duracionAlistador;
                pedidosAlistados++;
                lblPedidosAlistados->setText(QString::number(pedidosAlistados));

                pause();
                sleep(duracionAlistador);
                resume();
                start();
                qDebug() << "---------SALE ALISTADOR " << id << "---------";

                colaAlistado->pedidosTotales += 1;
                colaAlistado->pedidosActuales += 1;
                lblColaAlistado->setText(QString::number(colaAlistado->pedidosActuales) + " / " + QString::number(colaAlistado->pedidosTotales));


                colaAlistado->encolar(pedido);
                pedido = nullptr;
                finish();

            }
            /*else{
                qDebug() << "\nEsperando un pedido (Alistador " << id << " )";
            }*/
            mutexAlistador->unlock();
        }
        sleep(1);

    }
}

void Alistador::findDuracionArticulo(QString codigo)
{
    NodoLDA * tmpArticulo = articulos->primerNodo;
    int fila = 0;
    int columna = 0;

    while(tmpArticulo!=nullptr){
        if(tmpArticulo->strCodigo == codigo){

            fila = tmpArticulo->fila;
            columna = tmpArticulo->columna;
            duracionAlistador += ((fila+columna)-1)*2;
        }
        tmpArticulo = tmpArticulo->siguiente;
    }
}

void Alistador::findArticuloPedido(Pedido *pedido)
{
    NodoLSP * tmp = pedido->listaPedido->primerNodo;
    while(tmp != nullptr){

        findDuracionArticulo(tmp->codigo);

        qDebug() << tmp->codigo << "TIEMPO DE ALISTADOR " << id;

        tmp = tmp->siguiente;
    }
}


void Alistador::pause()
{
    pausa = true;
}

void Alistador::resume()
{
    pausa = false;
}

void Alistador::finish()
{
    activo = false;
}
