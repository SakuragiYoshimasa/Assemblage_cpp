//
//  StartScene.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/25.
//
//

#include "StartScene.hpp"

void StartScene::setup(){
    elements.push_back(new StartScene_FadeInOut());
    elements.push_back(new StartScene_LineAnim());
  //  elements.push_back(new StartScene_Wave());
    elements.push_back(new StartScene_Circuit());
    elements.push_back(new StartScene_Booting());
    for(int i = 0; i < elements.size(); i++){
        elements[i]->init();
        
        function<void(void)> cb = [&]{
            nextElement();
        };
        elements[i]->callback = cb;
    }
    
    elements[0]->start();
}


/*
void StartScene::update(){

}

void StartScene::draw(){
    

}*/

/*
 ofxBlur blur;
 blur.setup(cam.getWidth(), cam.getHeight(), 10, .2, 4);
 blur.setScale(ofMap(mouseX, 0, ofGetWidth(), 0, 10));
 blur.setRotation(ofMap(mouseY, 0, ofGetHeight(), -PI, PI));
 blur.begin();
 blur.end();
 blur.draw();
 
 ofxEasyFboGlitch fboGlitch;
 fboGlitch.draw(fbo, ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight()/2);
 fboGlitch.allocate(320, 240);
 
 
 ofGLWindowSettings s;
 s.setGLVersion(3,2);
 ofCreateWindow(s);
 
 ofxInkSim inkSim;
 SampleBrush brush;
 inkSim.setup();
 inkSim.update();
 inkSim.draw();
 
 ofColor c = moodmachine;
 inkSim.stroke(&brush, x, y, getInkColor(c.getHueAngle(), 255, 10));
 inkSim.stopStroke(&brush);
 if (key == '1')
 {
 inkSim.setDrawMode(ofxInkSim::INKFIX);
 }
 else if (key == '2')
 {
 inkSim.setDrawMode(ofxInkSim::INKSURF);
 }
 else if (key == '3')
 {
 inkSim.setDrawMode(ofxInkSim::INKFLOW);
 }
 else if (key == '4')
 {
 inkSim.setDrawMode(ofxInkSim::WATERFLOW);
 }
 else if (key == 'd')
 {
 inkSim.toggleDebug();
 }
 
 ofxPostProcessing post;
 post.init(ofGetWidth(), ofGetHeight());
 post.createPass<FxaaPass>()->setEnabled(false);
 post.createPass<BloomPass>()->setEnabled(false);
 post.createPass<DofPass>()->setEnabled(false);
 post.createPass<KaleidoscopePass>()->setEnabled(false);
 post.createPass<NoiseWarpPass>()->setEnabled(false);
 post.createPass<PixelatePass>()->setEnabled(false);
 post.createPass<EdgePass>()->setEnabled(false);
 post.createPass<VerticalTiltShifPass>()->setEnabled(false);
 post.createPass<GodRaysPass>()->setEnabled(false);
 
 // copy enable part of gl state
 glPushAttrib(GL_ENABLE_BIT);
 
 // setup gl state
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_CULL_FACE);
 light.enable();
 
 // begin scene to post process
 post.begin(cam);
 
 // draw boxes
 for (unsigned i = 0; i < posns.size(); ++i)
 {
 cout << i << cols[i] << endl;
 ofSetColor(cols[i]);
 ofPushMatrix();
 ofTranslate(posns[i]);
 boxMesh.draw();
 ofPopMatrix();
 }
 
 ofDrawAxis(100);
 
 // end scene and draw
 post.end();
 
 unsigned idx = key - '0';
 if (idx < post.size()) post[idx]->setEnabled(!post[idx]->getEnabled());
 */