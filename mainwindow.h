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


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_botonEmpezar_clicked();

    void on_botonPausar_clicked();

    void on_botonReanudar_clicked();

    void on_btnPausar_Balancer_clicked();

    void on_btnReanudar_Balancer_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
