/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KNGLOBAL_H
#define KNGLOBAL_H

#include <QObject>

#define knGlobal (KNGlobal::instance())

class KNImageViewer;
/*!
 * \brief The KNGlobal class provides the global.
 */
class KNGlobal : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Get the global instance pointer.
     * \return The global instance pointer.
     */
    static KNGlobal *instance();

    /*!
     * \brief Initial the global instance.
     * \param parent The parent object.
     */
    static void initial(QObject *parent = nullptr);

signals:

public slots:

private:
    static KNGlobal *_instance;
    explicit KNGlobal(QObject *parent = nullptr);
};

#endif // KNGLOBAL_H
