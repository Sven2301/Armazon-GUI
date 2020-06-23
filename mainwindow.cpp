#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMovie>
#include <QtMultimedia/QMediaPlayer>
#include <QDesktopWidget>

//  Steven Granados - 2019037999
//  Diego Fung - 2019308467

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// BG



    resize(QDesktopWidget().availableGeometry(this).size() * 0.90);
    //QPixmap backg("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fallout-Terminal.jpg");
    //QPixmap backg("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fallout-Terminal.jpg");
    QPixmap backg("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Fallout-Terminal.jpg");

    backg = backg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backg);
    this->setPalette(palette);

// GIF
    //LOADER
    //loaderGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Loader-VaultBoy.gif");
    //loaderGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Loader-VaultBoy.gif");
    loaderGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Loader-VaultBoy.gif");

    QLabel *loaderAnimation = new QLabel(this);
    loaderAnimation->setMovie(loaderGIF);
    loaderAnimation->setGeometry(0, 250, 125, 125);
    loaderGIF->start();
    loaderGIF->stop();


    //BALANCER
    //balancerGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Balancer-VaultBoy.gif");
    //balancerGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Balancer-VaultBoy.gif");
    balancerGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Balancer-VaultBoy.gif");

    QLabel *balancerAnimation = new QLabel(this);
    balancerAnimation->setMovie(balancerGIF);
    balancerAnimation->setGeometry(400, 250, 125, 125);
    balancerGIF->start();
    balancerGIF->stop();

    //FABRICA A
    //fabricaAGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    //QMovie *fabricaAGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    fabricaAGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Fabrica-VaultBoy.gif");

    QLabel *fabricaAAnimation = new QLabel(this);
    fabricaAAnimation->setMovie(fabricaAGIF);
    fabricaAAnimation->setGeometry(370, 0, 125, 125);
    fabricaAGIF->start();
    fabricaAGIF->stop();


    //FABRICA B
    //fabricaBGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    //fabricaBGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    fabricaBGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Fabrica-VaultBoy.gif");

    QLabel *fabricaBAnimation = new QLabel(this);
    fabricaBAnimation->setMovie(fabricaBGIF);
    fabricaBAnimation->setGeometry(495, 0, 125, 125);
    fabricaBGIF->start();
    fabricaBGIF->stop();

    //FABRICA C
    //fabricaCGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    //fabricaCGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    fabricaCGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Fabrica-VaultBoy.gif");


    QLabel *fabricaCAnimation = new QLabel(this);
    fabricaCAnimation->setMovie(fabricaCGIF);
    fabricaCAnimation->setGeometry(620, 0, 125, 125);
    fabricaCGIF->start();
    fabricaCGIF->stop();

    //FABRICA COMODIN
    //fabricaCoGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    //fabricaCoGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    fabricaCoGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Fabrica-VaultBoy.gif");

    QLabel *fabricaCoAnimation = new QLabel(this);
    fabricaCoAnimation->setMovie(fabricaCoGIF);
    fabricaCoAnimation->setGeometry(745, 0, 125, 125);
    fabricaCoGIF->start();
    fabricaCoGIF->stop();

    //ALISTADOR 1
    //alistador1GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    //alistador1GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    alistador1GIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador1Animation = new QLabel(this);
    alistador1Animation->setMovie(alistador1GIF);
    alistador1Animation->setGeometry(475, 520, 125, 125);
    alistador1GIF->start();
    alistador1GIF->stop();

    //ALISTADOR 2
    //alistador2GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    //alistador2GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    alistador2GIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador2Animation = new QLabel(this);
    alistador2Animation->setMovie(alistador2GIF);
    alistador2Animation->setGeometry(600, 520, 125, 125);
    alistador2GIF->start();
    alistador2GIF->stop();

    //ALISTADOR 3
    //alistador3GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    //alistador3GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    alistador3GIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador3Animation = new QLabel(this);
    alistador3Animation->setMovie(alistador3GIF);
    alistador3Animation->setGeometry(725, 520, 125, 125);
    alistador3GIF->start();
    alistador3GIF->stop();

    //ALISTADOR 4
    //alistador4GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    //alistador4GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    alistador4GIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador4Animation = new QLabel(this);
    alistador4Animation->setMovie(alistador4GIF);
    alistador4Animation->setGeometry(850, 520, 125, 125);
    alistador4GIF->start();
    alistador4GIF->stop();

    //ALISTADOR 5
    //alistador5GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    //alistador5GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    alistador5GIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador5Animation = new QLabel(this);
    alistador5Animation->setMovie(alistador5GIF);
    alistador5Animation->setGeometry(975, 520, 125, 125);
    alistador5GIF->start();
    alistador5GIF->stop();

    //ALISTADOR 6
    //alistador6GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    //alistador6GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    alistador6GIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador6Animation = new QLabel(this);
    alistador6Animation->setMovie(alistador6GIF);
    alistador6Animation->setGeometry(1100, 520, 125, 125);
    alistador6GIF->start();
    alistador6GIF->stop();

    //EMPACADOR
    //empacadorGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Empacador-VaultBoy.gif");
    //empacadorGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Empacador-VaultBoy.gif");
    empacadorGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Empacador-VaultBoy.gif");

    QLabel *empacadorAnimation = new QLabel(this);
    empacadorAnimation->setMovie(empacadorGIF);
    empacadorAnimation->setGeometry(940, 250, 125, 125);
    empacadorGIF->start();
    empacadorGIF->stop();

    //FACTURADOR
    //facturadorGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Facturador-VaultBoy.gif");
    //facturadorGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Facturador-VaultBoy.gif");
    //QMovie *facturadorGIF = new QMovie("../Armazon-GUI/Images/Facturador-VaultBoy.gif");
    facturadorGIF = new QMovie("C:/Users/Fung Méndez/Desktop/Armazon-GUI/Images/Facturador-VaultBoy.gif");


    QLabel *facturadorAnimation = new QLabel(this);
    facturadorAnimation->setMovie(facturadorGIF);
    facturadorAnimation->setGeometry(1040, 50, 125, 125);
    facturadorGIF->start();
    facturadorGIF->stop();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_botonEmpezar_clicked()
{
    if (!empezado){
    empezado = true;
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
            loaderGIF->start();
            balancerGIF->start();
            fabricaAGIF->start();
            fabricaBGIF->start();
            fabricaCGIF->start(),
            fabricaCoGIF->start();
            alistador1GIF->start();
            alistador2GIF->start();
            alistador3GIF->start();
            alistador4GIF->start();
            alistador5GIF->start();
            alistador6GIF->start();
            empacadorGIF->start();
            facturadorGIF->start();
        }
        else
           qDebug()<<"No inicio ERROR en Articulos\n";
    }
    else
        qDebug()<<"No inicio ERROR en clientes\n";
    }
    else
        qDebug()<<"No hago nada\n";
}

void MainWindow::on_btnPausar_todo_clicked()
{
    loader->pausado = true;
    balancer->pause();
    bodega->pause();
    bodega->a1->pause();
    bodega->a2->pause();
    bodega->a3->pause();
    bodega->a4->pause();
    bodega->a5->pause();
    bodega->a6->pause();
    empacador->pause();
    facturador->pausa = true;
    verificarPedido->pause();
    f1->pause();
    f2->pause();
    f3->pause();
    fComodin->pause();
    loader->actualizarInventario();
    qDebug()<<"Inventario actualizado";

    loaderGIF->stop();
    balancerGIF->stop();
    fabricaAGIF->stop();
    fabricaBGIF->stop();
    fabricaCGIF->stop(),
    fabricaCoGIF->stop();
    alistador1GIF->stop();
    alistador2GIF->stop();
    alistador3GIF->stop();
    alistador4GIF->stop();
    alistador5GIF->stop();
    alistador6GIF->stop();
    empacadorGIF->stop();
    facturadorGIF->stop();
}

void MainWindow::on_btnReanudar_todo_clicked()
{
    loader->pausado = false;
    balancer->resume();
    bodega->resume();
    bodega->a1->resume();
    bodega->a2->resume();
    bodega->a3->resume();
    bodega->a4->resume();
    bodega->a5->resume();
    bodega->a6->resume();
    empacador->resume();
    verificarPedido->resume();
    f1->resume();
    f2->resume();
    f3->resume();
    fComodin->resume();
    facturador->pausa = false;

    loaderGIF->start();
    balancerGIF->start();
    fabricaAGIF->start();
    fabricaBGIF->start();
    fabricaCGIF->start(),
    fabricaCoGIF->start();
    alistador1GIF->start();
    alistador2GIF->start();
    alistador3GIF->start();
    alistador4GIF->start();
    alistador5GIF->start();
    alistador6GIF->start();
    empacadorGIF->start();
    facturadorGIF->start();
}

// Loader
void MainWindow::on_botonPausar_clicked(){
    loader->pausado = true;
    loaderGIF->stop();
}

void MainWindow::on_botonReanudar_clicked(){
    loader->pausado = false;
    loaderGIF->start();
}

// Balancer
void MainWindow::on_btnPausar_Balancer_clicked(){
    balancer->pause();
    balancerGIF->stop();
}

void MainWindow::on_btnReanudar_Balancer_clicked(){
    balancer->resume();
    balancerGIF->start();
}

// Fabricas
void MainWindow::on_btnF1_pausar_clicked(){
    f1->pause();
    fabricaAGIF->stop();
}

void MainWindow::on_btnF1_reanudar_clicked(){
    f1->resume();
    fabricaAGIF->start();
}

void MainWindow::on_btnF2_pausar_clicked(){
    f2->pause();
    fabricaBGIF->stop();
}

void MainWindow::on_btnF2_reanudar_clicked(){
    f2->resume();
    fabricaBGIF->start();
}

void MainWindow::on_btnF3_pausar_clicked(){
    f3->pause();
    fabricaCGIF->stop();
}

void MainWindow::on_btnF3_reanudar_clicked(){
    f3->resume();
    fabricaCGIF->start();
}

void MainWindow::on_btnF4_pausar_clicked(){
    fComodin->pause();
    fabricaCoGIF->stop();
}

void MainWindow::on_btnF4_reanudar_clicked(){
    fComodin->resume();
    fabricaCoGIF->start();
}

// Alistadores

void MainWindow::on_BtnA1_pausar_clicked(){
    bodega->a1->pause();
    alistador1GIF->stop();
}

void MainWindow::on_BtnA1_reanudar_clicked(){
    bodega->a1->resume();
    alistador1GIF->start();
}

void MainWindow::on_BtnA2_pausar_clicked(){
    bodega->a2->pause();
    alistador2GIF->stop();
}

void MainWindow::on_BtnA2_reanudar_clicked(){
    bodega->a2->resume();
    alistador2GIF->start();
}

void MainWindow::on_BtnA3_pausar_clicked(){
    bodega->a3->pause();
    alistador3GIF->stop();
}

void MainWindow::on_BtnA3_reanudar_clicked(){
    bodega->a3->resume();
    alistador3GIF->start();
}

void MainWindow::on_BtnA4_pausar_clicked(){
    bodega->a4->pause();
    alistador4GIF->stop();
}

void MainWindow::on_BtnA4_reanudar_clicked(){
    bodega->a4->resume();
    alistador4GIF->start();
}

void MainWindow::on_BtnA5_pausar_clicked(){
    bodega->a5->pause();
    alistador5GIF->stop();
}

void MainWindow::on_BtnA5_reanudar_clicked(){
    bodega->a5->resume();
    alistador5GIF->start();
}

void MainWindow::on_BtnA6_pausar_clicked(){
    bodega->a6->pause();
    alistador6GIF->stop();
}

void MainWindow::on_BtnA6_reanudar_clicked(){
    bodega->a6->resume();
    alistador6GIF->start();
}

// Empacador
void MainWindow::on_BtnEmpacado_pausar_clicked(){
    empacador->pause();
    empacadorGIF->stop();
}

void MainWindow::on_BtnEmpacado_reanudar_clicked(){
    empacador->resume();
    empacadorGIF->start();
}


void MainWindow::on_BtnFacturador_pausar_clicked(){
    facturador->pausa = true;
    facturadorGIF->stop();
}

void MainWindow::on_BtnFacturador_reanudar_clicked(){
    facturador->pausa = false;
    facturadorGIF->start();
}
