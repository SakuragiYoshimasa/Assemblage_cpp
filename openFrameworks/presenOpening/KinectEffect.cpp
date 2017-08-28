//
//  KinectEffect.cpp
//  presenOpening
//
//  Created by SakuragiYoshimasa on 2016/08/29.
//
//

#include "KinectEffect.hpp"

void KinectEffect::setup(){
    
    // window
    ofBackground(19, 37, 13);
    ofSetWindowShape(640, 480);
    ofSetFrameRate(60);
    
    ofEnableAlphaBlending();
    
    
    // set up fbo
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofBackground(19, 37, 13);
    ofSetBackgroundAuto(false);
    
    
    fbo.end();
    
    //ofSetLogLevel(OF_LOG_VERBOSE);
    
    // setup ofxOpenNI
    openNIDevice.setup();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addImageGenerator(); // required for RGB image
    openNIDevice.addDepthGenerator(); // required for depth image
    
    
    // setup the hand generator
    // openNIDevice.addHandsGenerator();
    
    // add all focus gestures (ie., wave, click, raise arm)
    //openNIDevice.addAllHandFocusGestures();
    
    // or you can add them one at a time
    //vector<string> gestureNames = openNIDevice.getAvailableGestures(); // you can use this to get a list of gestures
    // prints to console and/or you can use the returned vector
    //openNIDevice.addHandFocusGesture("Wave");
    
    //openNIDevice.setMaxNumHands(4);
    
    // adjust two images
    
    openNIDevice.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(openNIDevice.getImageGenerator());
    
    //track user
    openNIDevice.addUserGenerator();
    
    // start kinect
    openNIDevice.start();
    
    maskedImage.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
    
    pointCloud.setMode(OF_PRIMITIVE_POINTS);
    randomTriangle.setMode(OF_PRIMITIVE_TRIANGLES);
}
void KinectEffect::update(){
    openNIDevice.update();
    
    switch (mode) {
        case 0:
            updateMode_0();
        case 1:
            updateMode_1();
            break;
        case 2:
            updateMode_2();
            break;
        case 3:
            updateMode_3();
            break;
        case 4:
            updateMode_4();
            break;
        default:
            break;
    }
}


void KinectEffect::updateMode_0(){
    
}

void KinectEffect::updateMode_1(){
    
    unsigned char *maskedImageData = maskedImage.getPixels();
    unsigned char *imageData = openNIDevice.getImagePixels().getPixels();
    unsigned short *depthData = openNIDevice.getDepthRawPixels().getPixels();
    
    for (int k = 0; k<640*480; k++){
        maskedImageData[k * 4 + 0] = imageData[k * 3 + 0];
        maskedImageData[k * 4 + 1] = imageData[k * 3 + 1];
        maskedImageData[k * 4 + 2] = imageData[k * 3 + 2];
        
        if (0 <= depthData[k] && depthData[k] < 1000){
            maskedImageData[k * 4 + 3]=255;
        }else{
            maskedImageData[k * 4 + 3]=0;
        }
    }
    maskedImage.setFromPixels(maskedImageData, 640, 480, OF_IMAGE_COLOR_ALPHA);
}

void KinectEffect::updateMode_2(){
    
    pointCloud.clear();
    int step = 1;
    int h = openNIDevice.getDepthRawPixels().getHeight();
    int w = openNIDevice.getDepthRawPixels().getWidth();
    unsigned short *depthData = openNIDevice.getDepthRawPixels().getPixels();
    
    for(int y = 0; y < h; y += step){
        for(int x = 0; x < w; x += step){
            int dist = depthData[x + w * y];
            if(dist > 0 && dist < 2000) {
                
                ofVec3f pt = ofVec3f(x, y, 10);
                
                ofColor c;
                int h = dist % 256;
                c.setHsb(h, 255, 255);
                pointCloud.addColor(c);
                pointCloud.addVertex(pt);
            }
        }
    }
}

void KinectEffect::updateMode_3(){
    pointCloud.clear();
    int step = 4;
    int h = openNIDevice.getDepthRawPixels().getHeight();
    int w = openNIDevice.getDepthRawPixels().getWidth();
    unsigned short *depthData = openNIDevice.getDepthRawPixels().getPixels();
    unsigned char *imageData = openNIDevice.getImagePixels().getPixels();
    
    for(int y = 0; y < h; y += step){
        for(int x = 0; x < w; x += step){
            int dist = depthData[x + w * y];
            if(dist > 0 && dist < 2000) {
                
                ofVec3f pt = ofVec3f(x, y);
                ofColor c = ofColor((imageData[3 * (y * w + x)] + imageData[3 * (y * w + x) + 1] +imageData[3 * (y * w + x) + 2]) % 256);
                
                pointCloud.addColor(c);
                pointCloud.addVertex(pt);
            }
        }
    }
}

void KinectEffect::updateMode_4(){
    pointCloud.clear();
    int step = 8;
    int h = openNIDevice.getDepthRawPixels().getHeight();
    int w = openNIDevice.getDepthRawPixels().getWidth();
    unsigned short *depthData = openNIDevice.getDepthRawPixels().getPixels();
    unsigned char *imageData = openNIDevice.getImagePixels().getPixels();
    
    for(int y = 0; y < h; y += step){
        for(int x = 0; x < w; x += step){
            int dist = depthData[x + w * y];
            if(dist > 0 && dist < 2000) {
                
                ofVec3f pt = ofVec3f(x, y);
                ofColor c = ofColor((imageData[3 * (y * w + x)] + imageData[3 * (y * w + x) + 1] +imageData[3 * (y * w + x) + 2]) % 256);
                
                pointCloud.addColor(c);
                pointCloud.addVertex(pt);
            }
        }
    }
    
    if(ofGetElapsedTimeMillis() % 1 != 0) return;
    randomTriangle.clear();
    
    int tNum = ofRandom(2, 5);
    
    if(pointCloud.getVertices().size() <= 0) return;
    for(int i = 0; i < tNum * 3; i++){
        int index = ofRandom(0, pointCloud.getVertices().size() - 1);
        randomTriangle.addVertex(pointCloud.getVertices().at(index));
        randomTriangle.addColor(ofColor(pointCloud.getColors().at(index), ofRandom(100, 255)));
    }
}

//--------------------------------------------------------------
void KinectEffect::draw(){
    
    ofBackground(0);
    ofSetColor(255, 255, 255);
    
    switch (mode) {
        case 0:
            openNIDevice.drawImage();
            break;
        case 1:
            maskedImage.draw(0, 0, 640, 480);
            break;
        case 2:
            glPointSize(0.5);
            pointCloud.draw();
            break;
        case 3:
            glPointSize(8.0);
            pointCloud.draw();
            break;
        case 4:
            glPointSize(2.0);
            pointCloud.draw();
            randomTriangle.drawFaces();
            randomTriangle.setMode(OF_PRIMITIVE_POINTS);
            glPointSize(4.0);
            randomTriangle.draw();
            randomTriangle.setMode(OF_PRIMITIVE_TRIANGLES);
            break;
            
        default:
            break;
    }
    
    
    
    /*
     音楽
     犬
     スマホ
     ケーキ
     */
}

//--------------------------------------------------------------
void KinectEffect::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void KinectEffect::keyPressed(int key){
    
}

//--------------------------------------------------------------
void KinectEffect::keyReleased(int key){
    switch (key){
        case '0':mode = 0; break;
        case '5':mode = 0; break;
        case '1':mode = 1; break;
        case '2':mode = 2; break;
        case '3':mode = 3; break;
        case '4':mode = 4; break;
    }
}