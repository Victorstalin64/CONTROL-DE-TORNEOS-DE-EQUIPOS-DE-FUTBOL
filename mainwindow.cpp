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
