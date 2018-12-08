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

#ifndef KNIMAGEVIEWER_H
#define KNIMAGEVIEWER_H

#include <QUrl>
#include <QList>
#include <QPixmap>

#include <QMainWindow>

/*!
 * \brief The KNImageViewer class defines the image viewer window for showing
 * the image.
 */
class KNImageViewer : public QMainWindow
{
    Q_OBJECT
public:
    /*!
     * \brief Construct a KNImageViewer window.
     * \param parent The parent widget.
     */
    explicit KNImageViewer(QWidget *parent = nullptr);

    /*!
     * \brief Load and display an image to the current display data.
     * \param fileUrl The file local or remote url.
     * \return true for successfully load the image, or else failed to load the
     * image.
     */
    bool loadImage(const QUrl &fileUrl);

signals:

public slots:

protected:
    /*!
     * \brief Reimplemented from QMainWindow::paintEvent().
     */
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    /*!
     * \brief Reimplemented from QMainWindow::resizeEvent().
     */
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    inline void rescalePixmap();
    QList<QPixmap> m_rawPixmap, m_scaledPixmap;
    bool m_singleMode;
};

#endif // KNIMAGEVIEWER_H
