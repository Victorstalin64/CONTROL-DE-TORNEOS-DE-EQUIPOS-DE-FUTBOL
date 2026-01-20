#ifndef CREAR_H
#define CREAR_H

#include <QDialog>

namespace Ui {
class crear;
}

class crear : public QDialog
{
    Q_OBJECT

public:
    explicit crear(QWidget *parent = nullptr);
    ~crear();

private:
    Ui::crear *ui;
};

#endif // CREAR_H
