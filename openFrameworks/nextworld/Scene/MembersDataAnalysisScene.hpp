//
//  MembersDataAnalysisScene.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#ifndef MembersDataAnalysisScene_hpp
#define MembersDataAnalysisScene_hpp

#include "Scene.hpp"
#include "ModelManager.hpp"
#include "MemberSceneDemo.hpp"

class MembersDataAnalysisScene : public Scene {
public:
    void setup() override;
//    void update() override;
//    void draw() override;
    
    MembersModel model;
};

#endif /* MembersDataAnalysisScene_hpp */
