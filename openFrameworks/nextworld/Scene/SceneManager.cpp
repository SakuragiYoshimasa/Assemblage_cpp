//
//  SceneManager.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#include "SceneManager.hpp"

void SceneManager::setup(){
    scenes.push_back(new StartScene());
    scenes.push_back(new LastScene());
    for(int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
}

void SceneManager::update(){
    scenes[sceneIndex]->update();
}

void SceneManager::draw(){
    scenes[sceneIndex]->draw();
}

void SceneManager::keyReleased(int key){
    if(key == ' '){
        sceneIndex++;
    }
}