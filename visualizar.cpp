#include "visualizar.h"
#include "ui_visualizar.h"

Visualizar::Visualizar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Visualizar)
{
    ui->setupUi(this);
}

Visualizar::~Visualizar()
{
    delete ui;
}
