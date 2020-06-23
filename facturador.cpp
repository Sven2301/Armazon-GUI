#include "facturador.h"

Facturador::Facturador()
{

}

void Facturador::__init__(ColaPedidos* _colaPorFacturar, QLabel *_lblPersonal, QLabel *_lblFacturar){

    colaPorFacturar = _colaPorFacturar;
    lblColaPorFacturar = _lblFacturar;
    lblPersonal = _lblPersonal;
    totalFacturados = 0;
    actualFacturando = 0;
    activo = true;
    pausa = false;

}

void Facturador::facturar(Pedido *pedido){

    QDateTime date;
    date = QDateTime::currentDateTime();
    QString strDate = date.toString("dd-MM-yyyy - hh-mm-ss");
    qDebug()<<pedido->infoFactura->numeroAlistador<<" Aqui presente";

    QString path = "C:/ITCR/Semestre I 2020/Estructuras de Datos/Proyectos/Proyecto 1/Armazon/Armazon/BD/Pedidos/Facturados_/" + pedido->infoFactura->numeroPedido + "_" +
                            pedido->infoFactura->codigoCliente + "_" + strDate + ".txt";
    //QString path = "C:/Users/Fung Méndez/Desktop/Diego/Sem III/Estructuras/PROYECTS/Proyecto CONSOLE/Proyecto_1/BD/Pedidos/Facturados/" + pedido->infoFactura->numeroPedido + "_" +
      //                      pedido->infoFactura->codigoCliente + "_" + strDate + ".txt";

    QString strMsg = "Pedido:\t" + pedido->infoFactura->numeroPedido + "\n"
            + "Cliente:\t" + pedido->infoFactura->codigoCliente + "\n"
            + "En cola:\t" + pedido->infoFactura->horaLoader + "\n"
            + "Balanceador:\t" + pedido->infoFactura->horaBalancer + "\n"
            + "Alisto: \t" + pedido->infoFactura->horaAlisto + "\n"
            + "Empaque:\t" + pedido->infoFactura->horaEmpaque + "\n"
            + "Finalizado:\t" + pedido->infoFactura->horaFacturacion +"\n"
            + "ALISTO\n Alistador # " + pedido->infoFactura->numeroAlistador + "\n";


    strMsg += writeMsg(pedido->infoFactura->infoArticulos);
    QByteArray msg = strMsg.toUtf8();
    qDebug()<<"Facturando\n";
    escribirArchivo(path, msg);
    //qDebug()<<"Facturado con exito\n";


}


void Facturador::escribirArchivo(QString path, QByteArray msg){

    QFile archivo;
    archivo.setFileName(path);

    archivo.open(QIODevice::ReadWrite | QIODevice::Text);
    archivo.write(msg);
    archivo.close();
    qDebug()<<"Facturado con exito\n";




}

void Facturador::run(){

    while(activo){

        while(pausa){

            sleep(1);
        }

        if (!colaPorFacturar->vacia()){

            NodoCP *tmp = colaPorFacturar->desencolar();
            colaPorFacturar->pedidosActuales -= 1;
            lblColaPorFacturar->setText(QString::number(colaPorFacturar->pedidosActuales) + " / " + QString::number(colaPorFacturar->pedidosTotales));
            totalFacturados++;
            actualFacturando++;
            lblPersonal->setText(QString::number(actualFacturando) + " / " + QString::number(totalFacturados));

            QDateTime date;
            date = QDateTime::currentDateTime();
            QString strFechaHora = date.toString("dd-MM-yyyy hh:mm:ss");
            tmp->pedido->infoFactura->horaFacturacion = strFechaHora;

            facturar(tmp->pedido);
            actualFacturando--;
            lblPersonal->setText(QString::number(actualFacturando) + " / " + QString::number(totalFacturados));


        }
        sleep(1);
    }
}

QString Facturador::writeMsg(LSInfo* listaArticulos){

    NodoInfo *tmp = listaArticulos->primerNodo;
    QString msg = "";

    while (tmp != nullptr){

        msg += tmp->codigo + "\t" + tmp->ubicacion + "\t" + tmp->duracion + "\n";

        tmp = tmp->siguiente;
    }
    return msg;
}
