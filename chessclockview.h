#ifndef CHESSCLOCKVIEW_H
#define CHESSCLOCKVIEW_H

#include <QDeclarativeView>

class ChessClockView : public QDeclarativeView
{
    Q_OBJECT
public:
    explicit ChessClockView(QWidget *parent = 0);

    bool event (QEvent *event);

signals:

public slots:

};

#endif // CHESSCLOCKVIEW_H
