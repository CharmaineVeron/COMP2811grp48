//Prototype 1 - changes from Bala

#ifndef PLTL_H
#define PLTL_H

#include <QMediaPlayer>
#include <QWidget>
#include <QToolButton>
#include <QPushButton>
#include <QSlider>
#include <QStyle>
#include <QComboBox>

class PlayerTools :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools(QWidget *parent): QToolButton(parent){
        setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        setIconSize(QSize(60,50));
        setStyleSheet("border: 2px solid transparent; background-color : white; color : white;");
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
        setIconSize(QSize(60,50));
        setStyleSheet("border: 2px solid transparent; background-color : white; color : white;");
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
        setIconSize(QSize(60,50));
        setStyleSheet("border: 2px solid transparent; background-color : white; color : white");
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
        setIconSize(QSize(60,50));
        setStyleSheet("border: 2px solid transparent;background-color : white; color : white");
        connect(this, SIGNAL(released()), this, SLOT (skpclicked() ));
    }
private slots:
    void skipclicked();

signals:
    void skipclick();
};

class PlayerTools4 :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools4(QWidget *parent): QToolButton(parent){
        setIconSize(QSize(60,50));
        setStyleSheet("border: 2px solid transparent;background-color : white; color : black");
        setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
        connect(this, SIGNAL(released()), this, SLOT (rewclicked() ));
    }
private slots:
    void rewclicked();

signals:
    void rewclick();
};

class PlayerTools5 :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools5(QWidget *parent): QToolButton(parent){
        setIconSize(QSize(60,50));
        setStyleSheet("border: 2px solid transparent;background-color : white; color : black;");
        setIcon(style()->standardIcon(QStyle::SP_FileIcon));
        connect(this, SIGNAL(released()), this, SLOT (rewclicked() ));

        connect(this, SIGNAL(click()), this, SLOT(filclicked()));
    }
private slots:
    void filclicked();

signals:
    void filclick();
};

class PlayerTools6 :public QPushButton
{
    Q_OBJECT

public:
    PlayerTools6(QWidget *parent): QPushButton(parent){
        setIconSize(QSize(60,50));
//        setText("Brightness");
//        setStyleSheet("border: 2px solid transparent;background-color : white; color : black");

    }
};

class PlayerTools7 :public QToolButton
{
    Q_OBJECT

public:
    PlayerTools7(QWidget *parent): QToolButton(parent){

        setStyleSheet("border: 2px solid transparent;background-color : white; color : white");
        setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        setIconSize(QSize(60,50));
    }
};




#endif // PLTL_H
