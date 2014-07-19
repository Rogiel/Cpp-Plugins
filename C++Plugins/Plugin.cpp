//
//  Plugin.hpp
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#include "Plugin.h"
#include <dlfcn.h>

using namespace Rogiel;

Plugin::Plugin(std::string file) : file(file), handle(nullptr), instance(nullptr) {
    handle = dlopen(this->file.c_str(), RTLD_GLOBAL);
    if(!handle) {
        throw std::exception();
    }
    creator = (PluginCreator) dlsym(handle, "PluginCreate");
    if(creator == nullptr) {
        dlclose(handle);
        throw "plugin creator not found";
    }
    destroyer = (PluginDestroyer) dlsym(handle, "PluginDestroy");
    if(destroyer == nullptr) {
        dlclose(handle);
        throw "plugin destroyer not found";
    }
    
    try {
        instance = creator();
    } catch(...) {
        dlclose(handle); // ignore errors here
        handle = nullptr;
        throw std::current_exception();
    }
}

Plugin::~Plugin() {
    if(instance) {
        destroyer(instance);
    }
    if(handle) {
        dlclose(handle);
    }
}

void* Plugin::operator->() {
    return instance;
}

void* Plugin::getPlugin() {
    return instance;
}