#include "empacador.h"

Empacador::Empacador() {}

void Empacador::__init__(QLabel *_lblPersonal, QLabel *_lblColaAlistado, QLabel *_lblFacturar)
{
    colaAlistado = new ColaPedidos;
    colaPorFacturar = new ColaPedidos;
    mutexEmpacador = new QMutex();
    activo = true;
    pausa = false;
    totalEmpacados = 0;
    actualEmpacando = 0;
    lblEmpacados = _lblPersonal;
    lblColaAlistado = _lblColaAlistado;
    lblColaFacturar = _lblFacturar;

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
                NodoCP * tmp = colaAlistado->frente;
                int tiempoEmpacando = cantArticulos(tmp->pedido);
                totalEmpacados++;
                actualEmpacando++;
                lblEmpacados->setText( QString::number(actualEmpacando) + " / " + QString::number(totalEmpacados));

                pause();
                sleep(tiempoEmpacando);
                resume();
                start();
                qDebug() <<"\n***** SALE EMPACADOR *****\n" << i;
                QDateTime date;
                date = QDateTime::currentDateTime();
                QString strFechaHora = date.toString("dd-MM-yyyy hh:mm:ss");
                tmp->pedido->infoFactura->horaEmpaque = strFechaHora;
                colaAlistado->pedidosActuales -= 1;
                lblColaAlistado->setText(QString::number(colaAlistado->pedidosActuales) + " / " + QString::number(colaAlistado->pedidosTotales));

                colaAlistado->desencolar();


                colaPorFacturar->encolar(tmp->pedido);
                colaPorFacturar->pedidosActuales += 1;
                colaPorFacturar->pedidosTotales += 1;
                lblColaFacturar->setText(QString::number(colaPorFacturar->pedidosActuales) + " / " + QString::number(colaPorFacturar->pedidosTotales));

                actualEmpacando--;
                lblEmpacados->setText( QString::number(actualEmpacando) + " / " + QString::number(totalEmpacados));

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
