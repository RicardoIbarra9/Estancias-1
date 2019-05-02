#include <QApplication>
 #include <QHBoxLayout>
 #include "dragwidget.h"

 int main(int argc, char *argv[])
 {
     //Q_INIT_RESOURCE(draggableicons);

     QApplication app(argc, argv);

     QWidget mainWidget;
     QHBoxLayout *horizontalLayout = new QHBoxLayout;
     horizontalLayout->addWidget(new DragWidget);
     horizontalLayout->addWidget(new DragWidget);

     mainWidget.setLayout(horizontalLayout);
     mainWidget.setWindowTitle(QObject::tr("draggableicons"));
 #ifdef Q_OS_SYMBIAN
     mainWidget.showMaximized();
 #else
     mainWidget.show();
 #endif

     return app.exec();
}
