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
signals:
    void pauseclick();
};

class PlayerTools1 :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools1(QWidget *parent): QToolButton(parent){
        setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        connect(this, SIGNAL(released()), this, SLOT (plclicked() ));
    }
private slots:
    void plclicked();

signals:
    void playclick();
};

class PlayerTools2 :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools2(QWidget *parent): QToolButton(parent){
        setIcon(style()->standardIcon(QStyle::SP_MediaStop));
        connect(this, SIGNAL(released()), this, SLOT (stpclicked() ));
    }
private slots:
    void stpclicked();

signals:
    void stopclick();
};

class PlayerTools3 :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools3(QWidget *parent): QToolButton(parent){
        setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
        connect(this, SIGNAL(released()), this, SLOT (skpclicked() ));
    }
private slots:
    void skipclicked();

signals:
    void skipclick();
};


#endif // PLTL_H
