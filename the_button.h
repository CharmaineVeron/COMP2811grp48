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
    QString filename;

    TheButtonInfo ( QUrl* url, QIcon* icon, QString  filename) : url (url), icon (icon), filename (filename) {}
};


class TheButton : public QToolButton {
    Q_OBJECT

public:
    TheButtonInfo* info;

     TheButton(QWidget *parent) :  QToolButton(parent) {
//         setToolButtonStyle(Qt::);
         //setText()
         setIconSize(QSize(210,130)); //200,110 //320,180

         //setIconSize(Qt::re)
         connect(this, SIGNAL(released()), this, SLOT (clicked() )); // if QPushButton clicked...then run clicked() below
    }

    void init(TheButtonInfo* i);
    //void setOpenFileName();

private slots:
    void clicked();

signals:
    void jumpTo(TheButtonInfo*);

};

#endif //CW2_THE_BUTTON_H
