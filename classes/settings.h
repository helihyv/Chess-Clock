#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include "classes/wrappedclockswidget.h"


/*! A class that gives access to settings

Used to save the last used dialog settings.
Uses QSettings internally.
Note: not compatible with the settings used in the Maemo versions.
The group names are the same, but the times are saved as ints (milliseconds) rather than QTimes.
Time Control is passed as int due to QML problem, but *must* be a valid
WrappedClocksWidget::TimeControlType enum to work. (All other values are interpreted as "Normal Clock"

@author Heli Hyvättinen
@date 2011-10-03
@version 1.9.1

  */

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);
    /*!
   Returns turns per addition from settings.
   @param timeControl Time control for which the setting is queried
   @param isWhite true for white player, false for black
   */
    Q_INVOKABLE int getTurnsPerAddition(int timeControl, bool isWhite);

    /*!
   Returns intitial time (in milliseconds) from settings.
   @param timeControl Time control for which the setting is queried
   @param isWhite true for white player, false for black
   */
    Q_INVOKABLE QTime getInitialTime(int timeControl, bool isWhite);

    /*!
   Returns additional time (in milliseconds) from settings.
   @param timeControl Time control for which the setting is queried
   @param isWhite true for white player, false for black
   */
    Q_INVOKABLE QTime getAdditionalTime(int timeControl, bool isWhite);

    /*!
      Returns whether the equal times is set in the settings
      @param timeControl Time control for which the setting is queried
      */
    Q_INVOKABLE bool isEqualTimes(int timeControl);



signals:

public slots:

    /*!
    Sets turns per addition in settings.
   @param timeControl Time control for which the setting is set
   @param isWhite true for white player, false for black
   @param turns The value to be saved
   */
    void setTurnsPerAddition(int timeControl, bool isWhite, int turns);

    /*!
    Sets initial time in settings.
   @param timeControl Time control for which the setting is set
   @param isWhite true for white player, false for black
   @param time The time to be saved, in milliseconds
   */
    void setInitialTime(int timeControl, bool isWhite, QTime time);

    /*!
    Sets additional time in settings.
   @param timeControl Time control for which the setting is set
   @param isWhite true for white player, false for black
   @param time The time to be saved, in milliseconds
   */

    void setAdditionalTime(int timeControl, bool isWhite, QTime time);

    /*! Sets the equal times setting
      @param timeControl Time control for which the setting is set
    */
    void setEqualTimes(int timeControl,bool on);

protected:

    QString getGroupName(int timeControl);

};

#endif // SETTINGS_H
