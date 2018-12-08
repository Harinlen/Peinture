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
#ifndef KNGENERALDECODER_H
#define KNGENERALDECODER_H

#include "knimagedecoder.h"

/*!
 * \brief The KNGeneralDecoder class provide a general decoder which could
 * decode most default image format. It will use the QPixmap default decoding
 * method to decode the image.
 * It is responsable for decoding BMP, JPG, JPEG, PNG, PBM, PGM, PPM, XBM, XPM.
 */
class KNGeneralDecoder : public KNImageDecoder
{
    Q_OBJECT
public:
    /*!
     * \brief KNGeneralDecoder
     * \param parent
     */
    explicit KNGeneralDecoder(QObject *parent = nullptr);

    /*!
     * \brief Reimplemented KNImageDecoder::canParse().
     */
    bool canParse(const QByteArray &imageData) Q_DECL_OVERRIDE;

    /*!
     * \brief Reimplemented KNImageDecoder::decode().
     */
    QList<QPixmap> decode(const QByteArray &imageData) Q_DECL_OVERRIDE;

signals:

public slots:
};

#endif // KNGENERALDECODER_H
