#include "ofApp.h"

ofMesh circleMesh;


//--------------------------------------------------------------
void ofApp::setup(){
    
    for(float i = 0; i < 3600; i++){
        circleMesh.addVertex(ofPoint(200 * cos(i * 0.1),200 * sin(i * 0.1)));
    }
    ofBackground(0);
    circleMesh.setMode(OF_PRIMITIVE_LINE_LOOP);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    circleMesh.clear();
    
    /*for(float i = 0; i < 3600; i++){
        circleMesh.addVertex(ofPoint(300 * sin(i * 0.1 + i * ofGetElapsedTimef()/1000) * cos(i * 0.1),300  * sin(i * 0.1 + i * ofGetElapsedTimef()/1000) * sin(i * 0.1)));
    }*/

    
    /*for(float i = 0; i < 3600; i++){
        circleMesh.addVertex(ofPoint(sin(ofGetElapsedTimef() / 10 + ofNoise(i * 0.1, ofGetElapsedTimef()* 0.1)) * 300.0 * cos(i * 0.1),sin(ofGetElapsedTimef() / 10  + ofNoise(i * 0.1, ofGetElapsedTimef()* 0.1)) * 300.0 * sin(i * 0.1)));
    }*/
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    
    
    float t = ofGetElapsedTimef();
    
    for(float i = 0; i < 360; i++){
        /*circleMesh.addVertex(ofPoint(
                                     50 * sin(-t* 1 + i * 0.1) * sin(t* 1 + i * 0.1 * 3.0)* sin(-t* 1 + i * 0.1 * 5.0)* sin(t* 1 + i * 0.1 * 2.5) + 300.0 * cos(i/180.0 * PI ) ,
                                     50 * sin(-t* 1 + i * 0.1) * sin(t * 1 + i * 0.1 * 3.0) * sin(-t* 1 + i * 0.1 * 5.0)* sin(t* 1 + i * 0.1 * 3.7) + 300.0 * sin(i/180.0 * PI ) ));*/
        
        ofVertex(50 * sin(-t* 1 + i * 0.1) * sin(t* 1 + i * 0.1 * 3.0)* sin(-t* 1 + i * 0.1 * 5.0)* sin(t* 1 + i * 0.1 * 2.5) + 300.0 * cos(i/180.0 * PI ) ,
                 50 * sin(-t* 1 + i * 0.1) * sin(t * 1 + i * 0.1 * 3.0) * sin(-t* 1 + i * 0.1 * 5.0)* sin(t* 1 + i * 0.1 * 3.7) + 300.0 * sin(i/180.0 * PI ));
    }
    
    ofEndShape();
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofFill();
    ofSetColor(0, 255, 255);
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    
    
    float t = ofGetElapsedTimef();
    
    for(float i = 0; i < 360; i++){
        /*circleMesh.addVertex(ofPoint(
         50 * sin(-t* 1 + i * 0.1) * sin(t* 1 + i * 0.1 * 3.0)* sin(-t* 1 + i * 0.1 * 5.0)* sin(t* 1 + i * 0.1 * 2.5) + 300.0 * cos(i/180.0 * PI ) ,
         50 * sin(-t* 1 + i * 0.1) * sin(t * 1 + i * 0.1 * 3.0) * sin(-t* 1 + i * 0.1 * 5.0)* sin(t* 1 + i * 0.1 * 3.7) + 300.0 * sin(i/180.0 * PI ) ));*/
        
        ofVertex(80 * sin(-t* 1 + i* 0.05) * sin(t* 1 + i * 0.05 * 3.0)* sin(-t* 1 + i * 0.05 * 5.0)* sin(t* 1 + i * 0.05 * 1.7) + 300.0 * cos(i/180.0 * PI) ,
                 80 * sin(-t* 1 + i* 0.05) * sin(t * 1 + i * 0.05 * 3.0) * sin(-t* 1 + i * 0.05 * 5.0)* sin(t* 1 + i * 0.05 * 3.7) + 300.0 * sin(i/180.0 * PI));
    }
    
    ofEndShape();
    circleMesh.draw();
    circleMesh.drawFaces();
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
