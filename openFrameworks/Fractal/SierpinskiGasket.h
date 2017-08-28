//
//  SierpinskiGasket.hpp
//  FractalTest
//
//  Created by SakuragiYoshimasa on 2015/12/13.
//
//シェルピンスキーのギャスケット

#ifndef SierpinskiGasket_hpp
#define SierpinskiGasket_hpp

#include "ofMain.h"

class SierpinskiGasket {
public:
    void setup();
    void update();
    void draw();
    void reset();
private:
    int generation = 0;
    int frame = 0;
    int maxGeneration = 8;
    ofMesh mesh;
};
#endif /* SierpinskiGasket_hpp */
