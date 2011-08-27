#include "chessclockview.h"
#include <QDeclarativeContext>
#include <QDebug>

ChessClockView::ChessClockView(QWidget *parent) :
    QDeclarativeView(parent)
{
}

bool ChessClockView::event(QEvent *event)
{

    if (event->type() == QEvent::WindowDeactivate)
    {
        QDeclarativeContext * pContext = rootContext();
        if (pContext)
        {
            QObject * pObject = pContext->contextObject();

            if (pObject)
            {
                pObject->setProperty("applicationActive",false);
//            pContext->setContextProperty("clocksPage.applicationActive", false);
            qDebug() << "Window deactivated";
            }
            else qDebug() << "No context object!" << pContext->isValid();
//            QDeclarativeEngine * pEngine = engine();
//            engine()->
        }
    }

    else if (event->type() == QEvent::WindowActivate)
    {
        QDeclarativeContext * pContext = rootContext();
        if (pContext)
        {
            pContext->setContextProperty("clocksPage.applicationActive", true);
        }
    }


    return QDeclarativeView::event(event);
}
