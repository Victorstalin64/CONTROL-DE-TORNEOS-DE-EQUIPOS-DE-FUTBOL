#include "visualizar.h"
#include "ui_visualizar.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidgetItem>

Visualizar::Visualizar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Visualizar)
{
    ui->setupUi(this);
    // Aplicar una imagen de fondo
    this->setStyleSheet("QWidget { "
                        "background-image: url(:/fondoCrear.png);"
                        "background-position: center;"
                        "background-repeat: no-repeat;"
                        "}");
}

Visualizar::~Visualizar()
{
    delete ui;
}

void Visualizar::on_btnCargar_clicked()
{
    // Limpiamos la tabla para que no se dupliquen los datos si pulsas varias veces
    ui->tableWidget->setRowCount(0);

    QFile archivo("equipos.txt");

    // Intentamos abrir el archivo en modo lectura
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&archivo);

        while (!in.atEnd()) {
            QString linea = in.readLine();
            // Usamos la coma como separador, tal como hizo Víctor
            QStringList datos = linea.split(",");

            // Verificamos que la línea tenga los 5 campos esperados
            if (datos.size() >= 5) {
                int fila = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(fila);

                // Insertamos cada dato en su columna correspondiente
                ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(datos[0])); // ID
                ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(datos[1])); // Nombre
                ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(datos[2])); // Ciudad
                ui->tableWidget->setItem(fila, 3, new QTableWidgetItem(datos[3])); // DT
                ui->tableWidget->setItem(fila, 4, new QTableWidgetItem(datos[4])); // Puntos
            }
        }
        archivo.close();
    } else {
        QMessageBox::warning(this, "Aviso", "Aún no hay equipos registrados o el archivo no existe.");
    }
}

