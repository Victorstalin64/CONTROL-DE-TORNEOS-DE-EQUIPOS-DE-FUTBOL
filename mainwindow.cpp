#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "crear.h"
#include "visualizar.h"   // Asegúrate de que este archivo se llame así
#include "eliminarequipo.h"
#include "updateequipo.h"

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

// Botón CREAR
void MainWindow::on_Crear_clicked()
{
    crear *v = new crear(this);
    v->setAttribute(Qt::WA_DeleteOnClose);
    v->setModal(true);
    v->show();
}

// Botón LEER / MOSTRAR
void MainWindow::on_Leer_clicked()
{
    Visualizar *ventana = new Visualizar();
    ventana->setAttribute(Qt::WA_DeleteOnClose);
    ventana->setWindowModality(Qt::ApplicationModal);
    ventana->show();
}

// Botón ELIMINAR (Asegúrate que el botón en el .ui se llame "Eliminar")
void MainWindow::on_Eliminar_clicked()
{
    eliminarequipo *ventanaE = new eliminarequipo(this);
    ventanaE->setWindowFlags(Qt::Window);
    ventanaE->setAttribute(Qt::WA_DeleteOnClose);
    ventanaE->show();
}

// Botón ACTUALIZAR (Asegúrate que el botón en el .ui se llame "Actualizar")
void MainWindow::on_Actualizar_clicked()
{
    updateequipo *ventanaU = new updateequipo(this);
    ventanaU->setWindowFlags(Qt::Window);
    ventanaU->setAttribute(Qt::WA_DeleteOnClose);
    ventanaU->show();
}
