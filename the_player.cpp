//
// Created by twak on 11/11/2019.
//
//Prototype 1 - changes from Bala

#include "the_player.h"
#include "fsbut.h"
#include <QBoxLayout>
#include <QSlider>
#include <QStyle>
#include <QToolButton>
#include <QComboBox>
#include <QWidget>
#include <QDialog>


using namespace std;

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i) {
    buttons = b;
    infos = i;
    jumpTo(buttons -> at(0) -> info);
}

// change the image and video for one button every one second
void ThePlayer::shuffle() {
//    TheButtonInfo* i = & infos -> at ( updateCount % infos->size() );
//        setMedia(*i->url);
//    buttons -> at( updateCount++ % buttons->size() ) -> init( i );
}

void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (TheButtonInfo* button) {
    setMedia( * button -> url);
    play();
}

//Bala
void ThePlayer::pauseclick () {
    pause();
}


void ThePlayer::playclick () {
    play();
}

void ThePlayer::stopclick () {
    stop();
}

void ThePlayer::skipclick () {
    //next();
}

