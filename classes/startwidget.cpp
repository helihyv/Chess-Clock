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

#include "startwidget.h"
#include "timecontrol.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QFont>
#include <QLabel>
#include <QListWidgetItem>

StartWidget::StartWidget(QWidget *parent) :
    QWidget(parent)
{
    QLabel* titleLabel = new QLabel( qApp->applicationName() );
    titleLabel->setFont(QFont("Helvetica",32,QFont::Bold));

    QLabel* copyLabel = new QLabel( tr("&copy; Arto Hyv&auml;ttinen 2010"));
    copyLabel->setTextFormat(Qt::RichText);
    copyLabel->setWordWrap(true);

    QLabel* logoLabel = new QLabel;
    logoLabel->setPixmap( QPixmap(":/rc/pic/logo.png"));

    QLabel* introLabel = new QLabel( tr("Select game mode"));
    introLabel->setWordWrap(true);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addWidget(titleLabel);
    leftLayout->addWidget(copyLabel);
    leftLayout->addWidget(logoLabel);
    leftLayout->addWidget(introLabel);

    modeSelect_ = new QListWidget();
    modeSelect_->setViewMode(QListView::IconMode);
    modeSelect_->setMovement(QListView::Static);
    modeSelect_->setSelectionMode(QAbstractItemView::NoSelection);
    modeSelect_->setIconSize(QSize(64,64 ));

    connect( modeSelect_, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(selectControl(QListWidgetItem*)));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addWidget(modeSelect_);


    setLayout( layout );
}

void StartWidget::addTimeControl(TimeControl *tc)
{
    timeControls_.append(tc);
    QListWidgetItem* item = new QListWidgetItem(modeSelect_);
    item->setText( tc->getName());
    item->setIcon( tc->getIcon());
    // Store index to UserRole
    item->setData(Qt::UserRole, timeControls_.size()-1);

}

void StartWidget::selectControl(QListWidgetItem *item)
{
    int index=item->data(Qt::UserRole).toInt();
    TimeControl* tc=timeControls_.at(index);
    emit selected(tc);

}

