/*
 *
 *    ______
 *   /_  __/___  ____ ___  ___  ____
 *    / / / __ \/ __ `__ \/ _ \/ __ \
 *   / / / /_/ / / / / / /  __/ /_/ /
 *  /_/  \____/_/ /_/ /_/\___/\____/
 *              video for sports enthusiasts...
 *
 *  2811 cw3 : twak
 */

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QScrollArea>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include "the_player.h"
#include "the_button.h"
#include "responsive_layout.h"
#include "movie_slider.h"
#include "pltl.h"
#include <QtWidgets/QSlider>
#include <QtWidgets>
#include "fsbut.h"
#include "fullscreen.h"


//Prototype 1 - changes from Oleh

using namespace std;

// read in videos and thumbnails to this directory
vector<TheButtonInfo> getInfoIn (string loc) {

    vector<TheButtonInfo> out =  vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb;
            }
            else
                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb;
        }
    }

    return out;
}


int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    vector<TheButtonInfo> videos;

    if (argc == 2)
        videos = getInfoIn( string(argv[1]) );

    if (videos.size() == 0) {

        const int result = QMessageBox::question(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! download, unzip, and add command line argument to \"quoted\" file location. Download videos from Tom's OneDrive?"),
                    QMessageBox::Yes |
                    QMessageBox::No );

        switch( result )
        {
        case QMessageBox::Yes:
          QDesktopServices::openUrl(QUrl("https://leeds365-my.sharepoint.com/:u:/g/personal/scstke_leeds_ac_uk/EcGntcL-K3JOiaZF4T_uaA4BHn6USbq2E55kF_BTfdpPag?e=n1qfuN"));
          break;
        default:
            break;
        }
        exit(-1);
    }

    // the widget that will show the video
    VideoWidget*videoWidget = new VideoWidget;

    // the QMediaPlayer which controls the playback
    ThePlayer *player = new ThePlayer;

    videoWidget->setMinimumSize(680,500);
    player->setVideoOutput(videoWidget);


    // a row of buttons
    QWidget *buttonWidget = new QWidget();
    // a list of the buttons
    vector<TheButton*> buttons;
    // the buttons are arranged vertically
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(0);
    //buttonWidget->setMinimumSize(300, 680);
    // create the four buttons
    for ( int i = 0; i <6; i++ ) {
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo* ))); // when clicked, tell the player to play.
        buttons.push_back(button);
        //button->adjustSize();
        layout->addWidget(button);
        button->init(&videos.at(i));
    }

    buttonWidget->setMinimumSize(320, 1090); //buttons.size() * 180
    buttonWidget->setLayout(layout);
    QScrollArea *scroll = new QScrollArea();
    scroll->setMinimumSize(320, 680);
    scroll->setWidgetResizable(true);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setWidget(buttonWidget);

    //Prototype 1 - changes from Bala
    QWidget *pbut = new QWidget();
    PlayerTools *pause = new PlayerTools(pbut);
    pause->connect(pause, SIGNAL(pauseclick()), player, SLOT (pauseclick()));

    //Prototype 2 - changes from Leo
    FSBUT *but1 = new FSBUT;
    but1->setText("FullScreen");
    but1->setMaximumSize(100,100);
    but1->setStyleSheet("border: 1px solid transparent; background-color : transparent; color : white;");
    but1->connect(but1, SIGNAL(clicked()),videoWidget,SLOT(full()));

    //add onto Bala's - me
    QWidget *videoOptions = new QWidget();
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(but1);
    layout2->addStretch(100);
    layout2->addWidget(pbut, Qt::AlignCenter);

    videoOptions->setMinimumSize(680, 100);
    videoOptions->setLayout(layout2);

    //Prototype 1 - changes from Oleh
    MovieSlider *mslider = new MovieSlider();
    mslider->setMinimumSize(680,70);
    MovieSlider::connect(player, SIGNAL(durationChanged(qint64)), mslider, SLOT(durChanged(qint64)));
    ThePlayer::connect(mslider, SIGNAL(timestampChanged(qint64)), player, SLOT(playat(qint64)));
    MovieSlider::connect(player, SIGNAL(positionChanged(qint64)), mslider, SLOT(videoMoved(qint64)));


    // tell the player what buttons and videos are available
    player->setContent(&buttons, & videos);

    //testing whether it is possible to achieve repsonsive layout
//    QPushButton *fd = new QPushButton();
//    fd->setMinimumSize(50,50);
//    fd->setStyleSheet("border: 1px solid red; background-color : white; color : black;");
//    fd->connect(fd,SIGNAL(clicked()),videoWidget,SLOT(charmaine()));

    // create the main window and layout
    QWidget window;
    QGridLayout *top = new QGridLayout();

    window.setLayout(top);

    window.setWindowTitle("tomeo");
    window.setMinimumSize(1500, 680);
    window.setStyleSheet("border: 1px solid transparent; background-color : skyblue; color : black;");

    // add the video and the buttons to the top level widget

    top->addWidget(videoWidget,1,1,Qt::Alignment());
    top->addWidget(mslider,2,1,Qt::Alignment());
    top->addWidget(videoOptions,3,1);
    top->addWidget(scroll,1,2,3,2);
//    top->addWidget(fd);
//    if (window.isMaximized()){
//        top->removeWidget(videoWidget);
//    }


    // showtime!
    window.show();

    // wait for the app to terminate
    return app.exec();
}
