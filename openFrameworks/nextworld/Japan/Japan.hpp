//
//  Japan.hpp
//  NextWorld
//
//  Created by 厚木麻耶 on 2016/03/15.
//
//

#ifndef Japan_hpp
#define Japan_hpp

#include <stdio.h>
#include "ofMain.h"
//#include "JapanData.hpp"
#endif /* Japan_hpp */

class Japan: public ofBaseApp{
public:
    void setup();
    void draw();
    void keyPressed(int key);
    void japanMap(bool s);
    vector<string> split(const string &str, const string &delim);
    void initMemberData();
    void convertMemberData();
    void drawMemberData();
    void drawRipple(ofPoint p){}; //波紋
    vector<ofVec2f> map[2];
    vector<ofVec2f> member_map;
    ofVec2f translate;
    ofFbo japan, fjapan;
    int count, pointnum, prepointnum, alpha;
    vector<int>frame;
    bool isStart;
    float thenTime;
};