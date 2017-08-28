//
//  Agent.cpp
//  GeneticAlgorithmSample
//
//  Created by SakuragiYoshimasa on 2016/04/20.
//
//

#include "Agent.hpp"

Agent::Agent(){

    for(int i = 0; i < PATTERN_NUM; i++){
        accePattern[i] = int(ofRandom(0, 9));
    }
    index = 0;
}

void Agent::init(){
    pos = ofVec2f(0,0);
    speed = ofVec2f(0,0);
    index = 0;
}

void Agent::update(){
    speed += ofVec2f(cos(float(accePattern[index]) * PI / 4.0 ),
                     sin(float(accePattern[index]) * PI / 4.0 ));
    
    pos += speed;
    index = (index + 1) % PATTERN_NUM;
}