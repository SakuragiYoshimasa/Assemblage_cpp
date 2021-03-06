//
//  TargetMarkerDrawer.cpp
//  MauInteractive
//
//  Created by 櫻木善将 on 2015/10/14.
//
//

#include "TargetMarkerDrawer.h"

void TargetMarkerDrawer::init(float radius){
    for(int i = 0; i < 3; i++){
        insideDrawer.addVertex(ofVec3f( radius * cos(i * 120 / 180.0 * PI), radius * sin(i * 120 / 180.0 * PI), 0));
        for(float deg = 0; deg < 60; deg += 0.5){
            insideDrawer.addVertex(ofVec3f(radius * cos((float(i * 120) + deg) / 180.0 * PI),
                                           radius * sin((float(i * 120) + deg) / 180.0 * PI), 0));
            insideDrawer.addVertex(ofVec3f(radius * cos((float(i * 120) + deg) / 180.0 * PI),
                                           radius * sin((float(i * 120) + deg) / 180.0 * PI), 0));
        }
        insideDrawer.addVertex(ofVec3f(radius * cos((i * 120 + 60) / 180.0 * PI),
                                       radius * sin((i * 120 + 60) / 180.0 * PI), 0));
    }
    for(int i = 0; i < 3; i++){
        outsideDrawer.addVertex(ofVec3f( radius * SCALE_RATE * cos((i * 120) / 180.0 * PI), radius * SCALE_RATE * sin((i * 120) / 180.0 * PI), 0));
        for(float deg = 0; deg < 90; deg += 0.5){
            outsideDrawer.addVertex(ofVec3f(radius * SCALE_RATE * cos((float(i * 120) + deg) / 180.0 * PI),
                                            radius * SCALE_RATE * sin((float(i * 120) + deg) / 180.0 * PI), 0));
            outsideDrawer.addVertex(ofVec3f(radius * SCALE_RATE * cos((float(i * 120) + deg) / 180.0 * PI),
                                            radius * SCALE_RATE * sin((float(i * 120) + deg) / 180.0 * PI), 0));
        }
        outsideDrawer.addVertex(ofVec3f(radius * SCALE_RATE * cos((i * 120 + 90)/ 180.0 * PI),
                                        radius * SCALE_RATE * sin((i * 120 + 90)/ 180.0 * PI), 0));
    }
    insideDrawer.setMode(OF_PRIMITIVE_LINES);
    outsideDrawer.setMode(OF_PRIMITIVE_LINES);
    position = ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    for(int i = 0; i < 5; i++){
        modeFrames[i] = ofRandom(8, 5 + 30 * ((i + 1) % 2));
    }
}

void TargetMarkerDrawer::update(){
    switch (mode) {
        case ROTATE:
            insideDeg += insideSpeed;
            outsideDeg += outsideSpeed;
            break;
        case ROTATE_REVERSE:
            insideDeg -= insideSpeed;
            outsideDeg -= outsideSpeed;
            break;
        default:
            break;
    }
    
    frameCount++;
    if(frameCount > modeFrames[int(mode)]){
        if((int)mode + 1 == 5){
            restart();
            return;
        }
        mode = Mode((int)mode + 1);
        frameCount = 0;
    }
}

void TargetMarkerDrawer::restart(){
    mode = ROTATE;
    frameCount = 0;
    float insideDeg = 0;
    float outsideDeg = 0;
    position = ofVec2f(ofRandom(100,ofGetWidth() -100),ofRandom(90,ofGetHeight() - 90));
    for(int i = 0; i < 5; i++){
        modeFrames[i] = ofRandom(8, 5 + 30 * ((i + 1) % 2));
    }
}

void TargetMarkerDrawer::drawTargetMarker(ofColor tColor){
    if(mode == END) return;
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(position);
    ofSetColor(tColor, 100);
    ofSetLineWidth(8);
    ofRotateZ(insideDeg);
    insideDrawer.draw();
    ofPopMatrix();
    ofPushMatrix();
    ofTranslate(position);
    ofRotateZ(outsideDeg);
    ofSetLineWidth(16);
    ofSetColor(tColor,150);
    outsideDrawer.draw();
    ofPopMatrix();
    ofSetLineWidth(2);
    ofSetColor(0, 255, 255,70);
    ofLine(0, position.y, ofGetWidth(), position.y);
    ofLine(position.x, 0, position.x, ofGetHeight());
    ofPopStyle();
}