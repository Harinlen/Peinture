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
#include <QFileInfo>

#include "knimageparser.h"
#include "knimagedecoder.h"

#include "knimageviewer.h"

#include <QDebug>

KNImageViewer::KNImageViewer(QWidget *parent) :
    QMainWindow(parent),
    m_singleMode(false)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
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
        // Update the title.
        setWindowTitle(QFileInfo(imageFile).fileName());
        // Load the file data to the memory.
        imageData=imageFile.readAll();
        imageFile.close();
    }
    // Try to find the decoder.
    KNImageDecoder *decoder=knImageParser->findDecoder(imageData);
    if(decoder==nullptr)
    {
        // Failed to find image decoder.
        return false;
    }
    //Decode the image file data.
    QList<QPixmap> renderData=decoder->decode(imageData);
    if(renderData.size()==1)
    {
        // Single image rendering mode.
        m_singleMode=true;
        m_rawPixmap=renderData;
        // Rescale the image.
        rescalePixmap();
        // Update the image.
        update();
        return true;
    }
    return false;
}

void KNImageViewer::paintEvent(QPaintEvent *event)
{
    // Paint the main window.
    QMainWindow::paintEvent(event);
    // Draw the pixmap data.
    if(m_scaledPixmap.isEmpty())
    {
        // Render the cannot open text.
        return;
    }
    // Render the image according to the current mode.
    if(m_singleMode)
    {
        // Render the only image.
        return;
    }
}

void KNImageViewer::resizeEvent(QResizeEvent *event)
{
    // Resize the window.
    QMainWindow::resizeEvent(event);
    // Rescale the image.
    rescalePixmap();
    // Update the scaled image.
    update();
}

inline void KNImageViewer::rescalePixmap()
{
    ;
}
