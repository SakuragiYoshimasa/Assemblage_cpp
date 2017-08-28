//
//  StartScene_FadeInOut.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#include "StartScene_FadeInOut.hpp"


void StartScene_FadeInOut::init(){
};

void StartScene_FadeInOut::start(){
    ofBackground(0);
}

void StartScene_FadeInOut::update(){
}

void StartScene_FadeInOut::draw(){
    //ofBackgroundGradient(ofColor(0,200,200), ofColor(0,0,0));
    int alpha = 150.0 * cos(ofMap(TimeManager::getInstance().getElapsedTime(), 0, 1.5, 0, TWO_PI));
    
    ofSetColor(100, 255, 255, alpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

    if(TimeManager::getInstance().getElapsedTime() > 1.0){
        cout << TimeManager::getInstance().getElapsedTime() << endl;
        callback();
    }
};