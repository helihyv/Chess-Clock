#include <QtGui/QApplication>
#include <QtDeclarative>
#include "classes/wrappedclockswidget.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<WrappedClocksWidget>("ChessClocks", 1, 0, "WrappedClocksWidget");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:/qml/main.qml"));
    view.showFullScreen();
    return app.exec();
}
