#include "test-plugin_plugin.h"
#include "test.h"

#include <qqml.h>

using namespace RePlay::Core::Plugins;

namespace RePlay
{
    namespace TestPlugin
    {

        void Test_PluginPlugin::registerTypes(const char *uri)
        {
            // @uri RePlay.TestPlugin
            qmlRegisterType<Test>(uri, 1, 0, "Test");
        }

        void Test_PluginPlugin::initializeInterfaces()
        {
            addInterface(new IPlugInterface("TestInterface"));
        }

        void Test_PluginPlugin::initialize()
        {

        }
    }
}
