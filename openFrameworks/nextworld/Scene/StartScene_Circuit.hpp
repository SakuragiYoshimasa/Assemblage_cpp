//
//  StartScene_Circuit.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#ifndef StartScene_Circuit_hpp
#define StartScene_Circuit_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"
#include "ofxBlur.h"

#define CIRCUIT_POINT_INTERVAL 50
#define CIRCUIT_WIDTH_NUM 24
#define CIRCUIT_HEIGHT_NUM 24
#define CIRCUIT_NUM 10

class StartScene_Circuit : public SceneElement {
public:
    void init() override;
    void start() override;
    void update() override;
    void end() override;
    void draw() override;
    
    
    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        UP_RIGHT,
        UP_LEFT,
        DOWN_RIGHT,
        DOWN_LEFT
    };
    
    enum Mode{
        NORMAL,
        HORIZONTAL,
        VERTICAL,
        RIGHT_UP,
        LEFT_UP,
        CROSS
    };
    
    void setRandomPoint(int n);
    void changeMode(Mode nextMode);
    void reset();
    bool setNextPoint(Direction nextDirection, int n);

    
    ofVboMesh circuit[CIRCUIT_NUM];
    ofVec3f targetPoint[CIRCUIT_NUM];
    ofVec3f lineStartPoint[CIRCUIT_NUM];
    ofVec3f points[CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM];
    ofColor lineColors[CIRCUIT_NUM];
    
    Mode mode = NORMAL;
    ofxBlur blur;
    ofFbo fbo;
    ofShader shader;
    ofCamera cam;
    

    int nextIndex[CIRCUIT_NUM];
    int addedPoint;
    int waitFrames;
    bool usedPoint[CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM];
    bool arrivedNextPoint[CIRCUIT_NUM];
    bool randomColor = true;
    float positionCounter[CIRCUIT_NUM]; //0~1
    bool boxMode = false;
    
    bool fadeOut = false;
};

#endif /* StartScene_Circuit_hpp */
