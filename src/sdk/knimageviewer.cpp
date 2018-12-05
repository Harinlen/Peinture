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
#include <QFile>

#include "knimageparser.h"

#include "knimageviewer.h"

#include <QDebug>

KNImageViewer::KNImageViewer(QWidget *parent) : QMainWindow(parent)
{
    ;
}

bool KNImageViewer::loadImage(const QUrl &fileUrl)
{
    QByteArray imageData;
    // According to the url type, load the file to the memory.
    if(fileUrl.isLocalFile())
    {
        QFile imageFile(fileUrl.toLocalFile());
        if(!imageFile.open(QIODevice::ReadOnly))
        {
            return false;
        }
        // Load the file data to the memory.
        imageData=imageFile.readAll();
        imageFile.close();
    }
    // Decode the image file data.
    qDebug()<<knImageParser->findDecoder(imageData);
    return false;
}
