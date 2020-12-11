//Prototype 1 - changes from Bala

#include "pltl.h"

#include <QBoxLayout>
#include <QSlider>
#include <QStyle>
#include <QToolButton>
#include <QComboBox>
#include <QWidget>


void PlayerTools::paclicked() {
    emit pauseclick();
}

void PlayerTools::plclicked() {
    emit playclick();
}

