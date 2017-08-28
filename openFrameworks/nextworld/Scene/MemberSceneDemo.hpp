//
//  MemberSceneDemo.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/28.
//
//

#ifndef MemberSceneDemo_hpp
#define MemberSceneDemo_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"
#include "PointCloudPainter.hpp"
#include "ModelManager.hpp"
#include "ofx3DFont.h"

class MemberSceneDemo : public SceneElement {
    void init() override;
    void start() override;
    void update() override;
    void end() override;
    void draw() override;
    
    vector<Member> * members;
    int membersCount;
    
    ofEasyCam cam;
    ofx3DFont font;
    ofLight light;
};

#endif /* MemberSceneDemo_hpp */
