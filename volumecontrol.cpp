#include "volumecontrol.h"
#include "ui_volumecontrol.h"
#include "mainwindow.h"

static MainWindow *mainWindow;

static int volumeControlValue = 0;

VolumeControl::VolumeControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VolumeControl)
{
    ui->setupUi(this);
    ui->progressBar->setValue(volumeControlValue);
    ui->horizontalSlider->setValue(volumeControlValue);
}

VolumeControl::~VolumeControl()
{
    delete ui;
}

void VolumeControl::on_backFVC_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void VolumeControl::on_horizontalSlider_valueChanged(int value)
{
    volumeControlValue = value;
    ui->progressBar->setValue(value);
}


