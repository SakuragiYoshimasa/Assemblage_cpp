//
//  LastScene_StreamShader.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/03/04.
//
//

#include "LastScene_StreamShader.hpp"

void LastScene_StreamShader::init(){
    shader.load("shader/shader");
}
void LastScene_StreamShader::draw(){
    ofPushMatrix();
    ofSetColor(255, 255 ,255);
    shader.begin();
    shader.setUniform1f("u_time", TimeManager::getInstance().getElapsedTime());
    shader.setUniform2f("u_resolution", ofVec2f(ofGetWidth(),ofGetHeight()));
    ofRect(-ofGetWidth()*0.5 ,-ofGetHeight() * 0.5,ofGetWidth(),ofGetHeight());
    shader.end();
    ofPopMatrix();
}