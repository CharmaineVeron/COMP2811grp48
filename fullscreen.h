#ifndef FULLSCREEN_H
#define FULLSCREEN_H

#include <QApplication>
#include <QMediaPlayer>
#include <vector>
#include <QMainWindow>
#include <QVideoWidget>



class VideoWidget: public QVideoWidget
{
    Q_OBJECT
public:
    VideoWidget():QVideoWidget(){};

public slots:
    void full();
    void keyPressEvent(QKeyEvent*event);
    //void charmaine();

};


#endif // FULLSCREEN_H
