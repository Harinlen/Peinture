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
#ifndef KNIMAGEPARSER_H
#define KNIMAGEPARSER_H

#include <QLinkedList>

#include <QObject>

#define knImageParser (KNImageParser::instance())

class KNImageDecoder;
/*!
 * \brief The KNImageParser class contains all the image decoder. The parser
 * would provide the decoder and render for the target image file.
 */
class KNImageParser : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Get the global instance for the image decoder.
     * \return The decoder instance pointer.
     */
    static KNImageParser *instance();

    /*!
     * \brief Initial the image decoder.
     * \param parent The parent object of the decoder.
     */
    static void initial(QObject *parent = nullptr);

    /*!
     * \brief Add the image decoder to the linked list.
     * \param decoder The decoder pointer.
     */
    void addDecoder(KNImageDecoder *decoder);

    /*!
     * \brief Find the decoder for the target file.
     * \return The decoder pointer, if we cannot decode the data, a null pointer
     * will be returned.
     */
    KNImageDecoder *findDecoder(const QByteArray &imageData);

signals:

public slots:

private:
    static KNImageParser *_instance;
    explicit KNImageParser(QObject *parent = nullptr);

    QLinkedList<KNImageDecoder *> m_decoders;
};

#endif // KNIMAGEPARSER_H
