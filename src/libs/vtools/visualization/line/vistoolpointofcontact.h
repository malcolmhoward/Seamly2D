/************************************************************************
 **
 **  @file   vistoolpointofcontact.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   14 8, 2014
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013-2015 Valentina project
 **  <https://github.com/valentina-project/vpo2> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef VISTOOLPOINTOFCONTACT_H
#define VISTOOLPOINTOFCONTACT_H

#include <qcompilerdetection.h>
#include <QGraphicsItem>
#include <QMetaObject>
#include <QObject>
#include <QString>
#include <QtGlobal>

#include "../vmisc/def.h"
#include "visline.h"

class VisToolPointOfContact : public VisLine
{
    Q_OBJECT
public:
    explicit VisToolPointOfContact(const VContainer *data, QGraphicsItem *parent = nullptr);
    virtual ~VisToolPointOfContact() = default;

    virtual void RefreshGeometry() Q_DECL_OVERRIDE;
    void         setLineP2Id(const quint32 &value);
    void         setRadiusId(const quint32 &value);
    void         setRadius(const QString &expression);
    virtual int  type() const Q_DECL_OVERRIDE {return Type;}
    enum { Type = UserType + static_cast<int>(Vis::ToolPointOfContact)};
private:
    Q_DISABLE_COPY(VisToolPointOfContact)
    quint32         lineP2Id;
    quint32         radiusId;
    VScaledEllipse *point;
    VScaledEllipse *lineP1;
    VScaledEllipse *lineP2;
    VScaledEllipse *arc_point;
    VScaledEllipse *circle;
    qreal           radius;

};

#endif // VISTOOLPOINTOFCONTACT_H
