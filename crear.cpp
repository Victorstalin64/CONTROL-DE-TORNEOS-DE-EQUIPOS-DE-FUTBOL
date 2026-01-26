#include "crear.h"
#include "ui_crear.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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

void crear::on_toolButton_clicked()
{
    //Obtener los datos
    QString id = ui->lineEdit_id->text();
    QString nombre = ui->lineEdit_nombre->text();
    QString ciudad = ui->lineEdit_ciudad->text();
    QString dt = ui->lineEdit_dt->text();
    QString puntosStr = ui->lineEdit_puntos->text();

    // Validacion para campos vacío
    if(id.isEmpty() || nombre.isEmpty() || ciudad.isEmpty() || dt.isEmpty() || puntosStr.isEmpty()){
        QMessageBox::warning(this, "Error", "Por favor, llene todos los campos.");
        return;
    }

    //Puntos mayor o igual a 0
    int puntos = puntosStr.toInt();
    if(puntos < 0){
        QMessageBox::warning(this, "Error", "Los puntos deben ser mayor o igual a 0.");
        return;
    }

    //ID unico y guradar en archivos
    QFile archivo("equipos.txt");

    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&archivo);
        while (!in.atEnd()) {
            QString linea = in.readLine();
            QStringList datos = linea.split(",");
            if (datos.size() > 0 && datos[0] == id) {
                QMessageBox::warning(this, "Error", "El ID ya existe. Use uno diferente.");
                archivo.close();
                return;
            }
        }
        archivo.close();
    }

    if (archivo.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&archivo);
        out << id << "," << nombre << "," << ciudad << "," << dt << "," << puntos << "\n";
        archivo.close();

        QMessageBox::information(this, "Éxito", "Equipo guardado correctamente.");

        ui->lineEdit_id->clear();
        ui->lineEdit_nombre->clear();
        ui->lineEdit_ciudad->clear();
        ui->lineEdit_dt->clear();
        ui->lineEdit_puntos->clear();
    } else {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo para guardar.");
    }
}

