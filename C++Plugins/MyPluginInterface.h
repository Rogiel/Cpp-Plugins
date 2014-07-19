//
//  MyPluginInterface.h
//  C++Plugins
//
//  Created by Rogiel Sulzbach on 7/19/14.
//  Copyright (c) 2014 Rogiel Sulzbach. All rights reserved.
//

#ifndef C__Plugins_MyPluginInterface_h
#define C__Plugins_MyPluginInterface_h

namespace Rogiel {
    /**
     * A plugin interface that prints a string
     */
    class IPrinterPlugin {
    public:
        /**
         * Prints the string
         */
        virtual void print(std::string str) = 0;
    };
    
    /**
     * A plugin interface that return a name
     */
    class INamePlugin {
    public:
        /**
         * Returns the name
         */
        virtual std::string getName() = 0 ;
    };
}

#endif
