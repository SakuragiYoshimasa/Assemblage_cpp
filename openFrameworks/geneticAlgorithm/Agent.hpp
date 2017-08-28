//
//  Agent.hpp
//  GeneticAlgorithmSample
//
//  Created by SakuragiYoshimasa on 2016/04/20.
//
//

#ifndef Agent_hpp
#define Agent_hpp

#include "ofMain.h"

#define PATTERN_NUM 50

class Agent {
public:
    ofVec2f speed;
    ofVec2f pos;
    
    unsigned int accePattern[PATTERN_NUM];
    unsigned int index;
    
    
    Agent();
    void update();
    void init();
};
#endif /* Agent_hpp */
