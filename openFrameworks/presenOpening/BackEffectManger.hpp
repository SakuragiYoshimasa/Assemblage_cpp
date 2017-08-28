//
//  BackEffectManger.hpp
//  presenOpening
//
//  Created by SakuragiYoshimasa on 2016/08/29.
//
//

#ifndef BackEffectManger_hpp
#define BackEffectManger_hpp

#include "BackEffect.hpp"
#include "KinectEffect.hpp"

class BackEffectManger {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    vector<BackEffect *> effects;
    int effectIndex = 0;
};

#endif /* BackEffectManger_hpp */
