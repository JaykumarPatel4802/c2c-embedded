#ifndef LIGHTBRIGHTNESS_H
#define LIGHTBRIGHTNESS_H

#include <QDialog>

namespace Ui {
class LightBrightness;
}

class LightBrightness : public QDialog
{
    Q_OBJECT

public:
    explicit LightBrightness(QWidget *parent = nullptr);
    ~LightBrightness();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::LightBrightness *ui;
};

#endif // LIGHTBRIGHTNESS_H
