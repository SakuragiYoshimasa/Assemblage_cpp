//
//  MemberScene.cpp
//  NextWorld
//
//  Created by HirokiNaganuma on 2016/02/24.
//
//

#include "MemberDataAnalysisScene.hpp"

void MemberDataAnalysisScene::setup(){
    ModelManager::getInstance().membersModel.load_data();
}

void MemberDataAnalysisScene::update(){
    for(int i = 0 ;i<ModelManager::getInstance().membersModel.members.size() ; i++){
        ModelManager::getInstance().membersModel.members.at(i).update();
    }
}

void MemberDataAnalysisScene::draw(){
    for(int i = 0 ;i<ModelManager::getInstance().membersModel.members.size() ; i++){
        ModelManager::getInstance().membersModel.members.at(i).draw();
    }
}