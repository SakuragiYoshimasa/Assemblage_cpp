//
//  GridManager.cpp
//  Qlearning
//
//  Created by SakuragiYoshimasa on 2016/07/07.
//
//

#include "GridManager.hpp"

GridManager::GridManager(){
    
    //-------------------------------------------
    //Initialize
    //-------------------------------------------
    for(int i = 0; i < WIDTH; i++){
        this->feild.push_back(*new vector<Grid>);
        for(int j = 0; j < HEIGHT; j++){
            this->feild[i].push_back(*new Grid);
        }
    }
    

    for(int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++) {
            if( (i == 0) || (i == WIDTH - 1) || (j == 0) || (j == HEIGHT - 1) ){
                this->feild[i][j].setWall();
            }
        }
    }
    this->position = *new Position(1, 1);
    this->step = 0;
    this->loop = 0;
    this->minLoop = 200000;
    
    this->chartMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    for(int i = 0; i < 4; i++){
        this->chartMesh.addVertex(ofPoint(0,0,0));
        this->chartMesh.addColor(ofColor::fromHsb(60 * i, 255, 255));
    }
    
    this->chartMesh.addIndex(0);
    this->chartMesh.addIndex(1);
    this->chartMesh.addIndex(2);
    this->chartMesh.addIndex(0);
    this->chartMesh.addIndex(3);
    this->chartMesh.addIndex(2);
    
    
    //---------------------------------
    //SETTING GOAL AND WALL
    //---------------------------------
    this->feild[2][5].setGoal(1.0);
    this->feild[5][5].setGoal(2.0);
    
    feild[3][2].setWall();
    feild[4][2].setWall();
    feild[5][2].setWall();
    feild[2][4].setWall();
    feild[3][4].setWall();
    feild[4][4].setWall();
    feild[5][4].setWall();

}

void GridManager::update(){
    
    DIRECTION direction = feild[position.x][position.y].getDirection();
    Position nextPosition = position + directionToPosition(direction);
    
    //----------------------------
    //Update Q value
    //----------------------------
    double newQ = (1.0 - ALPHA) * feild[position.x][position.y].getQvalue(direction) + ALPHA * (feild[nextPosition.x][nextPosition.y].getRevenue() + GANNMA * feild[nextPosition.x][nextPosition.y].getMaxQvalue());
    
    feild[position.x][position.y].updateQvalue(direction, newQ);
    
    
    //----------------------------
    //Move if not wall
    //----------------------------
    if(!feild[nextPosition.x][nextPosition.y].isWall()){
        this->position = nextPosition;
    }else{

    }
    
    loop++;
    
    //----------------------------
    //reset if goal
    //----------------------------
    if(feild[nextPosition.x][nextPosition.y].isGoal()){
        step++;
        reset();
        if(loop < minLoop && feild[nextPosition.x][nextPosition.y].getRevenue() > 1.5) minLoop = loop;
        loop = 0;
    }
}

void GridManager::draw(){
    
    ofBackground(255, 255, 255);
    
    //-------------------------------------------
    //Gridの描画
    //-------------------------------------------
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(50, 50);
    ofFill();
    
    for (int i = 0; i < WIDTH; i++) {
        
        ofLine(i * GRID_SIZE, 0, i * GRID_SIZE, GRID_SIZE * HEIGHT);
        
        for(int j = 0; j < HEIGHT; j++){
            
            
            if(i == 1 && j == 1){
                ofSetColor(255, 0, 0);
            }else if(feild[i][j].isGoal()){
                ofSetColor(0, 100 * feild[i][j].getRevenue(), 0);
            }else if(feild[i][j].isWall()){
                ofSetColor(100, 100, 100);
            }else{
                ofSetColor(255, 255, 255);
            }
            
            ofRect(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE);
            
            ofSetColor(0, 0, 0);
            ofLine(0, i * GRID_SIZE, GRID_SIZE * WIDTH, i * GRID_SIZE);
        }
    }

    for (int i = 0; i < WIDTH; i++) {
        ofLine(i * GRID_SIZE, 0, i * GRID_SIZE, GRID_SIZE * HEIGHT);
        for(int j = 0; j < HEIGHT; j++){
            ofSetColor(0, 0, 0);
            ofLine(0, i * GRID_SIZE, GRID_SIZE * WIDTH, i * GRID_SIZE);
        }
    }

    ofSetColor(255, 255, 0);
    ofRect(position.x * GRID_SIZE, position.y * GRID_SIZE, GRID_SIZE, GRID_SIZE);
    
    ofPopMatrix();
    ofPopStyle();
    
    //-------------------------------------------
    //Q値の描画
    //-------------------------------------------
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(100 + GRID_SIZE * WIDTH, 50);
    ofSetColor(50, 50, 50);
    ofRect(0, 0, GRID_SIZE * WIDTH, GRID_SIZE * HEIGHT);
    
    
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            if(feild[i][j].isWall()) continue;
            
            ofPushMatrix();
            ofTranslate(i * GRID_SIZE + 3, j * GRID_SIZE + 3);
            
            ofSetColor(255, 255, 255);
            ofRect(0, 0, GRID_SIZE - 6, GRID_SIZE - 6);
            
            double * q = feild[i][j].getAllQ();
            
            
            
            chartMesh.setVertex(0, ofPoint(0, -20.0 * q[1]));
            chartMesh.setVertex(1, ofPoint(-20.0 * q[3], 0));
            chartMesh.setVertex(2, ofPoint(0, 20.0 * q[0]));
            chartMesh.setVertex(3, ofPoint(20.0 * q[2], 0));
            
            ofTranslate( (GRID_SIZE - 6) / 2.0, (GRID_SIZE - 6) / 2.0);
            chartMesh.draw();
            
            ofPopMatrix();
        }
    }
    
    ofPopMatrix();
    ofPopStyle();
    
    
    //-------------------------------------------
    //Loop 回数の表示
    //-------------------------------------------
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(100, 150 + GRID_SIZE * (HEIGHT - 1));
    ofSetColor(0, 0, 0);
    
    ofDrawBitmapString("STEP:" + ofToString(step) , 0, 0);
    ofDrawBitmapString("LOOP:" + ofToString(loop) , 0, 50);
    ofDrawBitmapString("MINL:" + ofToString(minLoop) , 0, 100);
    
    ofPopMatrix();
    ofPopStyle();
}

void GridManager::reset(){
    this->position.reset();
}

Position GridManager::directionToPosition(DIRECTION direction){

    switch (direction) {
        case N:
            return Position(0, -1);
            break;
        case S:
            return Position(0, 1);
            break;
        case W:
            return Position(-1, 0);
            break;
        case E:
            return Position(1, 0);
            break;
        default:
            return Position(1, 0);
            break;
    }
}