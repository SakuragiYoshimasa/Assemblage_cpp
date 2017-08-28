//
//  PointCloudPainter.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/25.
//
//

#ifndef PointCloudPainter_hpp
#define PointCloudPainter_hpp

#include "Painter.h"
#include "TimeManager.hpp"

class PointCloudPainter : public Painter<vector<ofPoint> *> {
private:
    float rad = 500;
public:
    void draw(vector<ofPoint> * noise2d) override;
};


#endif /* PointCloudPainter_hpp */
