#include "interiorlights.h"
#include "ui_interiorlights.h"
#include "mainwindow.h"

static MainWindow *mainWindow;

static int frontLightPin = 25;
static int midLightPin = 26;
static int backLightPin = 27;

static bool frontLightsStatus = false;
static bool midLightsStatus = false;
static bool backLightsStatus = false;

InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
    ui->setupUi(this);

    wiringPiSetupGpio();
    pinMode(frontLightPin, OUTPUT);
    pinMode(midLightPin, OUTPUT);
    pinMode(backLightPin, OUTPUT);

    ui->frontLights->setChecked(frontLightsStatus);
    ui->midLights->setChecked(midLightsStatus);
    ui->backLights->setChecked(backLightsStatus);


}

InteriorLights::~InteriorLights()
{
    delete ui;
}

void InteriorLights::on_frontLights_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        frontLightsStatus = false;
        digitalWrite(frontLightPin, LOW);
    }
    else
    {
        frontLightsStatus = true;
        digitalWrite(frontLightPin, HIGH);
    }
}

void InteriorLights::on_midLights_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        midLightsStatus = false;
        digitalWrite(midLightPin, LOW);
    }
    else
    {
        midLightsStatus = true;
        digitalWrite(midLightPin, HIGH);
    }

}

void InteriorLights::on_backLights_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        backLightsStatus = false;
        digitalWrite(backLightPin, LOW);
    }
    else
    {
        backLightsStatus = true;
        digitalWrite(backLightPin, HIGH);
    }

}

void InteriorLights::on_backFIL_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}
