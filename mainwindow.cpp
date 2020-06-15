#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_botonEmpezar_clicked()
{
    loader = new LoaderThread();
    loader->_init_(&mutexColaPedidos, &mutexColaPedidosP, ui->lblColaPedidos);
    loader->cargarClientes();
    if(!loader->error){
        loader->cargarArticulos();
        if (!loader->error){
            loader->start();

            // new
            balancer = new Balancer();
            f1 = new Fabrica();
            f2 = new Fabrica();
            f3 = new Fabrica();
            fComodin = new Fabrica();
            verificarPedido = new PedidoCompletado();
            bodega = new BodegaAlisto;
            empacador = new Empacador;
            facturador = new Facturador();
            //factura = new Factura;

            empacador->__init__(ui->lblEmpacador, ui->lblColaAlistado, ui->lblPorFacturar);
            facturador->__init__(empacador->colaPorFacturar, ui->lblFacturador, ui->lblPorFacturar);
            // factura->__init__(empacador->colaPorFacturar);
            bodega->__init__(loader->listaArticulos, empacador->colaAlistado, ui->lblColaAlisto,
                             ui->lblAlistador1, ui->lblAlistador2, ui->lblAlistador3, ui->lblAlistador4,
                             ui->lblAlistador5, ui->lblAlistador6, ui->lblColaAlistado);
            verificarPedido->__init__(bodega->colaAlisto, ui->lblColaAlisto);

            f1->__init__('A', verificarPedido, loader->listaArticulos, ui->lblFabrica1);
            f2->__init__('B', verificarPedido, loader->listaArticulos, ui->lblFabrica2);
            f3->__init__('C', verificarPedido, loader->listaArticulos, ui->lblFabrica3);
            fComodin->__init__('*', verificarPedido, loader->listaArticulos, ui->lblFabricaComodin);

            balancer->__init__(&mutexColaPedidos, &mutexColaPedidosP,
                               loader->colaPedidos,loader->colaPedidosPrioridad, bodega->colaAlisto,
                               loader->listaArticulos,f1, f2, f3, fComodin, ui->lblColaPedidos, ui->lblBalanceador, ui->lblColaAlisto,
                               ui->lblFabrica1, ui->lblFabrica2, ui->lblFabrica3, ui->lblFabricaComodin);

            // start
            balancer->start();
            f1->start();
            f2->start();
            f3->start();
            fComodin->start();
            verificarPedido->start();
            bodega->start();
            empacador->start();
            facturador->start();
        }
        else
           qDebug()<<"No inicio ERROR en Articulos\n";
    }
    else
        qDebug()<<"No inicio ERROR en clientes\n";
}

void MainWindow::on_botonPausar_clicked()
{
    loader->pausado = true;
}

void MainWindow::on_botonReanudar_clicked()
{
    loader->pausado = false;
}

void MainWindow::on_btnPausar_Balancer_clicked()
{
    balancer->pausa = true;
}

void MainWindow::on_btnReanudar_Balancer_clicked()
{
    balancer->pausa = false;
}
