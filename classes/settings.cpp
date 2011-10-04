#include "settings.h"
#include <QSettings>
#include <QDebug>


Settings::Settings(QObject *parent) :
    QObject(parent)
{
}



QString Settings::getGroupName(int timeControl)
{
    //Using same groups and keys in QSettings as the maemo version
    //just in case Maemo version would move to use QML someday


   QString groupString;

   switch (timeControl)
   {

    case WrappedClocksWidget::NormalClock:

       groupString = "Normal clock";
       break;

    case WrappedClocksWidget::AdditionBefore:

       groupString = "Addition before";
       break;

    case WrappedClocksWidget::AdditionAfter:
           groupString = "Addition after";
           break;

    case WrappedClocksWidget::Delay:
       groupString = "Delay";
       break;

   case WrappedClocksWidget::DelayAfter:
       groupString = "Delay after";
       break;


    case WrappedClocksWidget::HourGlass:
       groupString = "Hour glass";
       break;

    default: //If QML sends an invalid value give the value for normal clock

       groupString = "Normal Clock";
       break;

    }
return groupString;

}

   int Settings::getTurnsPerAddition(int timeControl, bool isWhite)
   {

       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (isWhite)
           return settings.value("WhitePerTurns",1).toInt();

       else
           return settings.value("BlackPerTurns",1).toInt();

    }

   QTime Settings::getInitialTime(int timeControl, bool isWhite)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       QTime defaultTime(0,30);

       QTime hourGlassTime(0,1);

       if (timeControl == WrappedClocksWidget::HourGlass)
            defaultTime = hourGlassTime;

       if (isWhite)
           return settings.value("WhiteInitial",defaultTime).toTime();
        else
           return settings.value("BlackInitial",defaultTime).toTime();
   }

   QTime Settings::getAdditionalTime(int timeControl, bool isWhite)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       QTime defaultTime(0,0,30);
       if (isWhite)
           return settings.value("WhiteAddition",defaultTime).toTime();
       else
           return settings.value("BlackAddition",defaultTime).toTime();
   }

   bool Settings::isEqualTimes(int timeControl)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       return settings.value("Equals",false).toBool();
   }

   void Settings::setTurnsPerAddition(int timeControl, bool isWhite, int turns)
   {
        QSettings settings;
        settings.beginGroup(getGroupName(timeControl));

        if (isWhite)
            settings.setValue("WhitePerTurns",turns);
        else
            settings.setValue("BlackPerTurns",turns);
   }

   void Settings::setInitialTime(int timeControl, bool isWhite, QTime time)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (isWhite)
           settings.setValue("WhiteInitial",time);
       else
           settings.setValue("BlackItnitial",time);
   }

   void Settings::setInitialTime(int timeControl, bool isWhite, int hours, int minutes, int seconds)
   {
       QTime  time (hours,minutes,seconds);
       setInitialTime(timeControl,isWhite,time);
       qDebug () << "Saved initial time setting: "<< time;
   }

   void Settings::setAdditionalTime(int timeControl, bool isWhite, QTime time)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (isWhite)
           settings.setValue("WhiteAddition",time);
       else
           settings.setValue("BlackAddition",time);
   }

   void Settings::setAdditionalTime(int timeControl, bool isWhite, int hours, int minutes, int seconds)
   {
       QTime time(hours,minutes,seconds);
       setAdditionalTime(timeControl,isWhite,time);
       qDebug() << "Saved additional time setting: " << time;
   }

    void Settings::setEqualTimes(int timeControl, bool on)
    {
        QSettings settings;
        settings.beginGroup(getGroupName(timeControl));

        settings.setValue("Equals",on);
        qDebug() << "Saved Equal times setting: " << on;
    }



