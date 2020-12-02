//#include "responsive_layout.h"
//#include <iostream>
//#include <QApplication>
//#include <QScrollArea>

//using namespace std;

//// you should probably make extensive changes to this function

//void ResponsiveLayout::setGeometry(const QRect &r) {

//    QLayout::setGeometry(r);
//    int j=0,resultY=12,resultX=12,count=1;
//    float w=1200;
//    for (int i = 0; i < list_.size(); i++) {
//        QLayoutItem *o = list_.at(i);


//        try {
//            // cast the widget to one of our responsive labels
//            *label = static_cast<ResponsiveLabel *>(o->widget());
//            if (label == NULL) // null: cast failed on pointer
//                cout << "warning, unknown widget class in layout" << endl;
//            else if (label->text() == kScroll){
//                QScrollArea *scroll = new QScrollArea();
//                label -> setGeometry(0, 0, r.width(), r.height());
//                scroll->setWidget(o->widget());
//            }
//            else if (label->text() == kNavTabs) label -> setGeometry(NavX, 3*kS, NavW-kS, NavH);
//            else if (label-> text() == kShoppingBasket)label -> setGeometry(BagX+kS, BagY, BagW-6*kS, BagH);
//            else if (label-> text() == kSignIn) //SignIn always next to Bag (same row)
//                label -> setGeometry(r.width()-BagW-SignW-kS, BagY, SignW, BagH);
//            else if (label-> text() == kHomeLink) label -> setGeometry(HomeX, HomeY, HomeW, HomeH);
//            else if (label-> text() == kSearchText) label -> setGeometry(SearchX, Row2, SearchW, Row2H);
//            else if (label-> text() == kSearchButton) label -> setGeometry(ButX, Row2+kS,ButW, Row2H-2*kS);
//            else if (label->text() == kSearchOptions) label -> setGeometry(OptX, OptY, OptW, OptH);
//            else if (label->text() == kAdvert){ //Different amounts of Ads depend on window
//                if(j+AdH>r.height()) AdX = r.width();
//                label-> setGeometry(AdX, Row3+j, AdW, AdH);
//                if (r.width()>=740) j+=AdH+2*kS;
//           }
//            else if (label->text() == kSearchResult){ //Different amounts of results depend on window
//                count++;
//                if(r.width()>=500){
//                    label-> setGeometry(resultX, resultY, (r.width()-45)*0.5, (r.width()-45)*0.5);
//                    if ((resultX+(r.width()-45)*0.5+38)>r.width()){
//                        resultY+=((r.width()-45)*0.5+4*kS);
//                        resultX=12;
//                    }else
//                        resultX+=(r.width()-45)*0.5+4*kS;
//                    if (count==18)
//                        resultY+=((r.width()-45)*0.5+4*kS);
//                }else{
//                    label-> setGeometry(resultX, resultY, (r.width()-45), (r.width()-45));
//                    resultY+=((r.width()-45)+4*kS);//, Rcount = ResX;
//                }
//            }
//            else if (label->text() == kSearchBackward)
//                label ->setGeometry(12,resultY,directW, directW); //r.height()-directW-2*kS
//            else if (label->text() == kSearchForward)
//                label ->setGeometry(r.width()-72,resultY,directW, directW);
//            else // otherwise: disappear label by moving out of bounds
//                label -> setGeometry (-1,-1,0,0);
//        }
//        catch (bad_cast) {
//            // bad_case: cast failed on reference...
//            cout << "warning, unknown widget class in layout" << endl;
//        }
//    }



//}


//// following methods provide a trivial list-based implementation of the QLayout class
//int ResponsiveLayout::count() const {
//    return list_.size();
//}

//QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
//    return list_.value(idx);
//}

//QLayoutItem *ResponsiveLayout::takeAt(int idx) {
//    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
//}

//void ResponsiveLayout::addItem(QLayoutItem *item) {
//    list_.append(item);
//}

//QSize ResponsiveLayout::sizeHint() const {
//    return minimumSize();
//}

//QSize ResponsiveLayout::minimumSize() const {
//    return QSize(320,320);
//}

//ResponsiveLayout::~ResponsiveLayout() {
//    QLayoutItem *item;
//    while ((item = takeAt(0)))
//        delete item;
//}
