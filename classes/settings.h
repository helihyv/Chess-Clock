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

    Q_INVOKABLE int value(WrappedClocksWidget::TimeControlType timeControl, QString key);

    Q_INVOKABLE int getTurnsPerAddition(WrappedClocksWidget::TimeControlType timeControl, QString player);


signals:

public slots:

    void setValue();

protected:

    QString getGroupName(WrappedClocksWidget::TimeControlType);

};

#endif // SETTINGS_H
