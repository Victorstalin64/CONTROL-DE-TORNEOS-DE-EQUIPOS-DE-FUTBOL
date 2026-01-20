#include "mainwindow.h"
#include "crear.h"
#include "./ui_mainwindow.h"

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
    // Usamos 'crear' en minúsculas porque así se llama tu clase
    crear *v = new crear(this);

    v->setAttribute(Qt::WA_DeleteOnClose);
    v->setModal(true);
    v->show();
}
