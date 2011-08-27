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
        QGraphicsObject *pObject = rootObject();
        if (pObject)
            pObject->setProperty("applicationActive",false);
    }

    else if (event->type() == QEvent::WindowActivate)
    {
        QGraphicsObject *pObject = rootObject();
        if (pObject)
            pObject->setProperty("applicationActive",true);
    }


    return QDeclarativeView::event(event);
}
