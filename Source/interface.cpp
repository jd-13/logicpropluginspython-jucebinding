/*
  ==============================================================================

    interface.cpp
    Created: 6 Sep 2019 12:37:44pm
    Author:  Jack Devlin

  ==============================================================================
*/


#include "interface.h"

namespace {
    void scanPlugins(PluginDirectoryScanner& scanner) {
        String pluginName;
        
        while (true) {
            const String nextName = scanner.getNextPluginFileThatWillBeScanned();
            
            if (!scanner.scanNextFile(true, pluginName)) {
                break;
            }
        }
    }
}

PluginScanner::PluginScanner() {
    
    AudioUnitPluginFormat aupf;
    PluginDirectoryScanner scanner(_pluginList,
                                   aupf,
                                   aupf.getDefaultLocationsToSearch(),
                                   true,
                                   File());
    
    scanPlugins(scanner);
}

const char* PluginScanner::getFileOrIdentifier(int index) const {
    return static_cast<const char*>(_pluginList.getType(index)->fileOrIdentifier.toUTF8());
}

const char* PluginScanner::getManufacturer(int index) const {
    return static_cast<const char*>(_pluginList.getType(index)->manufacturerName.toUTF8());
}

const char* PluginScanner::getName(int index) const {
    return static_cast<const char*>(_pluginList.getType(index)->descriptiveName.toUTF8());
}

int PluginScanner::getNumPlugins() const {
    return _pluginList.getNumTypes();
}
