//
//  SampleSceneElement.cpp
//  SceneManagerSample
//
//  Created by 櫻木善将 on 2015/10/26.
//
//

#include "SampleSceneElement.h"

SampleSceneElement::SampleSceneElement(){
    this->backgroundColor = ofColor::fromHsb(ofRandom(255), 255, 255);
}

void SampleSceneElement::draw(){
    ofBackground(backgroundColor);
}