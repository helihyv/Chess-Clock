/**************************************************************************

   Chess Clock

   This file is part of Chess Clock software.

   (This file) Copyright (c) Heli Hyvättinen 2013

   Chess Clock is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Chess Clock is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.


**************************************************************************/

#include <QApplication>
#include <QDeclarativeView>

#include <QtDeclarative>

#include "sailfishapplication.h"
#include "classes/wrappedclockswidget.h"
#include "classes/settings.h"




Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> pApp(Sailfish::createApplication(argc, argv));


    pApp->setApplicationName("Chess Clock");
    pApp->setOrganizationName("Chess Clock");

    pApp->setStyleSheet("* {color: white}");

    qmlRegisterType<WrappedClocksWidget>("ChessClocks", 1, 2, "WrappedClocksWidget");
    qmlRegisterType<Settings>("ChessClocks", 1, 2, "Settings");


    QScopedPointer<QDeclarativeView> pView(Sailfish::createView("qrc:/qml/main.qml"));

    Sailfish::showView(pView.data());

    return pApp->exec();
}
