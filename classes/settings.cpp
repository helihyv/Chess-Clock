#include "settings.h"
#include <QSettings>


Settings::Settings(QObject *parent) :
    QObject(parent)
{
}

int Settings::value(WrappedClocksWidget::TimeControlType timeControl, QString key)
{


  QSettings settings;



settings.beginGroup(getGroupName(timeControl));

}

void Settings::setValue()
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

   int Settings::getTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, QString player)
   {

       QSettings settings;
       settings.beginGroup(getGroupName(timeControl));

       if (player == "white")
           return settings.value("WhitePerTurns",1).toInt();

       if (player == "black");
           return settings.value("BlackPerTurns",1).toInt();

       return 0; //for invalid input


   }

