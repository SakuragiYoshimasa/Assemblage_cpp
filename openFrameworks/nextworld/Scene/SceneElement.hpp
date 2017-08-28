//
//  SceneElement.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#ifndef SceneElement_hpp
#define SceneElement_hpp

#include "ofMain.h"
#include <stdio.h>
#include <functional>

class SceneElement {
public:
    
    
    function<void(void)> callback;
    void setCallBack(function<void(void)> & cb){
        callback = cb;
    };
    
    virtual void init(){};
    virtual void start(){};
    virtual void stop(){};
    virtual void update(){};
    virtual void draw()=0;
    virtual void end(){};
    
    virtual void keyReleased(int key){};
    virtual void mouseReleased(int x, int y, int button){};
};

#endif /* SceneElement_hpp */
