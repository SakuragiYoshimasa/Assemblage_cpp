//
//  StartScene_Wave.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/29.
//
//

#include "StartScene_Wave.hpp"


void StartScene_Wave::init(){
    
    float deltaX = float(ofGetWidth()) / float(WAVE_POINT);
    float elapsedTime = TimeManager::getInstance().getElapsedTime();
    for(float i = 0; i < WAVE_POINT; i++){
        wave.addVertex(ofPoint(i * deltaX, sin(i * deltaX + elapsedTime )) * 100.0);
    }
};

void StartScene_Wave::start(){
    ofBackground(0);
}

void StartScene_Wave::update(){
    float deltaX = float(ofGetWidth()) / float(WAVE_POINT);
    float elapsedTime = TimeManager::getInstance().getElapsedTime();
    for(float i = 0; i < WAVE_POINT; i++){
        float theta = i * deltaX * 0.03 + elapsedTime * 4.0;
        wave.setVertex( i, ofPoint(i * deltaX, (sin(theta + sin(elapsedTime * 10.0 + i * 0.01)) + sin(3.0 * theta + cos(elapsedTime * 10.0)) + sin(4.0 * theta + 2 * sin(elapsedTime * 7.0 + i * 0.01))) * 60.0));
    }
    
    if(elapsedTime > 2.0){
        callback();
    }
}

void StartScene_Wave::draw(){
    //ofBackgroundGradient(ofColor(0,200,200), ofColor(0,0,0));
    ofSetColor(0, 200, 255, 80);
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(1, 0x00FF);
    ofSetLineWidth(10.0);
    ofLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    ofSetLineWidth(1.0);
    ofSetColor(0, 255, 255, 200);
    ofSetLineWidth(1.0);
    ofLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    ofSetLineWidth(1.0);
    glPointSize(6.0);
    ofPushMatrix();
    ofTranslate(0, ofGetHeight()/2);
    ofSetColor(0, 255, 255, 150);
    wave.setMode(OF_PRIMITIVE_POINTS);
    wave.draw();
    wave.setMode(OF_PRIMITIVE_LINE_STRIP);
    wave.draw();
    ofPopMatrix();
    glPopAttrib();
};

void StartScene_Wave::end(){
    delete &wave;
}