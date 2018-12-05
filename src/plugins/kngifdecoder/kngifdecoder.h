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
#ifndef KNGIFDECODER_H
#define KNGIFDECODER_H

#include "knimagedecoder.h"

/*!
 * \brief The KNGifDecoder class provides the Graphics Interchange Format (GIF)
 * decoding.
 */
class KNGifDecoder : public KNImageDecoder
{
    Q_OBJECT
public:
    /*!
     * \brief Construct a KNGifDecoder class.
     * \param parent The parent object.
     */
    explicit KNGifDecoder(QObject *parent = nullptr);

    /*!
     * \brief Reimplemented KNImageDecoder::canParse().
     */
    bool canParse(const QByteArray &imageData) Q_DECL_OVERRIDE;

signals:

public slots:
};

#endif // KNGIFDECODER_H
