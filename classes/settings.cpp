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
    return 60*60*1000;
   }

   int Settings::getAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite)
   {
    return 30*1000;
   }

   void Settings::setTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int turns)
   {}

   void Settings::setInitialTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time)
   {}

   void Settings::setAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time)
   {}




