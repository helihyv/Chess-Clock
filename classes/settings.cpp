#include "settings.h"
#include <QSettings>


Settings::Settings(QObject *parent) :
    QObject(parent)
{
}



QString Settings::getGroupName(WrappedClocksWidget::TimeControlType timeControl)
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

   int Settings::getTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, bool isWhite)
   {

       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (isWhite)
           return settings.value("WhitePerTurns",1).toInt();

       else
           return settings.value("BlackPerTurns",1).toInt();

    }

   int Settings::getInitialTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       int defaultTime;

       if (timeControl == WrappedClocksWidget::HourGlass)
           defaultTime = 60*1000; // 1 min
       else
           defaultTime = 30*60*1000; //30 min

       if (isWhite)
           return settings.value("WhiteInitial",defaultTime).toInt();
        else
           return settings.value("BlackInitial",defaultTime).toInt();
   }

   int Settings::getAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (isWhite)
           return settings.value("WhiteAddition",30*1000).toInt();
       else
           return settings.value("BlackAddition",30*100).toInt();
   }

   bool Settings::isEqualTimes(WrappedClocksWidget::TimeControlType timeControl)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       return settings.value("Equals",false).toBool();
   }

   void Settings::setTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int turns)
   {
        QSettings settings;
        settings.beginGroup(getGroupName(timeControl));

        if (isWhite)
            settings.setValue("WhitePerTurns",turns);
        else
            settings.setValue("BlackPerTurns",turns);
   }

   void Settings::setInitialTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (isWhite)
           settings.setValue("WhiteInitial",time);
       else
           settings.setValue("BlackItnitial",time);
   }

   void Settings::setAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time)
   {
       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (isWhite)
           settings.setValue("WhiteAddition",time);
       else
           settings.setValue("BlackAddition",time);
   }

    void Settings::setEqualTimes(WrappedClocksWidget::TimeControlType timeControl, bool on)
    {
        QSettings settings;
        settings.beginGroup(getGroupName(timeControl));

        settings.setValue("Equals",on);
    }


