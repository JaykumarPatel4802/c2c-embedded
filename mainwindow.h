#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wiringPi.h"

#include "volumecontrol.h"
#include "about.h"
#include "maps.h"
#include "interiorlights.h"
#include "lightbrightness.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void headlights_button_pressed();

private slots:
    void on_headlights_clicked();

    void on_volume_control_clicked();

    void on_about_clicked();

    void on_maps_clicked();

    void on_interior_lights_clicked();

    void on_light_brightness_clicked();


private:
    Ui::MainWindow *ui;
    VolumeControl *volumeControl;
    About *about;
    Maps *maps;
    InteriorLights *interiorLights;
    LightBrightness *lightBrightness;

    void static buttonInterrupt(Ui::MainWindow *ui);

};

#endif // MAINWINDOW_H
