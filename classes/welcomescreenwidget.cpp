 /**************************************************************************

    Chess Clock

    Copyright (c) Arto Hyvättinen 2010

    This file is part of Chess Clock software.

    Chess Clock is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Chess Clock is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


**************************************************************************/

#include <QLabel>
#include <QPixmap>
#include <QApplication>
#include <QHBoxLayout>

#include "welcomescreenwidget.h"

WelcomeScreenWidget::WelcomeScreenWidget(QWidget *parent) :
    QWidget(parent)
{
    QLabel* logoLabel = new QLabel;
    logoLabel->setPixmap( QPixmap(":/rc/pic/logo.png"));
    QLabel* introLabel = new QLabel(
            tr("<h1>Chess Clock</h1><br>"
               "Version %1<br>"
               "&copy; Arto Hyv&auml;ttinen 2010<br>"
               "Chess Clock is free software in terms of GNU General Public Licence v3"
               "<p>Welcome to Chess Clock!<br>"
               "Please touch to set up game clock.</p>"
               ).arg(qApp->applicationVersion())

            );
    introLabel->setWordWrap(true);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(logoLabel);
    layout->addWidget(introLabel);
    setLayout( layout );
}
