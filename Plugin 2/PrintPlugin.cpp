//
//  PrintPlugin.cpp
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#include "PrintPlugin.h"

using namespace Rogiel;

void PrintPlugin::print(std::string str) {
    std::cout << str << std::endl;
}

PrintPlugin* PluginCreate() {
    std::cout << "## PrintPlugin did load" << std::endl;
    return new PrintPlugin();
}

void PluginDestroy(PrintPlugin* plugin) {
    std::cout << "## PrintPlugin did unload" << std::endl;
    delete plugin;
}