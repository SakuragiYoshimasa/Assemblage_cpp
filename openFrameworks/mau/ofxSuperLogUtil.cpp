//
//  ofxSuperLogUtil.cpp
//  mauInteractive
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#include "ofxSuperLogUtil.h"

void ofxSuperLogUtil::init(){
    bool logToConsole = true;
    bool logToScreen = true;
    ofSetLoggerChannel(ofxSuperLog::getLogger(logToConsole, logToScreen, "logs"));//consoleに行くはずのログをScreenに
    ofxSuperLog::getLogger()->setMaximized(true);//画面上に表示
}

void ofxSuperLogUtil::set_log(string tag, float arg){
    ofLogNotice() << " ["<< tag<< "] " << ofGetElapsedTimef() << " / " << arg;
}