#include "facturador.h"

Facturador::Facturador()
{

}

void Facturador::__init__(ColaPedidos* _colaPorFacturar, QLabel *_lblPersonal, QLabel *_lblFacturar){

    colaPorFacturar = _colaPorFacturar;
    lblColaPorFacturar = _lblFacturar;
    lblPersonal = _lblPersonal;
    totalFacturados = 0;
    activo = true;
    pausa = false;

}

void Facturador::facturar(Pedido *pedido){

    QDateTime date;
    date = QDateTime::currentDateTime();
    QString strDate = date.toString("dd-MM-yyyy - hh-mm-ss");

    QString path = "C:/ITCR/Semestre I 2020/Estructuras de Datos/Proyectos/Proyecto 1/Armazon/Armazon/BD/Pedidos/Facturados_/" + pedido->infoFactura->numeroPedido + "_" +
                            pedido->infoFactura->codigoCliente + "_" + strDate + ".txt";
    QString strMsg = "Pedido:\t" + pedido->infoFactura->numeroPedido + "\n"
            + "Cliente:\t" + pedido->infoFactura->codigoCliente + "\n"
            + "En cola:\t" + pedido->infoFactura->horaLoader + "\n"
            + "Balanceador:\t" + pedido->infoFactura->horaBalancer + "\n"
            + "Alisto: \t" + pedido->infoFactura->horaAlisto + "\n"
            + "Empaque:\t" + pedido->infoFactura->horaEmpaque + "\n"
            + "Finalizado:\t" + pedido->infoFactura->horaFacturacion +"\n";
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
            lblPersonal->setText(QString::number(totalFacturados));

            QDateTime date;
            date = QDateTime::currentDateTime();
            QString strFechaHora = date.toString("dd-MM-yyyy hh:mm:ss");
            tmp->pedido->infoFactura->horaFacturacion = strFechaHora;

            facturar(tmp->pedido);


        }
        sleep(1);
    }
}
