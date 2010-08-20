 /**************************************************************************

    Chess Clock

    Copyright (c) Arto Hyvättinen 2010

    This file is part of Chess Clock software.

    Chess Clock is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Chess Clock is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


**************************************************************************/

#include "basicdialog.h"

#include <QTimeEdit>
#include <QTime>
#include <QSpinBox>
#include <QCheckBox>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QSettings>
#include <QDebug>

BasicDialog::BasicDialog(QString timeControlName, QWidget *parent) :
    QDialog(parent)
{
    timeControlName_ = timeControlName;

    // Initial times
    initialLabel_ = new QLabel( tr("Initial time"));
    whiteInitial_ = initTimeEdit();
    blackInitial_ = initTimeEdit();
    // Additional times
    additionLabel_ = new QLabel( tr("Additional time"));
    whiteAddition_ = initTimeEdit();
    blackAddition_ = initTimeEdit();
    // Turns per addition
    perTurnLabel_ = new QLabel( tr("Turns per addition"));
    whiteTurns_=new QSpinBox;
    whiteTurns_->setRange(1,99);

    blackTurns_=new QSpinBox;
    blackTurns_->setRange(1,99);

    // Equal times
    equals_ = new QCheckBox( tr("Equal times"));

    connect( equals_, SIGNAL(stateChanged(int)),this,SLOT(setEquals()));

    equals_->setChecked(true);
    setEquals();

    whiteLabel_ = new QLabel;
    whiteLabel_->setPixmap(QPixmap(":/rc/pic/white_small.png"));
    blackLabel_ = new QLabel;
    blackLabel_->setPixmap(QPixmap(":/rc/pic/black_small.png"));

    // Lay out
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(equals_,0,0);
    layout->addWidget(whiteLabel_,0,1,1,1,Qt::AlignCenter);
    layout->addWidget(blackLabel_,0,2,1,1,Qt::AlignCenter);

    layout->addWidget(initialLabel_,1,0);
    layout->addWidget(whiteInitial_,1,1);
    layout->addWidget(blackInitial_,1,2);

    layout->addWidget(additionLabel_,2,0);
    layout->addWidget(whiteAddition_,2,1);
    layout->addWidget(blackAddition_,2,2);

    layout->addWidget(perTurnLabel_,3,0);
    layout->addWidget(whiteTurns_,3,1);
    layout->addWidget(blackTurns_,3,2);

    QPushButton* button = new QPushButton( tr("Start game"));
    connect( button, SIGNAL(clicked()), this, SLOT(accept()));
    layout->addWidget(button,4,2);

    setLayout( layout );
    setWindowTitle( timeControlName_);

}

void BasicDialog::setEquals()
{
    blackInitial_->setDisabled( equals_->isChecked());
    blackAddition_->setDisabled( equals_->isChecked());
    blackTurns_->setDisabled( equals_->isChecked());

}


void BasicDialog::disablePerTurns()
{
    perTurnLabel_->setVisible(false);
    whiteTurns_->setVisible(false);
    blackTurns_->setVisible(false);
}

void BasicDialog::disableAddition()
{
    disablePerTurns();
    whiteAddition_->setVisible(false);
    blackAddition_->setVisible(false);
    additionLabel_->setVisible(false);
}

void BasicDialog::disableUnEquals()
{
    equals_->setChecked(true);
    equals_->setVisible(false);
    whiteLabel_->setVisible(false);
    blackLabel_->setVisible(false);
    blackInitial_->setVisible(false);
    blackAddition_->setVisible(false);
    blackTurns_->setVisible(false);
}

void BasicDialog::store()
{
    // Store into QSettings
    QSettings s;
    s.beginGroup(timeControlName_);
    s.setValue("Equals",equals_->isChecked());
    s.setValue("WhiteInitial",whiteInitial_->time());
    s.setValue("WhiteAddition",whiteAddition_->time());
    s.setValue("WhitePerTurns",whiteTurns_->value());

    s.setValue("BlackInitial",blackInitial_->time());
    s.setValue("BlackAddition",blackAddition_->time());
    s.setValue("BlackPerTurns",blackTurns_->value());
}

void BasicDialog::init(QTime whiteInitial, QTime blackInitial, QTime whiteAddition, QTime blackAddition, int whitePerTurns, int blackPerTurns)
{
    // Load from QSettings
    // first time use defaults
    QSettings s;
    s.beginGroup(timeControlName_);

    equals_->setChecked(s.value("Equals",true).toBool() );
    setEquals();
    whiteInitial_->setTime( s.value("WhiteInitial",whiteInitial).toTime());
    blackInitial_->setTime(s.value("BlackInitial",blackInitial).toTime());
    whiteAddition_->setTime(s.value("WhiteAddition",whiteAddition).toTime());
    blackAddition_->setTime(s.value("BlackAddition",blackAddition).toTime());
    whiteTurns_->setValue(s.value("WhitePerTurns",whitePerTurns).toInt());
    blackTurns_->setValue(s.value("BlackPerTurns",blackPerTurns).toInt());

}

int BasicDialog::getWhiteInitial()
{
    return toMsecs( whiteInitial_);
}

int BasicDialog::getWhiteAddition()
{
    return toMsecs( whiteAddition_);
}

int BasicDialog::getWhitePerTurns()
{
    return whiteTurns_->value();
}

int BasicDialog::getBlackInitial()
{
    // if Equals is checked, black values are disabled
    // and white values returned.
    if( equals_->isChecked())
        return toMsecs( whiteInitial_);
    else
        return toMsecs( blackInitial_);
}

int BasicDialog::getBlackAddition()
{
    if( equals_->isChecked())
        return toMsecs( whiteAddition_);
    else
        return toMsecs( blackAddition_ );

}

int BasicDialog::getBlackPerTurns()
{
    if( equals_->isChecked())
        return whiteTurns_->value();
    else
        return blackTurns_->value();
}


int BasicDialog::toMsecs(QTimeEdit *timeEdit)
{
    QTime qtime=timeEdit->time();
    int msecs=qtime.msecsTo(QTime(0,0,0));;
    return 0-msecs;
}


QTimeEdit* BasicDialog::initTimeEdit()
{
    // Make QTimeEdit and set up range and display format
    QTimeEdit* timeEdit = new QTimeEdit;
    timeEdit->setMinimumTime( QTime(0,0,0));
    timeEdit->setMaximumTime( QTime(12,0,0));
    timeEdit->setDisplayFormat( tr("hh:mm:ss","Time Edit display format"));
    return timeEdit;
}
