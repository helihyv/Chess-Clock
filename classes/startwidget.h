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

#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QListWidget>


class QListWidget;
class TimeControl;

/*! Start widget to ask for Time control

  @author Arto Hyvättinen
  @date 2010-08-16

  Time Controls are stored inside Start Widget */
class StartWidget : public QWidget
{
    Q_OBJECT
public:
    StartWidget(QWidget *parent = 0);
    void addTimeControl( TimeControl* tc);

signals:
    void selected(TimeControl* timeControl);

public slots:
    void selectControl(QListWidgetItem* item);

protected:
    QListWidget* modeSelect_;
    QList<TimeControl*> timeControls_;

};

#endif // STARTWIDGET_H
