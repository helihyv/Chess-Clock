/**************************************************************************

   Chess Clock

   This file is part of Chess Clock software.

   (This file) Copyright (c) Heli Hyvättinen 2011

   Chess Clock is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Chess Clock is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.


**************************************************************************/

#include <QtGui/QApplication>
#include <QtDeclarative>
#include "classes/wrappedclockswidget.h"
#include "classes/settings.h"


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("Chess Clock");
    app.setOrganizationName("Chess Clock");

    app.setStyleSheet("* {color: white}");

    qmlRegisterType<WrappedClocksWidget>("ChessClocks", 1, 0, "WrappedClocksWidget");
    qmlRegisterType<Settings>("ChessClocks", 1, 0, "Settings");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:/qml/main.qml"));

    view.showFullScreen();
    return app.exec();
}
