#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H

#include <QDialog>

namespace Ui {
class VolumeControl;
}

class VolumeControl : public QDialog
{
    Q_OBJECT

public:
    explicit VolumeControl(QWidget *parent = nullptr);
    ~VolumeControl();

private slots:

    void on_backFVC_clicked();

    void on_horizontalSlider_valueChanged(int value);



private:
    Ui::VolumeControl *ui;
};

#endif // VOLUMECONTROL_H
