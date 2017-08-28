//
//  MemberSceneDemo.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/28.
//
//

#include "MemberSceneDemo.hpp"

void MemberSceneDemo::init(){
    members = &ModelManager::getInstance().getMembersModel().members;
    membersCount = members->size();
    
    
    cam.lookAt(ofPoint(0,0,0));
    cam.setPosition(ofPoint(200,100,0));
    
    font.loadFont("Fonts/Gidole-Regular.ttf",20,true,true,0.3f,0,true);
    font.loadSubFont("Fonts/KozGoPro-Light.otf");
    font.loadSubFont("Fonts/Futura.ttc");
    font.loadSubFont("Fonts/FiraCode-Regular.otf");
    font.loadSubFont("Geeza Pro",1,-0.04,0x0600,0x06FF,"arab");
    font.useProportional(true);
    font.useVrt2Layout(true);
    font.setLineHeight(font.getFontSize()*1.5);
    light.setPosition(0,0,0);
    light.lookAt(ofPoint(0,1.0,0));
}

void MemberSceneDemo::start(){
    ofBackground(0, 0, 0);
    glCullFace(GL_BACK);//裏面をカリング
    glEnable(GL_DEPTH_TEST);
}

void MemberSceneDemo::update(){
    
}


void MemberSceneDemo::draw(){
    
    cam.begin();
    float deg = TWO_PI / float(membersCount);
    float rad = 500;

    light.enable();
    
    for(int i = 0; i < membersCount; i++){

       // ofSetColor(ofColor::fromHsb(members->at(i).course * 15, 255, 255),150);
        ofSetColor(0,200,255,150);
        ofPoint p = ofPoint(rad * cos(deg * float(i)), 0, rad * sin(deg * float(i)));
        ofPushMatrix();
        glPushMatrix();
        ofDrawLine(p, p + ofPoint(0, 30.0, 0) * members->at(i).grade);
        ofDrawLine(ofPoint(0,0,0) + ofPoint(0, 30.0, 0) * members->at(i).grade,  p + ofPoint(0, 30.0, 0) * members->at(i).grade);

        ofSetColor(255, 255, 255, 255);
        glTranslated(p.x, 0, p.z);
        glRotatef(90.0f,1.0,0,0);
        glRotatef(float(i) / float(membersCount) * 360.0f , 0, 0, 1.0);
        
        //
       
        font.drawString("Course", 0, 0);
        glPopMatrix();
        ofPopMatrix();
    }
    
    light.disable();
    
    cam.end();
}

void MemberSceneDemo::end(){
    
}
