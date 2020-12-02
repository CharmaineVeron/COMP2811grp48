//Prototype 1 - changes from Bala

#ifndef PLTL_H
#define PLTL_H

#include <QMediaPlayer>
#include <QWidget>
#include <QToolButton>
#include <QSlider>
#include <QStyle>
#include <QComboBox>

class PlayerTools :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools(QWidget *parent): QToolButton(parent){
        setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        connect(this, SIGNAL(released()), this, SLOT (paclicked() ));
    }
private slots:
    void paclicked();
    void plclicked();

signals:
    void pauseclick();
    void playclick();


};



#endif // PLTL_H
