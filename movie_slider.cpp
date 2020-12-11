//Prototype 1 - changes from Oleh

#include "movie_slider.h"
#include <QtWidgets>


MovieSlider::MovieSlider(QWidget *parent) : QWidget(parent)
{
    time = new QLCDNumber();
    time->setDigitCount(2); //char
    time->setStyleSheet("border: 1px solid transparent"); //char
    slider = new QSlider(Qt::Horizontal);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(intChanged(int)));
    slider->setStyleSheet("border: 2px solid transparent");
    duration = new QLCDNumber();
    duration->setStyleSheet("border: 1px solid transparent"); //c
    duration->setDigitCount(2); //char
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(time);
    layout->addWidget(slider);
    layout->addWidget(duration);
    setLayout(layout);

    connect(this, SIGNAL(retimestamp(int)), slider, SLOT(setValue(int)));

}

void MovieSlider::durChanged(qint64 rawduration){
    slider->setRange(0, rawduration);
    duration->display(static_cast<int>(rawduration / 1000));
}

void MovieSlider::intChanged(int intvalue){
    qint64 newtimestamp = static_cast<qint64>(intvalue);
    emit timestampChanged(newtimestamp);
}

void MovieSlider::videoMoved(qint64 rawduration1){
    int newtime = static_cast<int>(rawduration1 / 1000);
    time->display(newtime);
    emit retimestamp(static_cast<int>(rawduration1));
}



