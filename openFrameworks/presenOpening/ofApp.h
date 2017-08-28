#pragma once

#include "ofMain.h"
#include "BackEffectManger.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioIn(float * input, int bufferSize, int nChannels);
    
    void updateGraph();
    void drawGraph();
    
    void updateBackEffect();
    void drawBackEffect();
    
    
    float curVol;
    ofSoundStream soundStream;
    
    ofMesh graphMesh;
    int vertexIndex;
    float threshold;
    float amplitude;
    const int GRAPGH_LNEGTH = 100;
    
    
    BackEffectManger effectManager;
    enum EffectMode {
        
    };
};
