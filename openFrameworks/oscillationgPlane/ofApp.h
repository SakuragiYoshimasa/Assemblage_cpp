#pragma once

#include "ofMain.h"

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
		
    
    
    void setNormals(ofMesh &mesh){
        int nV = mesh.getNumVertices();
        int nT = mesh.getNumIndices()/3;
        
        vector<ofPoint> norm(nV);
        
        for(int t = 0; t < nT; t++){
            int i1 = mesh.getIndex(3*t);
            int i2 = mesh.getIndex(3*t + 1);
            int i3 = mesh.getIndex(3*t + 2);
            
            const ofPoint &v1 = mesh.getVertex(i1);
            const ofPoint &v2 = mesh.getVertex(i2);
            const ofPoint &v3 = mesh.getVertex(i3);
            
            ofPoint dir = ((v2-v1).crossed(v3-v1)).normalized();
            
            norm[i1] += dir;
            norm[i2] += dir;
            norm[i3] += dir;
        }
        
        for (int i = 0; i < nV; i++) {
            norm[i].normalize();
        }
        
        mesh.clearNormals();
        mesh.addNormals(norm);
    }
    
    ofMesh mesh;
    ofLight light;
    
    int W = 100;
    int H = 100;
};
