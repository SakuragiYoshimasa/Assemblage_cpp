//
//  Arrow.cpp
//  ofBoidsSample
//
//  Created by SakuragiYoshimasa on 2015/11/15.
//
//

#include "Arrow.h"

Arrow::Arrow(){
    position = ofVec2f(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
    //position = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    velocity = ofVec2f(ofRandom(-10.0,10.0),ofRandom(-10.0,10.0));
}

