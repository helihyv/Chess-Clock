#include "chessclockview.h"
#include <QDeclarativeContext>
#include <QDebug>
#include <QGraphicsObject>

ChessClockView::ChessClockView(QWidget *parent) :
    QDeclarativeView(parent)
{

}

bool ChessClockView::event(QEvent *event)
{

    if (event->type() == QEvent::WindowDeactivate)
    {
        QDeclarativeContext * pContext = new QDeclarativeContext (rootContext());
        if (pContext)
        {

//            pContext->setContextProperty("applicationActive", false);
            qDebug() << "Window deactivated";

//            QDeclarativeEngine * pEngine = engine();
//            engine()->
        }

        QGraphicsObject *pObject = rootObject();
        pObject->setProperty("applicationActive",false);
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
