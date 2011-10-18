/*
    Parent class for Telepathy KDED Plugins
    Copyright (C) 2011  Martin Klapetek <martin.klapetek@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef TELEPATHY_KDED_MODULE_PLUGIN_H
#define TELEPATHY_KDED_MODULE_PLUGIN_H

#include <QObject>
#include <TelepathyQt4/Presence>
#include <TelepathyQt4/AccountManager>

class GlobalPresence;
class TelepathyKDEDModulePlugin : public QObject
{
    Q_OBJECT

public:
    TelepathyKDEDModulePlugin(GlobalPresence *globalPresence, QObject *parent = 0);
    virtual ~TelepathyKDEDModulePlugin();

    bool isActive() const { return m_active; };
    bool isEnabled() const { return m_enabled; };
    int pluginPriority() const { return m_pluginPriority; };

    Tp::Presence requestedPresence() const { return m_requestedPresence; };

Q_SIGNALS:
    void requestPresenceChange(const Tp::Presence &presence);
    void activate(bool);

protected:
    void setActive(bool active);
    void setEnabled(bool enabled);
    void setPluginPriority(int priority) { m_pluginPriority = priority; };
    void setRequestedPresence(const Tp::Presence &presence) { m_requestedPresence = presence; };

    GlobalPresence *m_globalPresence;

private:
    Tp::Presence m_requestedPresence;
    bool m_enabled;
    bool m_active;
    int m_pluginPriority;
};

#endif // TELEPATHY_KDED_MODULE_PLUGIN_H