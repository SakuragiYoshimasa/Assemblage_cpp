//
//  Manager.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>

class Manager { //Not abstract
public:
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
};
#endif /* Manager_hpp */
