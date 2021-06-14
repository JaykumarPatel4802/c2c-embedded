#ifndef INTERIORLIGHTS_H
#define INTERIORLIGHTS_H

#include <QDialog>
#include "wiringPi.h"

namespace Ui {
class InteriorLights;
}

class InteriorLights : public QDialog
{
    Q_OBJECT

public:
    explicit InteriorLights(QWidget *parent = nullptr);
    ~InteriorLights();

private slots:
    void on_frontLights_stateChanged(int arg1);

    void on_midLights_stateChanged(int arg1);

    void on_backLights_stateChanged(int arg1);

    void on_backFIL_clicked();

private:
    Ui::InteriorLights *ui;
};

#endif // INTERIORLIGHTS_H
