#include "ofApp.h"

int step = 8;
bool start = false;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    
    image.load("camp.png");
    unsigned char * pixles = image.getPixels().getData();
    

    for(int x = 0; x < 1920; x+= step){
        for(int y = 0; y < 1080; y+= step){
            mesh.addVertex(ofVec3f(x, y, 0));
            mesh.addColor(ofColor(pixles[3 * (x + y * 1920)], pixles[3 * (x + y * 1920) + 1], pixles[3 * (x + y * 1920) + 2]));
            
        }
    }
    
    
    for(int x = 0; x < 1920; x+= step){
        for(int y = 0; y < 1080; y+= step){

            if(x != 1920 - step){
                mesh.addIndex(x / step * 1080 / step + y / step);
                mesh.addIndex((x / step + 1) * 1080 / step + y / step);
            }
            
            if(y != 1080 - step){
                mesh.addIndex(x / step * 1080  / step+ y / step);
                mesh.addIndex(x / step * 1080 / step + y / step + 1);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    if(!start) return;
    
    float time = ofGetElapsedTimef();
    float ampX;
    float ampY;
    
    for(int x = 0; x < 1920; x+= step){
        for(int y = 0; y < 1080; y+= step){
            ofVec3f bef = mesh.getVertices()[x / step * 1080 / step + y / step];
            /*
            if(float(x - 1920 / 2) > 0){
                ampX = 1.0;
            }else{
                ampX = -1.0;
            }
            
            if(float(y - 1080 / 2) > 0){
                ampY = 1.0;
            }else{
                ampY = -1.0;
            }
             */
            ampX = sin(x / 1000.0);
            ampY = sin(y / 1000.0);
            
            ofVec3f diff = ofVec3f(
                                   ampX * ofNoise(x, y, time),
                                   ampY * ofNoise(x/step, y/step, time),
                                   sin((x + y)/1000.0));
            mesh.setVertex(x / step * 1080 / step + y / step, bef + diff );
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    glPointSize(8.0);
    ofSetLineWidth(0.5);
    mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
    mesh.drawWireframe();
    mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_POINTS);
    mesh.drawVertices();
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' '){
        start = true;
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
