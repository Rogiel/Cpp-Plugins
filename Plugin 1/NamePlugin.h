//
//  NamePlugin.h
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#ifndef __C__Plugins__NamePlugin__
#define __C__Plugins__NamePlugin__

#include <iostream>
#include "../C++Plugins/MyPluginInterface.h"

namespace Rogiel {
    class NamePlugin : public INamePlugin {
    public:
        virtual std::string getName() override;
    };
}

extern "C" {
    Rogiel::NamePlugin* PluginCreate();
    void PluginDestroy(Rogiel::NamePlugin*);
}

#endif /* defined(__C__Plugins__NamePlugin__) */
