#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMovie>
#include <QtMultimedia/QMediaPlayer>
#include <QDesktopWidget>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// BG

    resize(QDesktopWidget().availableGeometry(this).size() * 0.90);
    //QPixmap backg("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fallout-Terminal.jpg");
    QPixmap backg("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fallout-Terminal.jpg");

    backg = backg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backg);
    this->setPalette(palette);

// GIF
    //LOADER
    //QMovie *loaderGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Loader-VaultBoy.gif");
    QMovie *loaderGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Loader-VaultBoy.gif");

    QLabel *loaderAnimation = new QLabel(this);
    loaderAnimation->setMovie(loaderGIF);
    loaderAnimation->setGeometry(0, 250, 125, 125);
    loaderGIF->start();

    //BALANCER
    //QMovie *balancerGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Balancer-VaultBoy.gif");
    QMovie *balancerGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Balancer-VaultBoy.gif");

    QLabel *balancerAnimation = new QLabel(this);
    balancerAnimation->setMovie(balancerGIF);
    balancerAnimation->setGeometry(400, 250, 125, 125);
    balancerGIF->start();

    //FABRICA A
    //QMovie *fabricaAGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    QMovie *fabricaAGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");

    QLabel *fabricaAAnimation = new QLabel(this);
    fabricaAAnimation->setMovie(fabricaAGIF);
    fabricaAAnimation->setGeometry(370, 0, 125, 125);
    fabricaAGIF->start();

    //FABRICA B
    //QMovie *fabricaBGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    QMovie *fabricaBGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");

    QLabel *fabricaBAnimation = new QLabel(this);
    fabricaBAnimation->setMovie(fabricaBGIF);
    fabricaBAnimation->setGeometry(495, 0, 125, 125);
    fabricaBGIF->start();

    //FABRICA C
    //QMovie *fabricaCGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    QMovie *fabricaCGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    QLabel *fabricaCAnimation = new QLabel(this);
    fabricaCAnimation->setMovie(fabricaCGIF);
    fabricaCAnimation->setGeometry(620, 0, 125, 125);
    fabricaCGIF->start();

    //FABRICA COMODIN
    //QMovie *fabricaCoGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");
    QMovie *fabricaCoGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Fabrica-VaultBoy.gif");

    QLabel *fabricaCoAnimation = new QLabel(this);
    fabricaCoAnimation->setMovie(fabricaCoGIF);
    fabricaCoAnimation->setGeometry(745, 0, 125, 125);
    fabricaCoGIF->start();

    //ALISTADOR 1
    //QMovie *alistador1GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    QMovie *alistador1GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador1Animation = new QLabel(this);
    alistador1Animation->setMovie(alistador1GIF);
    alistador1Animation->setGeometry(475, 520, 125, 125);
    alistador1GIF->start();

    //ALISTADOR 2
    //QMovie *alistador2GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    QMovie *alistador2GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador2Animation = new QLabel(this);
    alistador2Animation->setMovie(alistador2GIF);
    alistador2Animation->setGeometry(600, 520, 125, 125);
    alistador2GIF->start();

    //ALISTADOR 3
    //QMovie *alistador3GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    QMovie *alistador3GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador3Animation = new QLabel(this);
    alistador3Animation->setMovie(alistador3GIF);
    alistador3Animation->setGeometry(725, 520, 125, 125);
    alistador3GIF->start();

    //ALISTADOR 4
    //QMovie *alistador4GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    QMovie *alistador4GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador4Animation = new QLabel(this);
    alistador4Animation->setMovie(alistador4GIF);
    alistador4Animation->setGeometry(850, 520, 125, 125);
    alistador4GIF->start();

    //ALISTADOR 5
    //QMovie *alistador5GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    QMovie *alistador5GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador5Animation = new QLabel(this);
    alistador5Animation->setMovie(alistador5GIF);
    alistador5Animation->setGeometry(975, 520, 125, 125);
    alistador5GIF->start();

    //ALISTADOR 6
    //QMovie *alistador6GIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");
    QMovie *alistador6GIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Alistador-VaultBoy.gif");

    QLabel *alistador6Animation = new QLabel(this);
    alistador6Animation->setMovie(alistador6GIF);
    alistador6Animation->setGeometry(1100, 520, 125, 125);
    alistador6GIF->start();

    //EMPACADOR
    //QMovie *empacadorGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Empacador-VaultBoy.gif");
    QMovie *empacadorGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Empacador-VaultBoy.gif");

    QLabel *empacadorAnimation = new QLabel(this);
    empacadorAnimation->setMovie(empacadorGIF);
    empacadorAnimation->setGeometry(940, 250, 125, 125);
    empacadorGIF->start();

    //FACTURADOR
    //QMovie *facturadorGIF = new QMovie("C:/Users/sven/Documents/GitHub/Armazon-GUI/Images/Facturador-VaultBoy.gif");
    QMovie *facturadorGIF = new QMovie("C:/Users/Fung Méndez/Documents/GitHub/Armazon-GUI/Images/Facturador-VaultBoy.gif");
    QLabel *facturadorAnimation = new QLabel(this);
    facturadorAnimation->setMovie(facturadorGIF);
    facturadorAnimation->setGeometry(1040, 50, 125, 125);
    facturadorGIF->start();


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
}

// Loader
void MainWindow::on_botonPausar_clicked(){
    loader->pausado = true;
}

void MainWindow::on_botonReanudar_clicked(){
    loader->pausado = false;
}

// Balancer
void MainWindow::on_btnPausar_Balancer_clicked(){
    balancer->pause();
}

void MainWindow::on_btnReanudar_Balancer_clicked(){
    balancer->resume();
}

// Fabricas
void MainWindow::on_btnF1_pausar_clicked(){
    f1->pause();
}

void MainWindow::on_btnF1_reanudar_clicked(){
    f1->resume();
}

void MainWindow::on_btnF2_pausar_clicked(){
    f2->pause();
}

void MainWindow::on_btnF2_reanudar_clicked(){
    f2->resume();
}

void MainWindow::on_btnF3_pausar_clicked(){
    f3->pause();
}

void MainWindow::on_btnF3_reanudar_clicked(){
    f3->resume();
}

void MainWindow::on_btnF4_pausar_clicked(){
    fComodin->pause();
}

void MainWindow::on_btnF4_reanudar_clicked(){
    fComodin->resume();
}

// Alistadores

void MainWindow::on_BtnA1_pausar_clicked(){
    bodega->a1->pause();
}

void MainWindow::on_BtnA1_reanudar_clicked(){
    bodega->a1->resume();
}

void MainWindow::on_BtnA2_pausar_clicked(){
    bodega->a2->pause();
}

void MainWindow::on_BtnA2_reanudar_clicked(){
    bodega->a2->resume();
}

void MainWindow::on_BtnA3_pausar_clicked(){
    bodega->a3->pause();
}

void MainWindow::on_BtnA3_reanudar_clicked(){
    bodega->a3->resume();
}

void MainWindow::on_BtnA4_pausar_clicked(){
    bodega->a4->pause();
}

void MainWindow::on_BtnA4_reanudar_clicked(){
    bodega->a4->resume();
}

void MainWindow::on_BtnA5_pausar_clicked(){
    bodega->a5->pause();
}

void MainWindow::on_BtnA5_reanudar_clicked(){
    bodega->a5->resume();
}

void MainWindow::on_BtnA6_pausar_clicked(){
    bodega->a6->pause();
}

void MainWindow::on_BtnA6_reanudar_clicked(){
    bodega->a6->resume();
}

// Empacador
void MainWindow::on_BtnEmpacado_pausar_clicked(){
    empacador->pause();
}

void MainWindow::on_BtnEmpacado_reanudar_clicked(){
    empacador->resume();
}


void MainWindow::on_BtnFacturador_pausar_clicked(){
    facturador->pausa = true;
}

void MainWindow::on_BtnFacturador_reanudar_clicked(){
    facturador->pausa = false;
}
