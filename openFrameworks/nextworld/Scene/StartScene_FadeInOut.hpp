//
//  StartScene_FadeInOut.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#ifndef StartScene_FadeInOut_hpp
#define StartScene_FadeInOut_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"

class StartScene_FadeInOut : public SceneElement {
    void init() override;
    void start() override;
    void update() override;
    void draw() override;
};
#endif /* StartScene_FadeInOut_hpp */
