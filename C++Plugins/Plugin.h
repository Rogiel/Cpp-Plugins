//
//  Plugin.h
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#ifndef __C__Plugins__Plugin__
#define __C__Plugins__Plugin__

#include <iostream>

namespace Rogiel {
    /**
     * This class represents a physical plugin. Each
     * plugin can be loaded or unloaded.
     */
    class Plugin {
    private:
        /**
         * The filename to the plugin dynamic library.
         */
        std::string file;
        
        /**
         * The system native handle that manages the 
         * dynamic library.
         */
        void* handle;
        
        /**
         * The plugin factory method signature. It must
         * be linked with C linkage (extern "C")
         */
        typedef void* (*PluginCreator)();
        /**
         * A pointer poiting to the factory function
         */
        PluginCreator creator;
        
        /**
         * The plugin factory method signature. It must
         * be linked with C linkage (extern "C")
         */
        typedef void(*PluginDestroyer)(void*);
        /**
         * A pointer poiting to the factory function
         */
        PluginDestroyer destroyer;
        
        /**
         * The plugin instance
         */
        void* instance;
        
    public:
        Plugin(std::string file);
        ~Plugin();
        
        void* operator->();
        void* getPlugin();
    };
}

#endif /* defined(__C__Plugins__Plugin__) */
