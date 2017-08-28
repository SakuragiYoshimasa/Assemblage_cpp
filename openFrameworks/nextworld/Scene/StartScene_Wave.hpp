//
//  StartScene_Wave.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/29.
//
//

#ifndef StartScene_Wave_hpp
#define StartScene_Wave_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"

#define WAVE_POINT 100

class StartScene_Wave : public SceneElement {
    void init() override;
    void start() override;
    void update() override;
    void draw() override;
    void end() override;
    
    ofMesh wave;
};

#endif /* StartScene_Wave_hpp */
