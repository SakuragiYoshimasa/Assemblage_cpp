#include "ofApp.h"

double height[100];

double ofApp::u(){
    return ofRandom(0, 1.0);
};

double ofApp::ConvertUtoX(double u){
    return (u - 0.5) >= 0 ? -log(1.0-2.0*abs(u - 0.5)) : log(1.0-2.0*abs(u - 0.5));
};

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < 10000; i++){
        sampleU[i] = u();
    }
    
    for(int i = 0; i < 10000; i++){
        raplasX[i] = ConvertUtoX(sampleU[i]);
    }
    
    for(int i = 0; i < 10000; i++){
        //-5~5を想定
        if(int(raplasX[i] * 10) + 50 >= 0 && int(raplasX[i] * 10.0) + 50 < 100) height[int(raplasX[i] * 10.0) + 50] += 1;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofSetColor(0, 0, 255);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/1.5);
    for(int i = 0; i < 100; i++){
        ofRect(i * 5 - 250, 0, 5, -height[i]);
    }
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
