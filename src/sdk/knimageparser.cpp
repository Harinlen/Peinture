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
#include "knimagedecoder.h"

#include "knimageparser.h"

KNImageParser *KNImageParser::_instance = nullptr;

KNImageParser *KNImageParser::instance()
{
    return _instance;
}

void KNImageParser::initial(QObject *parent)
{
    if(_instance)
    {
        return;
    }
    // Initial the pointer.
    _instance = new KNImageParser(parent);
}

void KNImageParser::addDecoder(KNImageDecoder *decoder)
{
    // Reset the parent.
    decoder->setParent(this);
    // Append the decoder to the linked list.
    m_decoders.append(decoder);
}

KNImageDecoder *KNImageParser::findDecoder(const QByteArray &imageData)
{
    // Find the decoder.
    for(auto i=m_decoders.constBegin(); i!=m_decoders.constEnd(); ++i)
    {
        //Check the decoder.
        if((*i)->canParse(imageData))
        {
            return (*i);
        }
    }
    // No parser could decode the image.
    return nullptr;
}

KNImageParser::KNImageParser(QObject *parent) : QObject(parent)
{
}
