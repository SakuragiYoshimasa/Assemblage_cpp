//
//  StartScene_Circuit.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#include "StartScene_Circuit.hpp"

void StartScene_Circuit::init(){
    
    for(int i = 0; i < CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM; i++){
        points[i] = ofVec3f((i  % CIRCUIT_WIDTH_NUM) * CIRCUIT_POINT_INTERVAL + 10,
                            (i / CIRCUIT_HEIGHT_NUM) * CIRCUIT_POINT_INTERVAL + 10,0);
    }
    reset();
    shader.load("shader/chromaKey");
};

void StartScene_Circuit::start(){
    ofBackground(0);
    //blur.setup(ofGetWidth(), ofGetHeight());
    blur.setup(CIRCUIT_POINT_INTERVAL * CIRCUIT_WIDTH_NUM, CIRCUIT_POINT_INTERVAL * CIRCUIT_HEIGHT_NUM);
    blur.setBrightness(255.0f);
    blur.setScale(10);
    blur.setRotation(0);
    fbo.allocate(CIRCUIT_POINT_INTERVAL * CIRCUIT_WIDTH_NUM, CIRCUIT_POINT_INTERVAL * CIRCUIT_HEIGHT_NUM);
}

void StartScene_Circuit::update(){
    
    for(int n = 0; n < CIRCUIT_NUM; n++){
        if(arrivedNextPoint[n] && addedPoint < CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM){
            if(addedPoint != 1 && addedPoint != CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM) circuit[n].addVertex(targetPoint[n]);
            circuit[n].addVertex(targetPoint[n]);
            lineStartPoint[n] = targetPoint[n];
            arrivedNextPoint[n] = false;
            positionCounter[n] = 0;
            Direction nextDirection = Direction(ofRandom(8));
            for(int i = 0; true; i++){
                if(setNextPoint(nextDirection, n)){break;}
                if(i == 3 && mode == NORMAL){
                    circuit[n].addVertex(targetPoint[n]);
                    setRandomPoint(n);
                    circuit[n].addVertex(targetPoint[n]);
                    break;
                }
                if(i >= 7 && mode != NORMAL){
                    circuit[n].addVertex(targetPoint[n]);
                    setRandomPoint(n);
                    circuit[n].addVertex(targetPoint[n]);
                    break;
                }
                if(nextDirection != RIGHT) {
                    nextDirection = Direction(int(nextDirection) + 1);
                    continue;
                }
                nextDirection = UP;
            }
            addedPoint++;
        }else{
            if(!boxMode){
                positionCounter[n] += ofRandom(0.3, 1.0);
            }else{
                positionCounter[n] += ofRandom(0.1, 0.2);
            }
            if(positionCounter[n] > 1.0){
                arrivedNextPoint[n] = true;
            }
        }
    }
    if(addedPoint == CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM) {
        waitFrames++;
        fadeOut = true;
        if(waitFrames > 30){
           // reset();
        }
    }
    
   /* cam.setPosition(CIRCUIT_POINT_INTERVAL * CIRCUIT_WIDTH_NUM * 0.5, CIRCUIT_POINT_INTERVAL * CIRCUIT_HEIGHT_NUM * 0.5, addedPoint * 0.65);
    cam.lookAt(ofPoint(CIRCUIT_POINT_INTERVAL * CIRCUIT_WIDTH_NUM * 0.5, CIRCUIT_POINT_INTERVAL * CIRCUIT_HEIGHT_NUM * 0.5,0));
    cam.rotate(addedPoint * 0.25, 0, 0, 1.0);*/
};
void StartScene_Circuit::draw(){

   // cam.begin();
    
    glPushAttrib(GL_ENABLE_BIT);
    
    ofEnableAlphaBlending();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    fbo.begin();
    ofEnableSmoothing();
    ofBackground(0);
    //ofBackgroundGradient(ofColor(0,200,200), ofColor(0,0,0));
    ofPushMatrix();
    ofPushStyle();
    ofSetLineWidth(3);
    glPointSize(15);
    glPushAttrib(GL_ENABLE_BIT);
    
    for(int n = 0; n < CIRCUIT_NUM; n++){
        if(randomColor){
            ofSetColor(lineColors[n] ,100);
        }else{
            ofSetColor(100, 255, 255, 255);
            //ofSetColor(100, 255, 255, 100);
        }
        circuit[n].setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
        circuit[n].draw();
        circuit[n].setMode(ofPrimitiveMode::OF_PRIMITIVE_POINTS);
        circuit[n].draw();
    }
    if(addedPoint != CIRCUIT_HEIGHT_NUM * CIRCUIT_WIDTH_NUM){
        ofSetColor(0, 255, 255);
        ofSetLineWidth(1);
        for(int n = 0; n <4; n++){
            if(randomColor){
                ofSetColor(lineColors[n] ,255);
            }else{
                //ofSetColor(100, 255, 255, 255);
                ofSetColor(100, 255, 255, 255);
            }
            ofLine(lineStartPoint[n], lineStartPoint[n] + positionCounter[n] *(targetPoint[n] - lineStartPoint[n]));
        }
    }
    
    ofPopStyle();
    ofPopMatrix();
    glPopAttrib();
    fbo.end();
    ofSetColor(255, 255, 255,255);

    
    //ofSetColor(255, 255, 255, 50);
    
    //fbo.draw(0,0);
    //ofRect(0,0,ofGetWidth(),ofGetHeight());
    blur.begin();
    fbo.draw(0,0);
    blur.end();
    blur.draw();
    
    shader.begin();
    shader.setUniform3f("chromaKeyColor", ofVec3f(0.0, 0, 0.0));
    shader.setUniform1f("threshold", 0.5);
    fbo.draw(0,0);
    shader.end();
    
    glPopAttrib();
    
    if(fadeOut){
        ofSetColor(0,0,0, 15 * waitFrames);
        ofRect(0,0,CIRCUIT_POINT_INTERVAL * CIRCUIT_WIDTH_NUM, CIRCUIT_POINT_INTERVAL * CIRCUIT_HEIGHT_NUM);
        if(waitFrames > 25){
            callback();
        }
    }
    
  //  cam.end();
};

void StartScene_Circuit::end(){
/*    delete[] &circuit;
    delete[] &targetPoint;
    delete[] &lineStartPoint;
    delete[] &points;
    delete[] &lineColors;
    delete &blur;
    delete &fbo;
    delete &shader;
    delete &cam;*/
}


void StartScene_Circuit::reset(){
    for(int i = 0; i < CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM; i++){
        usedPoint[i] = false;
    }
    for(int n = 0; n < CIRCUIT_NUM; n++){
    //    circuit[n].useColors = false;
        circuit[n].clear();
        setRandomPoint(n);
        circuit[n].addVertex(targetPoint[n]);
        arrivedNextPoint[n] = true;
        positionCounter[n] = 0;
        addedPoint = 10;
        
       // lineColors[n].setHsb(ofRandom(120, 240), 255, 255);
        lineColors[n] = ofColor(0, 255, 255);
    }
    waitFrames = 0;
}



bool StartScene_Circuit::setNextPoint(Direction nextDirection, int n){
    switch (nextDirection) {
            
        case UP:
            if(!(mode == NORMAL || mode == VERTICAL)) return false;
            if((nextIndex[n] - CIRCUIT_WIDTH_NUM > 0) && (!usedPoint[nextIndex[n] - CIRCUIT_WIDTH_NUM]))
            {
                nextIndex[n] = nextIndex[n] - CIRCUIT_WIDTH_NUM;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        case DOWN:
            if(!(mode == NORMAL || mode == VERTICAL)) return false;
            if((nextIndex[n] + CIRCUIT_WIDTH_NUM < CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM) && (!usedPoint[nextIndex[n] + CIRCUIT_WIDTH_NUM]))
            {
                nextIndex[n] = nextIndex[n] + CIRCUIT_WIDTH_NUM;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        case RIGHT:
            if(!(mode == NORMAL || mode == HORIZONTAL)) return false;
            if((nextIndex[n] + 1 < CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM) && (!usedPoint[nextIndex[n] + 1]) && ((nextIndex[n] + 1) % CIRCUIT_WIDTH_NUM != 0))
            {
                nextIndex[n] = nextIndex[n] + 1;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        case LEFT:
            if(!(mode == NORMAL || mode == HORIZONTAL)) return false;
            if(nextIndex[n] - 1 > 0 && !usedPoint[nextIndex[n] -1] && (nextIndex[n] - 1) % CIRCUIT_WIDTH_NUM != CIRCUIT_WIDTH_NUM - 1)
            {
                nextIndex[n] = nextIndex[n] - 1;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        case UP_RIGHT:
            if(!(mode == NORMAL || mode == RIGHT_UP || mode == CROSS)) return false;
            if(nextIndex[n] - CIRCUIT_WIDTH_NUM + 1 > 0
               && !usedPoint[nextIndex[n] - CIRCUIT_WIDTH_NUM + 1]
               && (nextIndex[n] - CIRCUIT_WIDTH_NUM + 1) % CIRCUIT_WIDTH_NUM != 0)
            {
                nextIndex[n] = nextIndex[n] - CIRCUIT_WIDTH_NUM + 1;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        case UP_LEFT:
            if(!(mode == NORMAL || mode == LEFT_UP || mode == CROSS)) return false;
            if(nextIndex[n] - CIRCUIT_WIDTH_NUM - 1  > 0
               && !usedPoint[nextIndex[n] - CIRCUIT_WIDTH_NUM - 1]
               && (nextIndex[n] - CIRCUIT_WIDTH_NUM - 1) % CIRCUIT_WIDTH_NUM != CIRCUIT_WIDTH_NUM - 1)
            {
                nextIndex[n] = nextIndex[n] - CIRCUIT_WIDTH_NUM - 1;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        case DOWN_RIGHT:
            if(!(mode == NORMAL || mode == LEFT_UP || mode == CROSS)) return false;
            if(nextIndex[n] + CIRCUIT_WIDTH_NUM + 1 < (CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM)
               && !usedPoint[nextIndex[n] + CIRCUIT_WIDTH_NUM + 1]
               && (nextIndex[n] + CIRCUIT_WIDTH_NUM + 1) % CIRCUIT_WIDTH_NUM != 0)
            {
                nextIndex[n] = nextIndex[n] + CIRCUIT_WIDTH_NUM + 1;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        case DOWN_LEFT:
            if(!(mode == NORMAL || mode == RIGHT_UP || mode == CROSS)) return false;
            if(nextIndex[n] + CIRCUIT_WIDTH_NUM - 1 < (CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM)
               && !usedPoint[nextIndex[n] + CIRCUIT_WIDTH_NUM - 1]
               && (nextIndex[n] + CIRCUIT_WIDTH_NUM - 1) % CIRCUIT_WIDTH_NUM != CIRCUIT_WIDTH_NUM - 1)
            {
                nextIndex[n] = nextIndex[n] + CIRCUIT_WIDTH_NUM - 1;
                targetPoint[n] = points[nextIndex[n]];
                usedPoint[nextIndex[n]] = true;
                return true;
            }
            break;
        default:
            break;
    }
    return false;

}

void StartScene_Circuit::setRandomPoint(int n){
    int randomIndex = (int)ofRandom(CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM);
    while(usedPoint[randomIndex]){
        randomIndex++;
        if(randomIndex == CIRCUIT_WIDTH_NUM * CIRCUIT_HEIGHT_NUM) randomIndex = 0;
    }
    nextIndex[n] = randomIndex;
    targetPoint[n] = points[nextIndex[n]];
    lineStartPoint[n] = targetPoint[n];
    usedPoint[nextIndex[n]] = true;
    //lineColors[n].setHsb(ofRandom(120, 240), 255, 255);
}


void StartScene_Circuit::changeMode(Mode nextMode){
    mode = nextMode;
}