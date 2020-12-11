#include "fullscreen.h"
#include <QKeyEvent>
#include <QKeyEventTransition>

void VideoWidget::full(){
//        qDebug("Maximize");
        setFullScreen(true);
}

void VideoWidget::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Escape){
        setFullScreen(false);
    }
}

//void VideoWidget::charmaine(){
//    //setMaximumSize(1,1);
//    //setGeometry(-1,-1,-1,-1);
//}
