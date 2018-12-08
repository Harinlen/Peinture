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
#include "kngifdecoder.h"

KNGifDecoder::KNGifDecoder(QObject *parent) :
    KNImageDecoder(parent)
{

}

bool KNGifDecoder::canParse(const QByteArray &imageData)
{
    // Detect the gif header.
    return imageData.size()>6 && // Minimum size of the image.
            imageData.at(0)=='G' && imageData.at(1)=='I' && imageData.at(2)=='F'
            && imageData.at(3)=='8' && imageData.at(5)=='a';
}

QList<QPixmap> KNGifDecoder::decode(const QByteArray &imageData)
{
    // Check the gif header.
    if(imageData.size()<6)
    {
        return QList<QPixmap>();
    }
    // Decode the GIF image.
    return QList<QPixmap>();
}
