#pragma once

#include "ofMain.h"
#include "Agent.hpp"

#define AGENT_NUM 20
#define ONE_LOOP_TIME 300
#define PROB_CROSSING 0.3
#define PROB_INVERSE 0.01
#define PROB_MUTATION 0.01 //0.01to0.0002

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
    
    unsigned int generation;
    unsigned int loopCounter;
    unsigned int selectedIndex;
    unsigned int changedIndex;
    
    Agent agents[AGENT_NUM];
    double scores[AGENT_NUM];
    double scoreAverage;
    
    ofMesh averageMesh;
};
