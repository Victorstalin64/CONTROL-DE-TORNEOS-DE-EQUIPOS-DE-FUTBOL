#include "crear.h"
#include "ui_crear.h"

crear::crear(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::crear)
{
    ui->setupUi(this);
}

crear::~crear()
{
    delete ui;
}
