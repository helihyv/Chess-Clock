#include "clockswidgetplugin.h"
#include "wrappedclockswidget.h"
#include <qdeclarative.h>

ClocksWidgetPlugin::ClocksWidgetPlugin(QObject *parent) :
    QDeclarativeExtensionPlugin(parent)
{
}


void ClocksWidgetPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<WrappedClocksWidget>(uri,1,0,"ChessClocks");
}

Q_EXPORT_PLUGIN2(clockswidgetplugin,ClocksWidgetPlugin);

