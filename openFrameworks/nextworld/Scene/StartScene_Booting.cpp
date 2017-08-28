//
//  StartScene_Booting.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#include "StartScene_Booting.hpp"

void StartScene_Booting::init(){
    video.load("booting.mov");
    shader.load("shader/chromaKey");
};

void StartScene_Booting::start(){
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofDisableSmoothing();
    ofSetCircleResolution(20);
    ofBackground(0);
    fbo.end();
    ofBackground(0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    fboGlitch.allocate(320, 240);
    glitchFbo.allocate(glitchWidth, glitchHeight);
    ofSetFrameRate(60);
}

void StartScene_Booting::update(){
    video.update();
    float dt = TimeManager::getInstance().getDeltaTime();
    float vel = 0.1;
    for(int i = 0; i < noise2d.size(); i++){
        noise2d.at(i) += ofPoint(vel * dt, vel * dt);
    }
    
    if(noise2d.size() > 100){
        cout << "" << endl;
        fadeOut = true;
        fadeCounter++;
        return;
    }
    if(TimeManager::getInstance().getSpentFrame() % 2 == 0 ){
        noise2d.push_back(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
      //noise2d.push_back(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
    }
}

void StartScene_Booting::draw(){
 
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    ofEnableAlphaBlending();
    
    ofSetColor(255,255,255,255);
    
    fbo.begin();
    glDisable(GL_BLEND);
    ofBackground(0);
    //ofBackgroundGradient(ofColor(0,200,200,150), ofColor(0,0,0));
    pcp.draw(&noise2d);
    ofSetColor(255,255,255,200);
    shader.begin();
    shader.setUniform3f("chromaKeyColor", ofVec3f(0.0, 0, 0.0));
    shader.setUniform1f("threshold", 0.5);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    video.draw(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    fbo.end();
    fbo.draw(0, 0);
    
    glitchFbo.begin();
    ofBackground(0);
    ofBackgroundGradient(ofColor(0,200,200,150), ofColor(0,0,0));
    fboGlitch.draw(fbo, 0, 0, glitchWidth, glitchHeight);
    glitchFbo.end();
    glitchFbo.draw(offsetX, offsetY);
    glitchFbo.draw(ofGetWidth() - glitchWidth - offsetX, offsetY);
    glitchFbo.draw(offsetX, ofGetHeight() - glitchHeight - offsetY);
    glitchFbo.draw(ofGetWidth() - glitchWidth - offsetX, ofGetHeight() - glitchHeight - offsetY);

    if(fadeOut){
        ofSetColor(0, 0, 0, fadeCounter * 20);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
    }
};

void StartScene_Booting::end(){
    video.stop();
    ofSetFrameRate(60);
}