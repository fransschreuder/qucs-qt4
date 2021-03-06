/***************************************************************************
 * Copyright (C) 2008 by Gopala Krishna A <krishna.ggk@gmail.com>          *
 *                                                                         *
 * This is free software; you can redistribute it and/or modify            *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 2, or (at your option)     *
 * any later version.                                                      *
 *                                                                         *
 * This software is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this package; see the file COPYING.  If not, write to        *
 * the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,   *
 * Boston, MA 02110-1301, USA.                                             *
 ***************************************************************************/

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "painting.h"

//! * \brief Represents an ellipse on schematic.
class Ellipse : public Painting
{
public:
    enum {
        Type = Painting::EllipseType
    };

    Ellipse(QRectF rect, SchematicScene *scene = 0);
    ~Ellipse();

    QRectF boundForRect(const QRectF &rect) const;
    QPainterPath shapeForRect(const QRectF &rect) const;

    void paint(QPainter *, const QStyleOptionGraphicsItem*, QWidget *);

    //! \brief Returns ellipse rect represented by this item.
    QRectF ellipse() const { return paintingRect(); }
    void setEllipse(const QRectF& rect) { setPaintingRect(rect); }

    int type() const { return Ellipse::Type; }
    Ellipse* copy(SchematicScene *scene = 0) const;

    void saveData(Qucs::XmlWriter *writer) const;
    void loadData(Qucs::XmlReader *reader);

    int launchPropertyDialog(Qucs::UndoOption opt);
};

#endif //ELLIPSE_H
