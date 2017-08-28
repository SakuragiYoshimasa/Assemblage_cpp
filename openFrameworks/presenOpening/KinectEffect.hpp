//
//  KinectEffect.hpp
//  presenOpening
//
//  Created by SakuragiYoshimasa on 2016/08/29.
//
//

#ifndef KinectEffect_hpp
#define KinectEffect_hpp

#include "BackEffect.hpp"
#include "ofxOpenNI.h"

class KinectEffect : public BackEffect {
public:
    void setup();
    void update();
    void draw();
    void exit();
 
    void updateMode_0();
    void updateMode_1();
    void updateMode_2();
    void updateMode_3();
    void updateMode_4();
    
    
   // void keyPressed(int key);
    override void keyReleased(int key);
   /* void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);*/
    
    
    ofxOpenNI openNIDevice;
    ofTrueTypeFont verdana;
    ofImage maskedImage, scenery;
    
    ofFbo fbo;
    ofPoint befposition;
    
    ofPoint rightHandP;
    
    int mode = 0;
    
    ofMesh pointCloud;
    ofMesh randomTriangle;
};

#endif /* KinectEffect_hpp */
