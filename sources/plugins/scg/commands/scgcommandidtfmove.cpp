/*
-----------------------------------------------------------------------------
This source file is part of OSTIS (Open Semantic Technology for Intelligent Systems)
For the latest info, see http://www.ostis.net

Copyright (c) 2010 OSTIS

OSTIS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OSTIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OSTIS.  If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
*/

#include "scgcommandidtfmove.h"

SCgCommandIdtfMove::SCgCommandIdtfMove(SCgTextItem *idtf,
                                       SCgScene *scene,
                                       const QPointF& oldPosition,
                                       const QPointF& newPosition,
                                       QUndoCommand *parent) :
    SCgBaseCommand(scene, 0, parent),
    mIdtfItem(idtf),
    mOldPosition(oldPosition),
    mNewPosition(newPosition)
{
    setText(QObject::tr("Move identifier"));
}

SCgCommandIdtfMove::~SCgCommandIdtfMove()
{
}

void SCgCommandIdtfMove::redo()
{
    mIdtfItem->setPos(mNewPosition);
    SCgBaseCommand::redo();
}

void SCgCommandIdtfMove::undo()
{
    mIdtfItem->setPos(mOldPosition);
    SCgBaseCommand::undo();
}
