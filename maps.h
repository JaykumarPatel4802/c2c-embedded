#ifndef MAPS_H
#define MAPS_H

#include <QDialog>

namespace Ui {
class Maps;
}

class Maps : public QDialog
{
    Q_OBJECT

public:
    explicit Maps(QWidget *parent = nullptr);
    ~Maps();

private slots:
    void on_backFM_clicked();

private:
    Ui::Maps *ui;
};

#endif // MAPS_H
