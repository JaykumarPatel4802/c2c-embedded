#include "mainwindow.h"
#include "ui_mainwindow.h"

static int headLightPin = 12;

enum headLightsStatus { On = 1, Off = 0};
// can also do "enum headLightsStatus { Off, On }
static headLightsStatus headLightsValue = Off;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(headlights_button_pressed()), this, SLOT(on_headlights_clicked()));

    wiringPiSetupGpio();
    wiringPiISR(21, INT_EDGE_RISING, &buttonInterrupt);
    pinMode(headLightPin, OUTPUT);

    if (headLightsValue == On)
    {
        ui->headlights->setStyleSheet("border-color: rgb(255, 255, 255); background-color: rgb(110, 255, 255); border-radius: 10px;");
    }
    else
    {
        ui->headlights->setStyleSheet("border-color: rgb(255, 255, 255); background-color: rgb(138, 195, 255); border-radius: 10px;");
    }
    digitalWrite(headLightPin, headLightsValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonInterrupt(Ui::MainWindow *ui) {


    if (headLightsValue == On)
    {
        headLightsValue = Off;
        ui->headlights->setStyleSheet("border-color: rgb(255, 255, 255); background-color: rgb(138, 195, 255); border-radius: 10px;");
    }
    else
    {
        headLightsValue = On;
        ui->headlights->setStyleSheet("border-color: rgb(255, 255, 255); background-color: rgb(110, 255, 255); border-radius: 10px;");
    }
    digitalWrite(headLightPin, headLightsValue);
}

void MainWindow::on_headlights_clicked()
{
    if (headLightsValue == On)
    {
        headLightsValue = Off;
        ui->headlights->setStyleSheet("border-color: rgb(255, 255, 255); background-color: rgb(138, 195, 255); border-radius: 10px;");
    }
    else
    {
        headLightsValue = On;
        ui->headlights->setStyleSheet("border-color: rgb(255, 255, 255); background-color: rgb(110, 255, 255); border-radius: 10px;");
    }
    digitalWrite(headLightPin, headLightsValue);
}

void MainWindow::on_volume_control_clicked()
{
    hide();
    volumeControl = new VolumeControl(this);
    volumeControl->show();
}

void MainWindow::on_about_clicked()
{
    hide();
    about = new About(this);
    about->show();
}

void MainWindow::on_maps_clicked()
{
    hide();
    maps = new Maps(this);
    maps->show();
}



void MainWindow::on_interior_lights_clicked()
{
    hide();
    interiorLights = new InteriorLights(this);
    interiorLights->show();
}


void MainWindow::on_light_brightness_clicked()
{
    hide();
    lightBrightness = new LightBrightness(this);
    lightBrightness->show();
}
