//
//  Japan.cpp
//  NextWorld
//
//  Created by 厚木麻耶 on 2016/03/15.
//
//

#include "Japan.hpp"
void Japan::setup(){
    ofBackground(0, 0, 0);
    ofSetCircleResolution(100);
    ofSetFrameRate(40);
    map[0].clear();
    map[1].clear();
    frame.clear();
    count = 0;
    prepointnum = 0;
    alpha = 255;
    isStart = false;
    
    for(int j=0; j<2; j++){
        string fileName;
        if(j == 0){
            fileName = "map/japan.csv";//北海道
        }else if(j == 1){
            fileName = "map/japan2.csv";//本州
        }
        string prePath = ofBufferFromFile( fileName );
        vector<string> data = ofSplitString(prePath, ",");
        for(int i=0; i<data.size()/2; i++){
            float x = ofToFloat(data[2*i]);
            float y = ofToFloat(data[2*i + 1]);
            map[j].push_back(ofVec2f(x, y));
        }
    }
    
    initMemberData();
    
    //日本地図
    japan.allocate(ofGetWidth(), ofGetHeight());
    japan.begin();
    japanMap(true);
    japan.end();
    fjapan.allocate(ofGetWidth(), ofGetHeight());
    fjapan.begin();
    japanMap(false);
    fjapan.end();
    
    
}

void Japan::initMemberData(){
    ifstream ifs("data/map/data.csv");
    string str;
    if (ifs.fail()){
        cerr << "failed" << endl;
        return -1;
    }
    while (getline(ifs, str)){
        vector<string> result = split(str, ",");
        member_map.push_back(ofVec2f(ofToFloat(result[1]),ofToFloat(result[0])));
    }
    //    convertMemberData();
}

void Japan::convertMemberData(){
    for (int i = 0 ;i < member_map.size() ; i++){
        member_map[i].x = ofMap(member_map[i].x, 122,153,0,ofGetWidth());
        member_map[i].y = ofMap(member_map[i].y, 20,45,0,ofGetHeight());
    }
}

/*
 * East  153°59′11″ 24°16′59″
 * West  122°56′01″ 24°26′58″
 * North 148°45′08″	45°33′26″
 * South 136°04′11″ 20°25′31″
 **/

void Japan::draw(){
    if(isStart){
        //    ofSetColor(255);
        drawMemberData();
        ofSetColor(255, 255-alpha*15);
        fjapan.draw(0, 0);
        ofSetColor(255, 255);
        japan.draw(0, 0);
    }
}
void Japan::japanMap(bool s){ //日本地図の描画
    
    if(s)ofNoFill();
    else ofFill();
    ofPushMatrix();
    ofTranslate(200, -60);
    ofScale(.8, .8);
    for(int j=0; j<2; j++){
        ofBeginShape();
        for(int i=0; i<map[j].size(); i++){
            ofCurveVertex(map[j].at(i).x, map[j].at(i).y);
        }
        ofEndShape();
    }
    ofPopMatrix();
    
    /*
     ofFill();
     ofPushMatrix();
     ofTranslate(0, -10);
     ofRotateZ(-8);
     ofScale(.78, .78);
     for (int i=0; i<9000; i++) {
     ofBeginShape();
     float x = 1000-((150-japan.vecdata[i][1])*40);
     float y = (50-japan.vecdata[i][0])*40;
     ofDrawCircle(x, y, 3);
     ofEndShape();
     }
     ofPopMatrix();
     */
}

void Japan::drawMemberData(){ //メンバーデータの描画
    //    ofPushStyle();
    
    ofPushMatrix();
    ofTranslate(0, -9);
    ofRotateZ(-8);
    ofScale(.78, .78);
    //    for(auto member : member_map){
    pointnum = (ofGetElapsedTimeMillis()-thenTime)/(1000-count);
    if(pointnum > member_map.size() ){
        pointnum = member_map.size();
    }
    
    int size = pointnum - prepointnum;
    if( size > 0){
        for(int i=0; i<size; i++){
            frame.push_back(ofGetFrameNum()); //新しい円が書かれたら、そのときのフレーム数を保存
        }
    }
    
    for(int i=0; i<pointnum; i++){
        float rad = ofGetFrameNum() - frame[i];
        float x = 1000-((150-member_map[i].x)*40);
        float y = (50-member_map[i].y)*40;
        ofFill();
        ofSetColor(255, 255, 0, 255);
        ofDrawCircle(x, y, 1);
        
        ofNoFill();
        ofSetColor(255, 255-rad*4);
        ofDrawCircle(x, y, rad*4);//円の広がり
        alpha = rad;
    }
    
    ofPopMatrix();
    //    ofPopStyle();
    count += 1.3; //円を増やす速度
    
    prepointnum = pointnum;
}

vector<string> Japan::split(const string &str, const string &delim){
    vector<string> res;
    size_t current = 0, found, delimlen = delim.size();
    while((found = str.find(delim, current)) != string::npos){
        res.push_back(string(str, current, found - current));
        current = found + delimlen;
    }
    res.push_back(string(str, current, str.size() - current));
    return res;
}

void Japan::keyPressed(int key){
    if (key == 's') {
        thenTime = ofGetElapsedTimeMillis();
        isStart = true;
    }
}












