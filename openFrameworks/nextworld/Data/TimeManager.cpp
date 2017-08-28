//
//  TimeManager.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#include "TimeManager.hpp"

void TimeManager::setup(){
    spentFrame = 0;
    deltaTime  = 0;
    ElapesedTimef = 0;
}

void TimeManager::update(){
    spentFrame++;
    deltaTime = ofGetElapsedTimef() - ElapesedTimef;
    ElapesedTimef += deltaTime;
}