//
//  BackEffect.hpp
//  presenOpening
//
//  Created by SakuragiYoshimasa on 2016/08/29.
//
//

#ifndef BackEffect_hpp
#define BackEffect_hpp

#include "ofMain.h"

class BackEffect {
public:
    virtual void setup()=0;
    virtual void update()=0;
    virtual void draw()=0;
    
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    virtual void mouseMoved(int x, int y );
    virtual void mouseDragged(int x, int y, int button);
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
};

#endif /* BackEffect_hpp */
