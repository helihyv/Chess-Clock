#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include "classes/wrappedclockswidget.h"


/*! A class that gives accedd to settings

Used to save the last used dialog settings.
Uses QSettings internally.
Note: not compatible with the settings used in the Maemo versions.
The group names are the same, but the times are saved as ints (milliseconds) rather than QTimes.

@author Heli Hyvättinen
@date 2011-09-28
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
    Q_INVOKABLE int getTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, bool isWhite);

    /*!
   Returns intitial time (in milliseconds) from settings.
   @param timeControl Time control for which the setting is queried
   @param isWhite true for white player, false for black
   */
    Q_INVOKABLE int getInitialTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite);

    /*!
   Returns additional time (in milliseconds) from settings.
   @param timeControl Time control for which the setting is queried
   @param isWhite true for white player, false for black
   */
    Q_INVOKABLE int getAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite);

    /*!
      Returns whether the equal times is set in the settings
      @param timeControl Time control for which the setting is queried
      */
    Q_INVOKABLE bool isEqualTimes(WrappedClocksWidget::TimeControlType timeControl);



signals:

public slots:

    /*!
    Sets turns per addition in settings.
   @param timeControl Time control for which the setting is set
   @param isWhite true for white player, false for black
   @param turns The value to be saved
   */
    void setTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int turns);

    /*!
    Sets initial time in settings.
   @param timeControl Time control for which the setting is set
   @param isWhite true for white player, false for black
   @param time The time to be saved, in milliseconds
   */
    void setInitialTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time);

    /*!
    Sets additional time in settings.
   @param timeControl Time control for which the setting is set
   @param isWhite true for white player, false for black
   @param time The time to be saved, in milliseconds
   */

    void setAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time);

    /*! Sets the equal times setting
      @param timeControl Time control for which the setting is set
    */
    void setEqualTimes(WrappedClocksWidget::TimeControlType timeControl,bool on);

protected:

    QString getGroupName(WrappedClocksWidget::TimeControlType timeControl);

};

#endif // SETTINGS_H
