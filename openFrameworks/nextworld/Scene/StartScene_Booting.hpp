//
//  StartScene_Booting.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/27.
//
//

#ifndef StartScene_Booting_hpp
#define StartScene_Booting_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"
#include "PointCloudPainter.hpp"
#include "ofxEasyFboGlitch.h"
#include "ofxBlur.h"

class StartScene_Booting : public SceneElement {
    void init() override;
    void start() override;
    void update() override;
    void end() override;
    void draw() override;
    
    ofVideoPlayer video;
    ofFbo fbo;
    ofFbo glitchFbo;
    vector<ofPoint> noise2d;
    PointCloudPainter pcp;
    ofShader shader;
    
    bool fadeOut = false;
    int fadeCounter = 0;
    int offsetX = 50;
    int offsetY = 40;
    float glitchratio = 0.3;
    
    float glitchWidth = ofGetWidth() * glitchratio;
    float glitchHeight = ofGetHeight() * glitchratio;
    
    ofxEasyFboGlitch fboGlitch;
};

#endif /* StartScene_Booting_hpp */
