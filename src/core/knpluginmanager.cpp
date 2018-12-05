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
#include <QApplication>

//Dependencies.
#include "knmainwindow.h"
#include "knversion.h"
#include "knglobal.h"
#include "knimageparser.h"
#include "knimageviewer.h"

//Plugins
#include "plugins/kngifdecoder/kngifdecoder.h"

#include "knpluginmanager.h"

#include <QDebug>

KNPluginManager::KNPluginManager(QObject *parent) :
    QObject(parent),
    m_mainWindow(nullptr),
    m_viewer(nullptr)
{
    // Load the global.
    KNGlobal::initial(this);
}

KNMainWindow *KNPluginManager::mainWindow() const
{
    return m_mainWindow;
}

void KNPluginManager::setMainWindow(KNMainWindow *mainWindow)
{
    if(m_mainWindow==nullptr)
    {
        //Save the main window object.
        m_mainWindow = mainWindow;
        //Set the main window to global.
//        knGlobal->setMainWindow(m_mainWindow);
    }
}

void KNPluginManager::loadPlugins()
{
    // Add decoders.
    knImageParser->addDecoder(new KNGifDecoder());
}

void KNPluginManager::launchApplication()
{
    // For Windows and Linux, it will check the arguments.
#if defined(Q_OS_WIN) || defined(Q_OS_LINUX)
    // Check the arguments.
    QStringList arguments = qApp->arguments();
    // Create image viewer window.
    ;
#elif defined(Q_OS_MACX)
    //Show the main window.
    m_mainWindow->show();
#endif
}

inline void KNPluginManager::setApplicationInformation()
{
    //Set static application information.
    QApplication::setApplicationName("Peinture");
    QApplication::setApplicationVersion(APP_VERSION_STR);
    QApplication::setApplicationDisplayName("Peinture");
    QApplication::setOrganizationName("Kreogist Dev Team");
    QApplication::setOrganizationDomain("http://kreogist.github.io/");
    //Configure application attributes.
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);
}
