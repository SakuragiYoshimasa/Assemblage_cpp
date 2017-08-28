//
//  StartScene_LineAnim.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/29.
//
//

#include "StartScene_LineAnim.hpp"

void StartScene_LineAnim::init(){
};

void StartScene_LineAnim::start(){
    ofBackground(0);
    elapsedTime = 0;
    /*  ofEnableAlphaBlending();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);*/
}

void StartScene_LineAnim::update(){
    
    if(TimeManager::getInstance().getElapsedTime() > 1.5){
        callback();
    }
}

void StartScene_LineAnim::draw(){
    
    elapsedTime += TimeManager::getInstance().getDeltaTime();
    
    //glPushAttrib(GL_ENABLE_BIT);
   // ofBackgroundGradient(ofColor(0,200,200), ofColor(0,0,0));
    
    ofSetLineWidth(1.0);
    ofPushMatrix();
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    ofSetColor(0, 255, 255, 200);
    ofLine(-elapsedTime * float(ofGetWidth()) ,
           0,
           elapsedTime * float(ofGetWidth()) ,
           0);
    ofLine(0,
           -elapsedTime * float(ofGetHeight()),
           0,
           elapsedTime * float(ofGetHeight()));
    ofSetLineWidth(10.0);
    ofSetColor(0, 255, 255, 100);
    ofLine(-elapsedTime * float(ofGetWidth()) ,
           0,
           elapsedTime * float(ofGetWidth()) ,
           0);
    ofLine(0,
           -elapsedTime * float(ofGetHeight()),
           0,
           elapsedTime * float(ofGetHeight()));
    /*ofNoFill();
    ofCircle(0, 0, 400.0 * elapsedTime);
    ofFill();*/
    ofPopMatrix();
    ofSetColor(0, 0, 0, 100);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    //glPopAttrib();
};

void StartScene_LineAnim::end(){
   // ofSetBackgroundAuto(true);
}