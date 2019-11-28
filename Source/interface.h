/*
  ==============================================================================

    interface.h
    Created: 6 Sep 2019 12:37:44pm
    Author:  Jack Devlin

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class PluginScanner {
public:
    PluginScanner();

    bool nextPlugin();

    const char* getFileOrIdentifier(int index) const;
    const char* getManufacturer(int index) const;
    const char* getName(int index) const;
    int getNumPlugins() const;

private:
    KnownPluginList _pluginList;
};

// Expose C interface for Python
// (attribute needed to prevent symbols being stripped from Release builds)
extern "C" {

    __attribute__((visibility("default")))
    PluginScanner* PluginScanner_new() {
        return new PluginScanner();
    }

    __attribute__((visibility("default")))
    const char* PluginScanner_getFileOrIdentifier(PluginScanner* self, int index) {
        return self->getFileOrIdentifier(index);
    }

    __attribute__((visibility("default")))
    const char* PluginScanner_getManufacturer(PluginScanner* self, int index) {
        return self->getManufacturer(index);
    }

    __attribute__((visibility("default")))
    const char* PluginScanner_getName(PluginScanner* self, int index) {
        return self->getName(index);
    }

    __attribute__((visibility("default")))
    int PluginScanner_getNumPlugins(PluginScanner* self) {
        return self->getNumPlugins();
    }
}
