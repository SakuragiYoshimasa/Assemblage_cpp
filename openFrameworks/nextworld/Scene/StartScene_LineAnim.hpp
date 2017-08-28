//
//  StartScene_LineAnim.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/29.
//
//

#ifndef StartScene_LineAnim_hpp
#define StartScene_LineAnim_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"
#include "ofxBlur.h"


class StartScene_LineAnim : public SceneElement {
    void init() override;
    void start() override;
    void update() override;
    void draw() override;
    void end() override;
    
    float elapsedTime;
};

#endif /* StartScene_LineAnim_hpp */
