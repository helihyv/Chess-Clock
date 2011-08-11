#ifndef CLOCKSWIDGETPLUGIN_H
#define CLOCKSWIDGETPLUGIN_H

#include <QDeclarativeExtensionPlugin>

class ClocksWidgetPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
public:
    explicit ClocksWidgetPlugin(QObject *parent = 0);

    void registerTypes(const char *uri);

signals:

public slots:

};

#endif // CLOCKSWIDGETPLUGIN_H
