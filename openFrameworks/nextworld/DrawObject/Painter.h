//
//  Painter.h
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/24.
//
//

#ifndef Painter_h
#define Painter_h

#include "ofMain.h"
#include "Mentor.hpp"

template <class T>
class Painter {
public:
    //plaese Inherit this
    //has no data only draw
    virtual void draw(T instance) = 0;
};
/*
class intPainter : public Painter<int> {
public:
    void draw(int i) override {
        ofDrawCircle(i % ofGetWidth(), 200, 200);
    }
};*/

#endif /* Painter_h */
