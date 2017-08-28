//
//  StartScene.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/25.
//
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include "Scene.hpp"
#include "ofMain.h"
#include "PointCloudPainter.hpp"
#include "StartScene_FadeInOut.hpp"
#include "StartScene_LineAnim.hpp"
#include "StartScene_Wave.hpp"
#include "StartScene_Circuit.hpp"
#include "StartScene_Booting.hpp"

class StartScene : public Scene {
public:
    void setup() override;
};

#endif /* StartScene_hpp */
