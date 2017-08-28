#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    
    //-------------------------------
    //Phase1
    //-------------------------------
    generation = 0;
    loopCounter = 0;
    
    for(int i = 0; i < AGENT_NUM; i++){
        agents[i] = *new Agent();
        agents[i].init();
    }
}

//--------------------------------------------------------------
void ofApp::update(){


    if(loopCounter == ONE_LOOP_TIME){
        
        if(generation != 0){
            //-------------------------------
            //Phase2.3
            //-------------------------------
            double newScore = agents[changedIndex].pos.x;
            if(newScore < 0) newScore = 0.01;
            
            //-------------------------------
            //Phase2.4
            //-------------------------------
            scoreAverage = scoreAverage + (newScore - scores[changedIndex]) / double(AGENT_NUM);
            averageMesh.addVertex(ofVec2f(float(generation) * 0.5, -scoreAverage * 0.03 * 0.8));
          
            //-------------------------------
            //Phase2.5
            //-------------------------------
            scores[changedIndex] = newScore;
            
        }else{
            //-------------------------------
            //Phase2.1
            //-------------------------------
            scoreAverage = 0;
            
            for(int i = 0; i < AGENT_NUM; i++){
                scores[i] = agents[i].pos.x;
                if(scores[i] < 0) scores[i] = 0.01;
                scoreAverage += scores[i];
            }
            
            
            //-------------------------------
            //Phase2.2
            //-------------------------------
            scoreAverage /= double(AGENT_NUM);
            averageMesh.addVertex(ofVec2f(float(generation) * 0.5, -scoreAverage * 0.03 * 0.8));
            
        }
        
        for(int i = 0; i < AGENT_NUM; i++){
            agents[i].init();
        }
        
        
        //-------------------------------
        //Phase3
        //-------------------------------
        loopCounter = 0;
        generation++;
        
        //-------------------------------
        //Phase4
        //-------------------------------
        float rand = ofRandom(AGENT_NUM);
        float sumP = 0;
        for(int i = 0; i < AGENT_NUM; i++){
            sumP += scores[i] / scoreAverage;
            if(sumP > rand){
                selectedIndex = i;
                break;
            }
        }
        
        //Agent newAgent = agents[selectedIndex];
        Agent newAgent = *new Agent();
        for(int i = 0; i < PATTERN_NUM; i++){
            newAgent.accePattern[i] = agents[selectedIndex].accePattern[i];
        }
        //-------------------------------
        //Phase5.1 Simple crossing‐over
        //-------------------------------
        if(ofRandom(1.0) < PROB_CROSSING){
            
            float rand1 = ofRandom(AGENT_NUM);
            float sumP1 = 0;
            int crossedIndex = 0;
            for(int i = 0; i < AGENT_NUM; i++){
                sumP1 += scores[i] / scoreAverage;
                if(sumP1 > rand1){
                    crossedIndex = i;
                    break;
                }
            }
            
            int crossPoint = ofRandom(PATTERN_NUM);
            
            for(int i = crossPoint; i < PATTERN_NUM; i++){
                char temp = newAgent.accePattern[i];
                newAgent.accePattern[i] = agents[crossedIndex].accePattern[i];
            }
        }
        
        
        //-------------------------------
        //Phase5.2 Simple Inversion
        //-------------------------------
        if(ofRandom(1.0) < PROB_INVERSE){
            
            int inversePoint0 = ofRandom(PATTERN_NUM - 10);
            int inversePoint1 = ofRandom(inversePoint0 + 1,PATTERN_NUM);
            
            //cout << "inverseStart" << ":" << inversePoint0 << "," << inversePoint1 << endl;
            
            while (inversePoint1 > inversePoint0) {
                
                
                char temp = newAgent.accePattern[inversePoint0];
                newAgent.accePattern[inversePoint0] = newAgent.accePattern[inversePoint1];
                newAgent.accePattern[inversePoint1] = temp;
                
               // cout << "inverse" << ":" << inversePoint0 << "," << inversePoint1 << endl;
                
                inversePoint0++;
                inversePoint1--;
            }
        }
        
        //-------------------------------
        //Phase5.3 Mutation
        //-------------------------------
        for(int i = 0; i < PATTERN_NUM; i++){
           
            if(ofRandom(1.0) < PROB_MUTATION){
                int mutatePoint = ofRandom(PATTERN_NUM);
                newAgent.accePattern[mutatePoint] = int(ofRandom(0,8));
            }
        }
        
        
        //-------------------------------
        //Phase6.1
        //-------------------------------
        changedIndex = ofRandom(AGENT_NUM);
        agents[changedIndex] = newAgent;
        
        /*
        cout << "new :";
        for(int i = 0; i < PATTERN_NUM; i++){
            cout << newAgent.accePattern[i];
        }
        cout << endl;
        
        
        cout << "chan:";
        for(int i = 0; i < PATTERN_NUM; i++){
            cout << agents[changedIndex].accePattern[i];
        }
        cout << endl;
        
        cout << "sele:";
        for(int i = 0; i < PATTERN_NUM; i++){
            cout << agents[selectedIndex].accePattern[i];
        }
        cout << endl;
        */
    }
    
    
    if(generation % 100 == 0){
        
        
        
        
        //process 1 loop only to show
        for(int i = 0; i < AGENT_NUM; i++){
            agents[i].update();
        }
        loopCounter++;
        
    }else{
        //process all loop to selectedIndex
        for(int n = 0; n < ONE_LOOP_TIME; n++){
            
            agents[changedIndex].update();
            loopCounter++;
        }
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255, 255, 255);
    ofDrawBitmapString("Generation:" + ofToString(generation), 50, 50);
    
    for(int i = 0; i < AGENT_NUM; i++){
        ofSetColor(ofColor::fromHsb(i * 10, 255, 255));
        ofDrawCircle(agents[i].pos * 0.025 + ofVec2f(100, i * 30 + 50), 5);
    }
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight());
    ofSetColor(0, 255, 255);
    averageMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    averageMesh.draw();
    averageMesh.setMode(OF_PRIMITIVE_POINTS);
    averageMesh.draw();
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
