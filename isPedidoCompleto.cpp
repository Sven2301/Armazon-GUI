#include "isPedidoCompleto.h"

PedidoCompletado::PedidoCompletado() {}

void PedidoCompletado::__init__(ColaPedidos * _colaAlisto, QLabel* _lblAlistado)
{
    colaPedidoCompletado = new ColaPedidos();
    colaAlisto = _colaAlisto;
    mutexPedido = new QMutex();
    lblColaAlistado = _lblAlistado;
    activo = true;
    pausa = false;
}

void PedidoCompletado::run()
{
    while (activo) {
        while (pausa){
            sleep(1);
        }

        if(mutexPedido->tryLock()){
            if (!colaPedidoCompletado->vacia()){
                qDebug() << "\n***** PedidoCompleto? *****";
                NodoCP * aux = colaPedidoCompletado->frente;

                if(isCompleted(aux->pedido)){
                    qDebug() << "Pedido se dirige a la cola de Alisto" << aux->pedido->numeroPedido;
                    // Encolado en colaAlisto

                    colaAlisto->encolar(aux->pedido);
                    colaAlisto->pedidosActuales += 1;
                    colaAlisto->pedidosTotales += 1;
                    lblColaAlistado->setText(QString::number(colaAlisto->pedidosActuales) + " / " + QString::number(colaAlisto->pedidosTotales));

                    colaPedidoCompletado->desencolar();

                }else{
                    qDebug() << "El pedido todavía no está completo"  << aux->pedido->numeroPedido;
                    colaPedidoCompletado->desencolar();
                }

                colaPedidoCompletado->imprimir();

            }/*else{
                qDebug() << "\nEsperando un pedido de fabrica (PedidoCompleto)";
            }*/
            mutexPedido->unlock();
        }
        sleep(1);
    }
}

bool PedidoCompletado::isCompleted(Pedido * pedido){
    NodoLSP * tmp = pedido->listaPedido->primerNodo;

    while(tmp != nullptr){
        if(!tmp->completado){
            qDebug() << "\nNo completos: " << tmp->codigo << "Cantidad faltante: " << tmp->cantFaltante;
            return false;
        }
        tmp = tmp->siguiente;
    }
    sleep(1);
    return true;
}

void PedidoCompletado::pause()
{
    pausa = true;
}

void PedidoCompletado::resume()
{
    pausa = false;
}

void PedidoCompletado::finish()
{
    activo = false;
}
