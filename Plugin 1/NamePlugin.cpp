//
//  NamePlugin.cpp
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#include "NamePlugin.h"

using namespace Rogiel;

std::string NamePlugin::getName() {
    return "Rogiel";
}

NamePlugin* PluginCreate() {
    std::cout << "## NamePlugin did load" << std::endl;
    return new NamePlugin();
}

void PluginDestroy(NamePlugin* plugin) {
    std::cout << "## NamePlugin did unload" << std::endl;
    delete plugin;
}