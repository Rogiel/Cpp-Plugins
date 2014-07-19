//
//  main.cpp
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#include <iostream>
#include "Plugin.h"
#include "MyPluginInterface.h"

using namespace Rogiel;

int main(int argc, const char * argv[]) {
    // loads 2 plugins
    Plugin plugin1("libPlugin1.dylib");
    Plugin plugin2("libPlugin2.dylib");
    
    // get the plugin class and cast it to our interfaces
    INamePlugin* namePlugin = reinterpret_cast<INamePlugin*>(plugin1.getPlugin());
    IPrinterPlugin* printerPlugin = reinterpret_cast<IPrinterPlugin*>(plugin2.getPlugin());
    
    // tells the printer to print the name
    printerPlugin->print(namePlugin->getName());
    
    return 0;
}
