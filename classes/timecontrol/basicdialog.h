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

#ifndef BASICDIALOG_H
#define BASICDIALOG_H

#include <QDialog>
#include <QString>
#include <QTime>

class QTimeEdit;
class QSpinBox;
class QCheckBox;
class QLabel;

/*! Basic dialog for Time Control settings

  @author Arto Hyvättinen
  @date 2010-08-16

  Basic dialog setting up clock.
  Time control can use this dialog.
  Using disableAddition(), disablePerTurns() or disableUnEquals()
  it is possible to customize dialog.

  All the widgets are public for customization.
  */

class BasicDialog : public QDialog
{
    Q_OBJECT
public:
    /*! Constructor

      @param timeControlName Name of time controller, will be window title */
    BasicDialog(QString timeContolName, QWidget *parent = 0);

    void disableAddition();
    void disablePerTurns();
    void disableUnEquals();

    int getWhiteInitial();
    int getBlackInitial();
    int getWhiteAddition();
    int getBlackAddition();
    int getWhitePerTurns();
    int getBlackPerTurns();
    /*! Store values to settings */
    void store();
    /*! Load values from settings, or init to initial values */
    void init(QTime whiteInitial=QTime(1,30),
              QTime blackInitial=QTime(1,30),
              QTime whiteAddition=QTime(0,0,30),
              QTime blackAddition=QTime(0,0,30),
              int whitePerTurns = 1,
              int blackPerTurns = 1);
signals:

public slots:
    void setEquals();

protected:
    static QTimeEdit* initTimeEdit();
    static int toMsecs(QTimeEdit* timeEdit);

public:
    QTimeEdit *whiteInitial_, *blackInitial_;
    QTimeEdit *whiteAddition_, *blackAddition_;
    QSpinBox *whiteTurns_, *blackTurns_;
    QCheckBox *equals_;

    QLabel *initialLabel_, *additionLabel_, *perTurnLabel_, *equalsLabel_;
    QLabel *whiteLabel_, *blackLabel_;

protected:
    QString timeControlName_;


};

#endif // BASICDIALOG_H
