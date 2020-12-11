#ifndef FSBUT_H
#define FSBUT_H

#include <QPushButton>

class FSBUT : public QPushButton
{
    Q_OBJECT

public:
    FSBUT(QWidget *parent = NULL):QPushButton(parent){
        connect(this, SIGNAL(clicked()), this, SLOT(onClicked()));
    }

};

#endif // FSBUT_H
