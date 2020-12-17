//
// Created by twak on 11/11/2019.
//

#include "the_button.h"
#include <QFileDevice>
#include <QFileDialog>
#include <QFile>
#include <string>
#include <QPushButton>

void TheButton::init(TheButtonInfo* i) {
    setIcon( *(i->icon) );
    //setText( i->filename);
    //setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    info =  i;
}


void TheButton::clicked() {
    emit jumpTo(info);
}

//void TheButton::setOpenFileName()
//{
//    QFileDialog::Options options;

//    QString selectedFilter;

//    QString fileName = QFileDialog::getOpenFileName(this,
//                                tr("Select a Blaster File)"),
//                                this->text(),
//                                tr("/Users/user/Desktop/2811_cw3/videos"),
//                                &selectedFilter,
//                                options);
//    if (!fileName.isEmpty())
//        this->setText(QFileInfo(fileName).fileName());


//}
