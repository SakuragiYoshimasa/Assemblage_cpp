#include "ofApp.h"
ofVec2f center;
int mouseX,mouseY;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    turbulence = ofRandom(0.2,0.8);
    //-----------------------------------------------
    //GetCenter
    //-----------------------------------------------
    center = ofVec2f(0,0);;
    for(int i = 0; i < NUM; i++){
        center += arrows[i].position;
    }
    center /= float(NUM);
    center += arrows[0].position;
    center /= 2.0;
    /*center += arrows[1].position;
    center += arrows[2].position;
    center += arrows[3].position;
    center += arrows[4].position;
    center /= 6.0;*/

    //-----------------------------------------------
    //ToCenter
    //-----------------------------------------------
    for(int i = 0; i < NUM; i++){
        /*if(i == 0){
            ofVec2f dirToCenter = (center - arrows[i].position).normalized();
            ofVec2f direction = (arrows[i].velocity.normalized() * turbulence + dirToCenter * (1.0 - turbulence)).normalized();
            direction *= ofRandom(10000, 12000);
            arrows[i].velocity += -ofVec2f(1.0/direction.x,1.0/direction.y);
        }*////else{
       /* ofVec2f dirToCent = center - arrows[i].position;
            ofVec2f dirToCenter = (center - arrows[i].position).normalized();
            //ofVec2f direction = (arrows[i].velocity.normalized() * turbulence + dirToCenter * (1.0 - turbulence)).normalized();
        ofVec2f direction = (arrows[i].velocity.normalized() / (dirToCent.length() * 0.001) + dirToCenter * (dirToCent.length() * 0.001)).normalized() ;
            direction *= ofRandom(1.0, 2.0);
            arrows[i].velocity = direction;
          */
        //}
        
        //if(i == 0 || i==1 || i==2 || i== 3 || i== 4){
        if(i == 0 ){
            ofVec2f dirToCent = center - arrows[i].position;
            ofVec2f dirToCenter = (center - arrows[i].position).normalized();
            //ofVec2f direction = (arrows[i].velocity.normalized() * turbulence + dirToCenter * (1.0 - turbulence)).normalized();
            ofVec2f direction = (arrows[i].velocity.normalized() / (dirToCent.length() * 0.001) + dirToCenter * (dirToCent.length() * 0.0007)).normalized() ;
            //ofVec2f direction = (arrows[i].velocity.normalized() / (dirToCent.length() * 0.01) + dirToCenter * (dirToCent.length() * 0.0001));
            direction *= ofRandom(3.0, 7.0);
            arrows[i].velocity = direction;
        }else{
            ofVec2f dirToCent = center - arrows[i].position;
            ofVec2f dirToCenter = (center - arrows[i].position).normalized();
            //ofVec2f direction = (arrows[i].velocity.normalized() * turbulence + dirToCenter * (1.0 - turbulence)).normalized();
            ofVec2f direction = (arrows[i].velocity.normalized() / (dirToCent.length() * 0.005) + dirToCenter * (dirToCent.length() * 0.0015)).normalized() ;
            //ofVec2f direction = (arrows[i].velocity.normalized() / (dirToCent.length() * 0.005) + dirToCenter * (dirToCent.length() * 0.0005)) ;
            direction *= ofRandom(1.0, 4.0);
            arrows[i].velocity = direction;
        }
    }
    
    //-----------------------------------------------
    //Every arrows want stay same distance
    //-----------------------------------------------
    for(int i = 0; i < NUM; i++){
        for(int j = 0; j < NUM; j++){
            if(i == j) continue;
            ofVec2f diff = arrows[i].position - arrows[j].position;
            if(diff.length() < ofRandom(70, 150)){
                //arrows[i].velocity = diff.normalized() * arrows[i].velocity.length();
              //  cout << 1.0/diff.length() << endl;
                arrows[i].velocity += diff.length()/10000.0 * arrows[i].velocity;
                //arrows[i].velocity += 1.0/diff.length() * arrows[i].velocity;
                arrows[i].velocity += ofVec2f(0.15/diff.x,0.15/diff.y);
            }
        }
    }
    
    //-----------------------------------------------
    //Average Vector
    //-----------------------------------------------
    /*ofVec3f averageVelocity = ofVec2f(0,0);
    for(int i = 0; i < NUM; i++){
        averageVelocity += arrows[i].velocity;
    }
    averageVelocity /= NUM;
    
    for(int i = 1; i < NUM; i++){
        arrows[i].velocity = arrows[i].velocity * turbulence + averageVelocity * (1.0 - turbulence);
    }
    */
    //-----------------------------------------------
    //update
    //-----------------------------------------------
    for(int i = 0; i < NUM; i++){
        arrows[i].position += arrows[i].velocity;
        
        if(arrows[i].position.x <= 0){
            arrows[i].position.x = ofGetWidth() - 50;
            arrows[i].position.y = ofGetHeight() - arrows[i].position.y;
        }
        if(arrows[i].position.x >= ofGetWidth() ){
            arrows[i].position.x = 50;
            arrows[i].position.y = ofGetHeight() - arrows[i].position.y;
        }
        if(arrows[i].position.y <= 0){
            arrows[i].position.y = ofGetHeight() - 50;
            arrows[i].position.x = ofGetWidth() - arrows[i].position.x;
        }
        if(arrows[i].position.y >= ofGetHeight()){
            arrows[i].position.y = 50;
        arrows[i].position.x = ofGetWidth() - arrows[i].position.x;
        }
        /*
        if((arrows[i].position.x < 50 && arrows[i].velocity.x < 0) || (arrows[i].position.x > ofGetWidth() - 50 && arrows[i].velocity.x > 0)){
            arrows[i].velocity.x *= -1;
        }
        if((arrows[i].position.y < 50 && arrows[i].velocity.y < 0) || (arrows[i].position.y > ofGetHeight() - 50 && arrows[i].velocity.y > 0)){
            arrows[i].velocity.y *= -1;
        }*/
    }
 }

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundAuto(false);
    //ofEnableAlphaBlending();
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int i = 0; i < NUM; i++) {
        ofSetColor(0, 255, 0);
        ofCircle(arrows[i].position, 5);
        //if(i == 0 || i==1 || i==2 || i== 3 || i== 4){
        if(i == 0 ){
            //ofSetColor(0, 255, 255);
            //ofCircle(arrows[i].position, 10);
        }
    }
    ofSetColor(255, 0, 0);
   // ofCircle(center, 10);
    ofSetColor(255, 0, 0);
   // ofCircle(ofVec2f(mouseX,mouseY), 10);
    ofSetColor(0, 0, 0,10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseX = x;
    mouseY = y;
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
