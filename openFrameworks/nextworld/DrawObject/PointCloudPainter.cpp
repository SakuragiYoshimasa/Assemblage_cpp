//
//  PointCloudPainter.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/25.
//
//

#include "PointCloudPainter.hpp"

void PointCloudPainter::draw(vector<ofPoint> * noise2d){
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    glPushAttrib(GL_ENABLE_BIT);
    glPointSize(15);
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
    ofSetLineWidth(1.0);
    
    ofSetColor(220, 220, 220, 250);
    ofSetColor(255, 255, 255, 250);
    for(int i = 0; i < noise2d->size(); i++){
        for(int j = 0; j < noise2d->size(); j++){
            if(i == j) continue;
            float dist = ofDist(ofSignedNoise(noise2d->at(i).x) * rad,
                                ofSignedNoise(noise2d->at(i).y) * rad,
                                ofSignedNoise(noise2d->at(j).x) * rad,
                                ofSignedNoise(noise2d->at(j).y) * rad);
            if(dist < 50){
                ofDrawLine(ofSignedNoise(noise2d->at(i).x) * rad,
                           ofSignedNoise(noise2d->at(i).y) * rad,
                           ofSignedNoise(noise2d->at(j).x) * rad,
                           ofSignedNoise(noise2d->at(j).y) * rad);
            }
        }
    }
    
    ofSetColor(220, 220, 220, 250);
    ofSetColor(255, 255, 255, 250);
    glBegin(GL_POINTS);
    
    for(int i = 0; i < noise2d->size(); i++){
        glVertex2d(ofSignedNoise(noise2d->at(i).x) * rad,
                   ofSignedNoise(noise2d->at(i).y) * rad);
    }
    glEnd();
    
    glPopAttrib();
    ofPopMatrix();
    ofPopStyle();
}