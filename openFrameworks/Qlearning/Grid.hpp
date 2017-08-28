//
//  Grid.hpp
//  Qlearning
//
//  Created by SakuragiYoshimasa on 2016/07/07.
//
//

#ifndef Grid_hpp
#define Grid_hpp

#include "ofMain.h"

#define DIRECTION_NUM 4
#define THAU 0.5


enum DIRECTION {
    S = 0,
    N = 1,
    E = 2,
    W = 3
};


class Grid {
private:
    bool _isWall;
    bool _isGoal;
    double _revenue;
    double Q_value[DIRECTION_NUM];
    
public:
    Grid();
    
    void updateQvalue(DIRECTION d, double Qvalue);
    void setWall();
    void setGoal(double revenue);
    bool isWall();
    bool isGoal();
    double getQvalue(int direction);
    double getRevenue();
    double getMaxQvalue();
    double * getAllQ();
    
    DIRECTION getDirection();
};

#endif /* Grid_hpp */
