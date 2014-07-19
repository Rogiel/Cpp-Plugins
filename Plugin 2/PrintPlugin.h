//
//  PrintPlugin.h
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#ifndef __C__Plugins__PrintPlugin__
#define __C__Plugins__PrintPlugin__

#include <iostream>
#include "../C++Plugins/MyPluginInterface.h"

namespace Rogiel {
    class PrintPlugin : public IPrinterPlugin {
    public:
        virtual void print(std::string str) override;
    };
}

extern "C" {
    Rogiel::PrintPlugin* PluginCreate();
    void PluginDestroy(Rogiel::PrintPlugin*);
}

#endif /* defined(__C__Plugins__PrintPlugin__) */
