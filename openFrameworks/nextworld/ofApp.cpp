#include "ofApp.h"
#include "CSVLoadHandler.hpp"

//--------------------------------------------------------------
void ofApp::setup(){

    sceneManager = *new SceneManager();
    sceneManager.setup();
    TimeManager::getInstance().setup();
    
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle(to_string(ofGetFrameRate()));
    if(appStarted){
        sceneManager.update();
        TimeManager::getInstance().update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(appStarted){
        sceneManager.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '!'){
        appStarted = true;
        ofResetElapsedTimeCounter();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(appStarted){
        sceneManager.keyReleased(key);
    }
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
