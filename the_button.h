//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_BUTTON_H
#define CW2_THE_BUTTON_H


#include <QPushButton>
#include <QToolButton>
#include <QUrl>
#include <QFileInfo>

class TheButtonInfo {

public:
    QUrl* url; // video file to play
    QIcon* icon; // icon to display



    TheButtonInfo ( QUrl* url, QIcon* icon) : url (url), icon (icon) {}
};


class TheButton : public QPushButton {
    Q_OBJECT

public:
    TheButtonInfo* info;

     TheButton(QWidget *parent) :  QPushButton(parent) {
//         setToolButtonStyle(Qt::);
         //setText("hi");
         setText(QFileInfo().fileName());
         setIconSize(QSize(320,180)); //200,110        
         connect(this, SIGNAL(released()), this, SLOT (clicked() )); // if QPushButton clicked...then run clicked() below
    }

    void init(TheButtonInfo* i);
    void setOpenFileName();

private slots:
    void clicked();

signals:
    void jumpTo(TheButtonInfo*);

};

#endif //CW2_THE_BUTTON_H
