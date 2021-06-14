#include "lightbrightness.h"
#include "ui_lightbrightness.h"
#include "mainwindow.h"

static MainWindow *mainWindow;

static int lightBrightnessValue = 0;

LightBrightness::LightBrightness(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LightBrightness)
{
    ui->setupUi(this);

    ui->progressBar->setValue(lightBrightnessValue);
    ui->horizontalSlider->setValue(lightBrightnessValue);
}

LightBrightness::~LightBrightness()
{
    delete ui;
}

void LightBrightness::on_pushButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void LightBrightness::on_horizontalSlider_valueChanged(int value)
{
    lightBrightnessValue = value;
    ui->progressBar->setValue(value);
}
