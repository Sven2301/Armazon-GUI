#include "balancer.h"

Balancer::Balancer() {}

void Balancer::__init__(QMutex* _mutex, QMutex* _mutexP,
                        ColaPedidos* _colaPedidos, ColaPedidos* _colaPedidosP, ColaPedidos* _colaAlisto,
                        LDArticulos* _articulos,
                        Fabrica* _f1, Fabrica* _f2, Fabrica* _f3, Fabrica* _fComodin, QLabel *_lblColaPedidos,
                        QLabel *_lblBalanceador, QLabel *_lblAlisto, QLabel *_lblF1, QLabel *_lblF2, QLabel *_lblF3,
                        QLabel *_lblF4)
{
    mutexColaPedidos = _mutex;
    mutexColaPedidosP = _mutexP;
    lblColaPedidos = _lblColaPedidos;
    colaPedidos = _colaPedidos;
    colaPedidosPrioridad = _colaPedidosP;
    colaAlisto = _colaAlisto;
    articulos = _articulos;
    lblBalanceador = _lblBalanceador;
    lblColaAlisto = _lblAlisto;
    lblF1 = _lblF1;
    lblF2 = _lblF2;
    lblF3 = _lblF3;
    lblF4 = _lblF4;
    pedidosProcesados = 0;

    f1 = _f1;
    f2 = _f2;
    f3 = _f3;
    fComodin = _fComodin;

    activo = true;
    pausa = false;
}

void Balancer::run()
{
    while (activo) {
        while (pausa)
            sleep(1);

        if(!colaPedidosPrioridad->vacia()){

            if (mutexColaPedidosP->tryLock() and mutexColaPedidos->tryLock()){

                pedidoConPrioridad(colaPedidosPrioridad);
                mutexColaPedidos->unlock();
                mutexColaPedidosP->unlock();
            }else
                qDebug() << "\nEsperando un pedido (Balancer)";

        }
        else if(!colaPedidos->vacia()){
            if (mutexColaPedidos->tryLock() and mutexColaPedidosP->tryLock()){

                pedidoConPrioridad(colaPedidos);
                mutexColaPedidosP->unlock();
                mutexColaPedidos->unlock();
            }else
                qDebug() << "\nEsperando un pedido (Balancer)";

        }

        sleep(1);
    }
}

void Balancer::pedidoConPrioridad(ColaPedidos* colapedido)
{

    qDebug() << "\n***** BALANCER *****\n";
    qDebug() << "\nDesencolando pedido de la ColaPedidos";
    NodoCP * tmp = colapedido->desencolar();
    QDateTime date;
    date = QDateTime::currentDateTime();
    QString strFechaHora = date.toString("dd-MM-yyyy hh:mm:ss");
    tmp->pedido->infoFactura->horaBalancer = strFechaHora;
    pedidosProcesados++;
    lblBalanceador->setText(QString::number(pedidosProcesados));
    colaPedidos->pedidosActuales -= 1;
    int pedidosActuales = colaPedidosPrioridad->pedidosActuales + colaPedidos->pedidosActuales;
    int pedidosTotales = colaPedidosPrioridad->pedidosTotales + colaPedidos->pedidosTotales;
    lblColaPedidos->setText(QString::number(pedidosActuales) + " / " + QString::number(pedidosTotales));


    qDebug() << "Pedido " << tmp->pedido->numeroPedido << ", cliente: " << tmp->pedido->codigoCliente;

    if(pedidoCompleto(tmp)){
        colaAlisto->encolar(tmp->pedido);
        QDateTime date;
        date = QDateTime::currentDateTime();
        QString strFechaHora = date.toString("dd-MM-yyyy hh:mm:ss");
        tmp->pedido->infoFactura->horaAlisto = strFechaHora;
        colaAlisto->pedidosActuales += 1;
        colaAlisto->pedidosTotales += 1;
        lblColaAlisto->setText(QString::number(pedidosActuales) + " / " + QString::number(pedidosTotales));

        qDebug() << "\nPedido enviado a ColaAlisto";
    }else{
        direccionarAFabrica(tmp->pedido);
    }
}

char Balancer::findCategoriaArticulo(QString codigo)
{
    NodoLDA * tmpArticulo = articulos->primerNodo;

    while(tmpArticulo!=nullptr){
        if(tmpArticulo->strCodigo == codigo){

            QString code = tmpArticulo->strCategoria;
            std::string codeChar = code.toStdString();
            char categoria = codeChar[0]; // Letra del codigo del articulo

            return categoria;
        }
        tmpArticulo = tmpArticulo->siguiente;
    }
    return '0';
}

void Balancer::direccionarAFabrica(Pedido *pedido)
{
    NodoLSP * tmp = pedido->listaPedido->primerNodo;
    while(tmp != nullptr){

        char categoria = findCategoriaArticulo(tmp->codigo);

        int timefA = f1->tiempoEnFabrica(f1->colaFabrica);
        int timefB = f2->tiempoEnFabrica(f2->colaFabrica);
        int timefD = fComodin->tiempoEnFabrica(fComodin->colaFabrica);

        if(!tmp->completado){

            if(categoria == 'A'){
                if(timefA <= timefD){
                    f1->colaFabrica->encolar(pedido);

                    f1->colaFabrica->pedidosActuales += 1;
                    f1->colaFabrica->pedidosTotales += 1;
                    lblF1->setText(QString::number(f1->colaFabrica->pedidosActuales) + " / " + QString::number(f1->colaFabrica->pedidosTotales));

                    qDebug() << "\nPedido a FABRICA *";
                }else{
                    fComodin->colaFabrica->encolar(pedido);

                    fComodin->colaFabrica->pedidosActuales += 1;
                    fComodin->colaFabrica->pedidosTotales += 1;
                    lblF4->setText(QString::number(fComodin->colaFabrica->pedidosActuales) + " / " + QString::number(fComodin->colaFabrica->pedidosTotales));

                    qDebug() << "\nPedido a FABRICA A";
                }

            }else if(categoria == 'B'){
                if(timefB <= timefD){
                    fComodin->colaFabrica->encolar(pedido);

                    fComodin->colaFabrica->pedidosActuales += 1;
                    fComodin->colaFabrica->pedidosTotales += 1;
                    lblF4->setText(QString::number(fComodin->colaFabrica->pedidosActuales) + " / " + QString::number(fComodin->colaFabrica->pedidosTotales));

                    qDebug() << "\nPedido a FABRICA *";
                }else{
                    f2->colaFabrica->encolar(pedido);

                    f2->colaFabrica->pedidosActuales += 1;
                    f2->colaFabrica->pedidosTotales += 1;
                    lblF2->setText(QString::number(f2->colaFabrica->pedidosActuales) + " / " + QString::number(f2->colaFabrica->pedidosTotales));

                    qDebug() << "\nPedido a FABRICA B";
                }

            }else if(categoria == 'C'){
                f3->colaFabrica->encolar(pedido);

                f3->colaFabrica->pedidosActuales += 1;
                f3->colaFabrica->pedidosTotales += 1;
                lblF3->setText(QString::number(f3->colaFabrica->pedidosActuales) + " / " + QString::number(f3->colaFabrica->pedidosTotales));

                qDebug() << "\nPedido a FABRICA C";

            }else{
                qDebug() << "Error de codigo";
                break;
            }

        }else
            qDebug() << "Articulo en Stock";

        qDebug() << tmp->codigo << ", " << tmp->cantidad << ", " << tmp->completado;

        tmp = tmp->siguiente;
    }
    sleep(1);
}

// Retorna la cantidad faltante de un articulo del pedido
int Balancer::cantArticuloFaltante(NodoLSP *articuloPedido)
{
    int faltante = 0;
    NodoLDA * tmp = articulos->primerNodo;
    while (tmp!=nullptr) {
        if(articuloPedido->codigo == tmp->strCodigo){
            if(tmp->cantidad < articuloPedido->cantidad){
                faltante = (articuloPedido->cantidad)-(tmp->cantidad);
                tmp->cantidad = 0;

            }else if(tmp->cantidad >= articuloPedido->cantidad){
                tmp->cantidad -= articuloPedido->cantidad;
            }
            articuloPedido->cantFaltante = faltante;
            return faltante;
        }
        tmp = tmp->siguiente;
    }
    return 0;
}

// Retorna booleano si los articulos de un pedido estan en Stock
bool Balancer::pedidoCompleto(NodoCP *pedido)
{
    bool pedidoCompletado = true;
    NodoLSP * tmp = pedido->pedido->listaPedido->primerNodo;
    while(tmp != nullptr){
        if(cantArticuloFaltante(tmp) > 0)
            pedidoCompletado = false;
        else
            tmp->completado = true;

        tmp = tmp->siguiente;
    }
    return pedidoCompletado;
}


void Balancer::pause()
{
    pausa = true;
}

void Balancer::resume()
{
    pausa = false;
}

void Balancer::finish()
{
    activo = false;
}
