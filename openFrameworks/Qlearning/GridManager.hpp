//
//  GridManager.hpp
//  Qlearning
//
//  Created by SakuragiYoshimasa on 2016/07/07.
//
//

#ifndef GridManager_hpp
#define GridManager_hpp

#include "Grid.hpp"
#include "ofMain.h"

#define WIDTH 8
#define HEIGHT 8

#define ALPHA 0.1
#define GANNMA 0.9

#define GRID_SIZE 70

struct Position {
    int x = 0;
    int y = 0;
    
    Position(int _x, int _y){
        this->x = _x;
        this->y = _y;
    }
    
    void reset(){
        this->x = 1;
        this->y = 1;
    }
    
    Position operator +(Position p){
        return Position(this->x + p.x, this->y + p.y);
    }
};


class GridManager {
private:
    int step;
    int loop;
    int minLoop;
    vector< vector<Grid> > feild;
    Position position = Position(1, 1);
    ofMesh chartMesh;
    
public:
    
    GridManager();
    
    void reset();
    void update();
    void draw();
    
    Position directionToPosition(DIRECTION direction);
};
#endif /* GridManager_hpp */
