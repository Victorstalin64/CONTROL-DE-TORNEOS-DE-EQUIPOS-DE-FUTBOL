#include "updateequipo.h"
#include "ui_updateequipo.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>

updateequipo::updateequipo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateequipo)
{
    ui->setupUi(this);
}

updateequipo::~updateequipo()
{
    delete ui;
}

// BUSCAR: Lee el archivo para encontrar los datos actuales
void updateequipo::on_btnBuscar_clicked()
{
    QString idABuscar = ui->lineEditBuscarId->text();
    if(idABuscar.isEmpty()){
        QMessageBox::warning(this,"Error","Ingrese un ID para buscar");
        return;
    }

    QFile archivo("equipos.txt");
    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this,"Error","No se encontró el archivo equipos.txt");
        return;
    }

    QTextStream in(&archivo);
    bool encontrado = false;
    while(!in.atEnd()){
        QString linea = in.readLine();
        QStringList datos = linea.split(","); // Asumiendo que separas por comas

        if(datos.size() >= 5 && datos[0] == idABuscar){
            ui->lineEditNuevoId->setText(datos[0]);
            ui->lineEditNuevoNombre->setText(datos[1]);
            ui->lineEditNuevaCiudad->setText(datos[2]);
            ui->lineEditNuevoDT->setText(datos[3]);
            ui->spinBoxPuntos->setValue(datos[4].toInt());
            encontrado = true;
            break;
        }
    }
    archivo.close();

    if(!encontrado) {
        QMessageBox::warning(this,"Error","ID no encontrado");
    }
}

// ACTUALIZAR: Reescribe el archivo con el cambio
void updateequipo::on_Actualizar_clicked()
{
    QString idOriginal = ui->lineEditBuscarId->text();
    QString nuevoId = ui->lineEditNuevoId->text();
    QString nombre = ui->lineEditNuevoNombre->text();
    QString ciudad = ui->lineEditNuevaCiudad->text();
    QString dt = ui->lineEditNuevoDT->text();
    QString puntos = QString::number(ui->spinBoxPuntos->value());

    if(nuevoId.isEmpty() || nombre.isEmpty()){
        QMessageBox::warning(this,"Error","Complete los campos");
        return;
    }

    QFile archivo("equipos.txt");
    QStringList lineas;
    bool modificado = false;

    // 1. Leer todo el archivo y guardar los cambios en una lista
    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&archivo);
        while(!in.atEnd()){
            QString linea = in.readLine();
            QStringList datos = linea.split(",");
            if(datos.size() >= 1 && datos[0] == idOriginal){
                // Esta es la línea que cambiamos
                lineas.append(nuevoId + "," + nombre + "," + ciudad + "," + dt + "," + puntos);
                modificado = true;
            } else {
                lineas.append(linea); // Las demás quedan igual
            }
        }
        archivo.close();
    }

    // 2. Sobrescribir el archivo con la lista actualizada
    if(modificado && archivo.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
        QTextStream out(&archivo);
        for(const QString &l : lineas){
            out << l << "\n";
        }
        archivo.close();
        QMessageBox::information(this,"Éxito","Equipo actualizado en el archivo");
    } else {
        QMessageBox::warning(this,"Error","No se pudo actualizar el archivo");
    }
}

void updateequipo::on_btnCancelar_clicked()
{
    this->close();
}
