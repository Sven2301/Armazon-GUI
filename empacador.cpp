#include "empacador.h"

Empacador::Empacador() {}

void Empacador::__init__(QLabel *_lblPersonal, QLabel *_lblColaAlistado)
{
    colaAlistado = new ColaPedidos;
    colaPorFacturar = new ColaPedidos;
    mutexEmpacador = new QMutex();
    activo = true;
    pausa = false;
    totalEmpacados = 0;
    lblEmpacados = _lblPersonal;
    lblColaAlistado = _lblColaAlistado;

}

void Empacador::run()
{
    int i = 0; // Prueba
    while (activo) {
        while (pausa){
            sleep(1);
        }

        if(mutexEmpacador->tryLock()){
            if (!colaAlistado->vacia()){
                qDebug() << "\n***** EMPACADOR *****\n" << i;
                colaAlistado->imprimir();
                totalEmpacados++;
                lblEmpacados->setText(QString::number(totalEmpacados));
                NodoCP * tmp = colaAlistado->frente;
                int tiempoEmpacando = cantArticulos(tmp->pedido);

                pause();
                sleep(tiempoEmpacando);
                resume();
                start();
                qDebug() <<"\n***** SALE EMPACADOR *****\n" << i;
                colaAlistado->desencolar();

                colaAlistado->pedidosActuales -= 1;
                lblColaAlistado->setText(QString::number(colaAlistado->pedidosActuales) + " / " + QString::number(colaAlistado->pedidosTotales));

                colaPorFacturar->encolar(tmp->pedido);
                i++; // Prueba
            }
            /*else{
                qDebug() << "\nEsperando un pedido (EMPACADOR)";
            }*/
            mutexEmpacador->unlock();
        }
        sleep(1);

    }
}

int Empacador::cantArticulos(Pedido * pedido){
    NodoLSP * tmp = pedido->listaPedido->primerNodo;
    int contador = 0;
    while (tmp != nullptr) {
        contador++;
        tmp = tmp->siguiente;
    }
    return contador;
}

void Empacador::pause()
{
    pausa = true;
}

void Empacador::resume()
{
    pausa = false;
}

void Empacador::finish()
{
    activo = false;
}
