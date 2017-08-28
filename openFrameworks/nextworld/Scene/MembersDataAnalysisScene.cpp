//
//  MembersDataAnalysisScene.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#include "MembersDataAnalysisScene.hpp"

void MembersDataAnalysisScene::setup(){
    
    /*ofBackground(0);
    model = ModelManager::getInstance().getMembersModel();
    cout << "Size:" << model.members.size() << endl;
    */
    elements.push_back(new MemberSceneDemo());

    for(int i = 0; i < elements.size(); i++){
        elements[i]->init();
        
        function<void(void)> cb = [&]{
            nextElement();
        };
        elements[i]->callback = cb;
    }
    elements[0]->start();
}
/*
void MembersDataAnalysisScene::update(){
    
}

void MembersDataAnalysisScene::draw(){
}*/