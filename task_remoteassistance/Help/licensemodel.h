/*
 * Copyright (C) 2017 ~ 2017 Deepin Technology Co., Ltd.
 *
 * Author:     Iceyer <me@iceyer.net>
 *
 * Maintainer: Iceyer <me@iceyer.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LICENSE_H
#define LICENSE_H

#include <QObject>
#include <QDateTime>

enum SystemType {
    Desktop,
    Server,
};

enum ActiveState
{
    Unactivated,
    Activated
};

enum AuthorizationState
{
    Notauthorized,
    Authorized,
    Expired
};


struct System {
    SystemType  systemType;
    int         trialRemind;
    QString     localeEdition;
    QString     localeCopyright;
    QString     machineCode;
    QString     version;
};

struct License {
    QString     organization;
    QString     product;
    QString     machineCode;
    QString     edition;
    QString     validityBegin;
    QString     validityEnd;
    quint32     actived;
    quint32     authorizationState;
    QString     activeMethod;
    quint32     activeMsgType;
    QString     activeCode;
};

struct LicenseModel {
    System  system;
    License license;
};

Q_DECLARE_METATYPE(LicenseModel)

#endif // LICENSE_H
