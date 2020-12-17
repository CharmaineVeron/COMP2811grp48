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

void PlayerTools1::plclicked() {
    emit playclick();
}

void PlayerTools2::stpclicked() {
    emit stopclick();
}

void PlayerTools3::skipclicked() {
    emit skipclick();
}

void PlayerTools4::rewclicked() {
    emit rewclick();
}

void PlayerTools5::filclicked() {
    emit filclick();
}
