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
#include "kngeneraldecoder.h"

#include <QDebug>

KNGeneralDecoder::KNGeneralDecoder(QObject *parent) :
    KNImageDecoder(parent)
{

}

bool KNGeneralDecoder::canParse(const QByteArray &imageData)
{
    const char *imgData = imageData.constData();
    // Check the bmp format.
    if(imageData.size()>14)
    {
        // At least we have the size. :)
        if((imgData[0]=='B' && imageData[1]=='M') || // Windows Image
           (imgData[0]=='B' && imageData[1]=='A') || // OS/2 Bitmap array
           (imgData[0]=='C' && imageData[1]=='I') || // OS/2 Color Icon
           (imgData[0]=='C' && imageData[1]=='P') || // OS/2 Color Pointer
           (imgData[0]=='I' && imageData[1]=='C') || // OS/2 Icon
           (imgData[0]=='P' && imageData[1]=='T'))   // OS/2 Pointer
        {
            // Check the internal format.
            if(imgData[6] == 0 && imgData[7] == 0 &&
                    imgData[8] == 0 && imgData[9] == 0)
            {
                const quint8 *uImageData=(const quint8 *)imgData;
                quint32 dataSize=(((quint32)uImageData[5]) << 24) |
                                 (((quint32)uImageData[4]) << 16) |
                                 (((quint32)uImageData[3]) << 8) |
                                 (((quint32)uImageData[2]));
                return dataSize==(quint32)imageData.size();
            }
        }
    }
    return false;
}

QList<QPixmap> KNGeneralDecoder::decode(const QByteArray &imageData)
{
    // Create an result map.
    QList<QPixmap> result;
    // Append the pixmap.
    result.append(QPixmap::fromImage(QImage::fromData(imageData)));
    // Give back the result.
    return result;
}
