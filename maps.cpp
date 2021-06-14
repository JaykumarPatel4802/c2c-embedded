#include "maps.h"
#include "ui_maps.h"
#include "mainwindow.h"
#include <QPixmap>

static MainWindow *mainWindow;

Maps::Maps(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Maps)
{
    ui->setupUi(this);

    // QPixmap pix("/home/pi/Documents/Austin.png");    // This is going to be done using resource
    QPixmap pix(":/resources/img/Austin.png");
    int label_width = ui->label->width();
    int label_height = ui->label->height();
    ui->label->setPixmap(pix.scaled(label_width, label_height, Qt::KeepAspectRatio));

}

Maps::~Maps()
{
    delete ui;
}

void Maps::on_backFM_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}
