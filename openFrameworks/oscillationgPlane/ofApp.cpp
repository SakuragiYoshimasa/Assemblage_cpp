#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            mesh.addVertex(ofPoint((x - W/2) * 6, (y - H/2) * 6,0));
            mesh.addColor(ofColor(0,0,0));
        }
    }
    for(int y = 0; y < H - 1; y++){
        for(int x = 0; x < W - 1; x++){
            int i1 = x + W * y;
            int i2 = x+1 + W * y;
            int i3 = x + W * (y + 1);
            int i4 = x + 1 + W * (y + 1);
            mesh.addTriangle(i1, i2, i3);
            mesh.addTriangle(i2, i4, i3);
        }
    }
    
    setNormals(mesh);
    light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            int i = x + y * W;
            ofPoint p = mesh.getVertex(i);
            float value = ofNoise(x * 0.05, y * 0.05, time * 0.5);
            p.z = value * 100.0;
            
            mesh.setVertex(i, p);
            mesh.setColor(i, ofColor(value * 255, value * 255, 255));
            
        }
    }
    setNormals(mesh);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    ofBackgroundGradient(ofColor(255),ofColor(128));
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight()*0.5);
    
    float time = ofGetElapsedTimef();
    float angle = 20.0 * time;
    
    ofRotate(30, 1, 0, 0);
    
    ofRotate(angle,0,0,1);
    
    mesh.draw();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
