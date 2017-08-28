#include "ofMain.h"
#include "ofApp.h"
#include "Japan.hpp"

//========================================================================
int main( ){
//	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    ofSetupOpenGL(960,540,OF_WINDOW);   // <-------- setup the GL context
    //ofSetupOpenGL(1920,1080,OF_WINDOW);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new Japan());
}
