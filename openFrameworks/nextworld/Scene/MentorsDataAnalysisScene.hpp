//
//  MentorsDataAnalysisScene.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/24.
//
//

#ifndef MentorsDataAnalysisScene_hpp
#define MentorsDataAnalysisScene_hpp

#include "Scene.hpp"
#include "ModelManager.hpp"

class MentorsDataAnalysisScene : public Scene {
public:
    void setup() override;
 //   void update() override;
 //   void draw() override;
    
    MentorsModel model;
};

#endif /* MentorsDataAnalysisScene_hpp */
