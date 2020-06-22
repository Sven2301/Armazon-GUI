#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loaderthread.h"
#include "balancer.h"
#include "fabricas.h"
#include "isPedidoCompleto.h"
#include "alistadores.h"
#include "bodegaAlisto.h"
#include "empacador.h"
#include "facturador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoaderThread * loader;
    QMutex mutexColaPedidos;
    QMutex mutexColaPedidosP;

    Balancer * balancer;
    Fabrica * f1, *f2, *f3, *fComodin;
    PedidoCompletado * verificarPedido;
    BodegaAlisto * bodega;
    Empacador * empacador;
    Facturador *facturador;
    bool empezado = false;

    QMovie *loaderGIF;
    QMovie *fabricaAGIF;
    QMovie *balancerGIF;
    QMovie *fabricaBGIF;
    QMovie *fabricaCGIF;
    QMovie *fabricaCoGIF;
    QMovie *alistador1GIF;
    QMovie *alistador2GIF;
    QMovie *alistador3GIF;
    QMovie *alistador4GIF;
    QMovie *alistador5GIF;
    QMovie *alistador6GIF;
    QMovie *empacadorGIF;
    QMovie *facturadorGIF;


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_botonEmpezar_clicked();

    void on_botonPausar_clicked();

    void on_botonReanudar_clicked();

    void on_btnPausar_Balancer_clicked();

    void on_btnReanudar_Balancer_clicked();

    void on_btnPausar_todo_clicked();

    void on_btnReanudar_todo_clicked();

    void on_btnF1_pausar_clicked();
    void on_btnF1_reanudar_clicked();
    void on_btnF2_pausar_clicked();
    void on_btnF2_reanudar_clicked();
    void on_btnF3_pausar_clicked();
    void on_btnF3_reanudar_clicked();
    void on_btnF4_pausar_clicked();
    void on_btnF4_reanudar_clicked();

    void on_BtnA1_pausar_clicked();
    void on_BtnA1_reanudar_clicked();
    void on_BtnA2_pausar_clicked();
    void on_BtnA2_reanudar_clicked();
    void on_BtnA3_pausar_clicked();
    void on_BtnA3_reanudar_clicked();
    void on_BtnA4_pausar_clicked();
    void on_BtnA4_reanudar_clicked();
    void on_BtnA5_pausar_clicked();
    void on_BtnA5_reanudar_clicked();
    void on_BtnA6_pausar_clicked();
    void on_BtnA6_reanudar_clicked();

    void on_BtnEmpacado_pausar_clicked();

    void on_BtnEmpacado_reanudar_clicked();

    void on_BtnFacturador_pausar_clicked();

    void on_BtnFacturador_reanudar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
