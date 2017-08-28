//
//  MentorsDataAnalysisScene.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/24.
//
//

#include "MentorsDataAnalysisScene.hpp"

void MentorsDataAnalysisScene::setup(){
    
    ofBackground(0);
    model = ModelManager::getInstance().getMentorsModel();
    cout << "Size:" << model.mentors.size() << endl;;
}

/*void MentorsDataAnalysisScene::update(){
    
}

void MentorsDataAnalysisScene::draw(){
}*/