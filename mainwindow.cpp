#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "crear.h"

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

void MainWindow::on_Crear_clicked()
{
    crear *v = new crear(this);

    v->setAttribute(Qt::WA_DeleteOnClose);
    v->setModal(true);
    v->show();
}

void MainWindow::on_Leer_clicked()
{
    // Al quitar el "this" o pasarle 0, la ventana se vuelve independiente
    Visualizar *ventana = new Visualizar();

    // Esto asegura que la ventana se borre de la memoria al cerrarla
    ventana->setAttribute(Qt::WA_DeleteOnClose);

    // Esto la hace "Modal" (opcional): impide tocar la ventana de atrás hasta cerrar esta
    ventana->setWindowModality(Qt::ApplicationModal);

    ventana->show();

}

