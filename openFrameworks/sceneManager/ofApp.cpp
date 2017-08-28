#include "ofApp.h"
#include "SampleSceneManager.h"

SampleSceneManager manager;

void ofApp::setup(){
    manager.setup();
}

void ofApp::update(){
    manager.update();
}

void ofApp::draw(){
    manager.draw();
}

void ofApp::keyReleased(int key){
    if(key == ' '){
        if(!manager.nextElement()){
            //Create new manager if has no more elements
            manager = *new SampleSceneManager();
            manager.setup();
        }
    }
    
    manager.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
    manager.mouseReleased(x, y, button);
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


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::keyPressed(int key){
    
}