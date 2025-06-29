// Copyright (c) 2017-2024 Manuel Schneider

#pragma once
#include <QStringList>
#include <albert/extensionplugin.h>
#include <albert/indexqueryhandler.h>
#include <albert/notification.h>
#include <albert/property.h>


enum SupportedCommands {
    LOCK,
    LOGOUT,
    SUSPEND,
#if not defined(Q_OS_MAC)
    HIBERNATE,
#endif
    REBOOT,
    POWEROFF
};

struct Command
{
    SupportedCommands id;
    const QString config_key_enabled;
    const QString config_key_title;
    const QString config_key_command;
    const QStringList icon_urls;
    const QString default_title;
    const QString description;
    const QString command;
};


class Plugin : public albert::util::ExtensionPlugin,
               public albert::util::IndexQueryHandler
{
    ALBERT_PLUGIN

public:

    Plugin();

    void updateIndexItems() override;
    QWidget* buildConfigWidget() override;

    const std::vector<Command> commands;

};
