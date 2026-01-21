#ifndef VISUALIZAR_H
#define VISUALIZAR_H

#include <QWidget>

namespace Ui {
class Visualizar;
}

class Visualizar : public QWidget
{
    Q_OBJECT

public:
    explicit Visualizar(QWidget *parent = nullptr);
    ~Visualizar();

private:
    Ui::Visualizar *ui;
};

#endif // VISUALIZAR_H
