#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QVariant>
#include "classes/wrappedclockswidget.h"

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);

    Q_INVOKABLE int getTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, bool isWhite);

    Q_INVOKABLE int getInitialTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite);

    Q_INVOKABLE int getAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite);


signals:

public slots:

    void setTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int turns);

    void setInitialTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time);

    void setAdditionalTime(WrappedClocksWidget::TimeControlType timeControl, bool isWhite, int time);

protected:

    QString getGroupName(WrappedClocksWidget::TimeControlType);

};

#endif // SETTINGS_H
