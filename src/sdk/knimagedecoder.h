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
#ifndef KNIMAGEDECODER_H
#define KNIMAGEDECODER_H

#include <QObject>

/*!
 * \brief The KNImageDecoder class provides an port for the decoding the image.
 */
class KNImageDecoder : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Construct a KNImageDecoder class.
     * \param parent The parent object.
     */
    KNImageDecoder(QObject *parent = nullptr) : QObject(parent)
    {
    }

    /*!
     * \brief Return the image could parse the image or not.
     * \param imageData The data of the image.
     * \return If the parser could parse the image, return true.
     */
    virtual bool canParse(const QByteArray &imageData) = 0;

signals:

public slots:
};

#endif // KNIMAGEDECODER_H
