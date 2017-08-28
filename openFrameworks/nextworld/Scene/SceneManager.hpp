//
//  SceneManager.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include "ofMain.h"
#include "Manager.hpp"
#include "Scene.hpp"
#include "StartScene.hpp"
#include "MembersDataAnalysisScene.hpp"
#include "MentorsDataAnalysisScene.hpp"
#include "LastScene.hpp"

class SceneManager : public Manager {
public:
    int sceneIndex = 0;
    
    vector<Scene *> scenes;
    void setup() override;
    void update() override;
    void draw() override;
    void nextScene();
    void keyReleased(int key);
};
#endif /* SceneManager_hpp */
