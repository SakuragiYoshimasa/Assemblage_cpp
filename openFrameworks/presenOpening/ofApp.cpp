#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    soundStream.setup(this, 0, 1, 44100, 256, 4);
    vertexIndex = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateBackEffect();
    updateGraph();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    //--------------------------------
    //BackEffect
    //--------------------------------
    drawBackEffect();
    
    //--------------------------------
    //Cover
    //--------------------------------
    ofSetColor(0, 0, 0, 30);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //--------------------------------
    //volume test
    //--------------------------------
    ofPushMatrix();
    ofSetColor(0, 255, 100, 30);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofDrawCircle(0, 0, curVol * 200.0);
    ofPopMatrix();
    
    //--------------------------------
    //Draw Graph
    //--------------------------------
    drawGraph();
}

//--------------------------------
//Back Effect
//--------------------------------
void ofApp::updateBackEffect(){
    
};

void ofApp::drawBackEffect(){

};

//--------------------------------
//Graph
//--------------------------------
void ofApp::updateGraph(){
    
    vector<ofPoint> vertices = graphMesh.getVertices();
    float newValue = -curVol * 1000.0;
    
    if(vertices.size() > 0){
        if(abs(vertices.at(vertices.size() - 1).y - newValue) > 200){
            newValue += (newValue - vertices.at(vertices.size() - 1).y) * 0.2;
        }
    }
    
    graphMesh.addVertex(ofPoint(0,  newValue, 0));
    vertices = graphMesh.getVertices();

    
    for(int i = 0; i < graphMesh.getVertices().size(); i++){
        graphMesh.setVertex(i, vertices[i] + ofVec3f(float(ofGetWidth() / GRAPGH_LNEGTH * 0.8), 0.0, 0.0));
    }
    
    if(graphMesh.getVertices().size() >= GRAPGH_LNEGTH){
        graphMesh.removeVertex(0);
    }
};

void ofApp::drawGraph(){
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight() - 150);
    
    ofSetLineWidth(1.0);
    ofSetColor(0, 255, 100, 150);
    graphMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    graphMesh.draw();
    
    glPointSize(10.0);
    ofSetColor(0, 255, 100, 100);
    graphMesh.setMode(OF_PRIMITIVE_POINTS);
    
    graphMesh.draw();
    
    ofPopMatrix();
}

//--------------------------------
//Audio
//--------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    curVol = 0.0;
    for (int i = 0; i < bufferSize; i++){
        curVol += input[i]*input[i];
    }
    curVol /= bufferSize;
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
