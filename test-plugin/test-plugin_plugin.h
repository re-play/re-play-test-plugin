#pragma once

#include <QQmlExtensionPlugin>

#include <core/plugins/iplugin.h>
#include <core/plugins/ipluginterface.h>

namespace RePlay
{
    namespace TestPlugin
    {
        class Test_PluginPlugin : public QQmlExtensionPlugin, public Core::Plugins::IPlugin
        {
            Q_OBJECT
            Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

        public:

            Test_PluginPlugin()
                : Core::Plugins::IPlugin("TestPlugin", "0.1")
            {

            }

            // ----------------------------------------
            // - QML meta types
            // ----------------------------------------
            void registerTypes(const char *uri);


            // ------------------------------------
            // - Virtual interfaces implementation
            // ------------------------------------
            void initializeInterfaces() override;
            void initialize() override;
        };
    }
}

