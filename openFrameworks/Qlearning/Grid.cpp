//
//  Grid.cpp
//  Qlearning
//
//  Created by SakuragiYoshimasa on 2016/07/07.
//
//

#include "Grid.hpp"

Grid::Grid(){
    
    for (int i = 0; i < DIRECTION_NUM; i++) {
        Q_value[i] = 0;
    }
    
    _revenue = 0;
    _isWall = false;
    _isGoal = false;
}

bool Grid::isWall(){
    return this->_isWall;
}

bool Grid::isGoal(){
    return this->_isGoal;
}

double Grid::getQvalue(int direction){
    return this->Q_value[direction];
}

void Grid::updateQvalue(DIRECTION d, double Qvalue){
    this->Q_value[d] = Qvalue;
}


void Grid::setWall(){
    _isWall = true;
    _revenue = -1.0;
};

void Grid::setGoal(double revenue){
    _isGoal = true;
    _revenue = revenue;
}

double Grid::getRevenue(){
    return this->_revenue;
}

DIRECTION Grid::getDirection(){
    //Qの値によって返すdirectionを決定する
    //maxにthauを与える
    
    vector<int> maxIndex = *new vector<int>(0);
    maxIndex.push_back(0);
    double maxQ = Q_value[0];
    
    
    for (int i = 1; i < DIRECTION_NUM; i++) {
        if(maxQ < Q_value[i]){
            maxIndex.resize(1);
            maxIndex[0] = i;
            maxQ = Q_value[i];
            
        }else if(maxQ == Q_value[i]){
            maxIndex.push_back(i);
        }
    }
    
    double rand = ofRandom(0.0, 1.0);
    
    double sum = 0.0;
    
    for(int i = 0; i < DIRECTION_NUM; i++){
        for(int k = 0; k < maxIndex.size(); k++){
            if(maxIndex[k] == i){
                sum += THAU / double(maxIndex.size());
                break;
            }
            if(k == maxIndex.size() - 1){
                sum+= (1.0 - THAU) / double(DIRECTION_NUM - maxIndex.size());
                break;
            }
        }
        if(sum > rand){
            return DIRECTION(i);
        }
    }
    return E;
}

double Grid::getMaxQvalue(){
    
    double maxQ = Q_value[0];
    for (int i = 1; i < DIRECTION_NUM; i++) {
        if(maxQ <= Q_value[i]) maxQ = Q_value[i];
    }
    return maxQ;
}

double * Grid::getAllQ(){
    return Q_value;
}