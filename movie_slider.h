//Prototype 1 - changes from Oleh

#ifndef MOVIE_SLIDER_H
#define MOVIE_SLIDER_H

#include <QWidget>

class QSlider;
class QLCDNumber;

class MovieSlider : public QWidget
{
    Q_OBJECT
public:
    MovieSlider(QWidget* = 0);
    //charmaine
    //void setNumDigits(int n);

signals:
    void timestampChanged(qint64 timestamp);
    void retimestamp(int timestamp1);

public slots:
    void intChanged(int intvalue);
    void durChanged(qint64 rawduration);
    void videoMoved(qint64 rawduration);

private:
    QLCDNumber* time;
    QSlider* slider;
    QLCDNumber* duration;
};


#endif // MOVIE_SLIDER_H
