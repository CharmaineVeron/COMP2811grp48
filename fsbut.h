#ifndef FSBUT_H
#define FSBUT_H

#include <QPushButton>

class FSBUT : public QPushButton
{
    Q_OBJECT

public:
    FSBUT(QWidget *parent = NULL):QPushButton(parent){
        setIconSize(QSize(100,50));
        setStyleSheet("border: 2px solid transparent; background-color : orange; color : black;");
        connect(this, SIGNAL(clicked()), this, SLOT(onClick()));
    }

};

#endif // FSBUT_H
