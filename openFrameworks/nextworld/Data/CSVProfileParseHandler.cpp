//
//  CSVProfileParseHandler.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/26.
//
//

#include "CSVProfileParseHandler.hpp"

Course CSVProfileParseHandler::courseParse(string courseString){
    return courses[courseString];
}
Sex CSVProfileParseHandler::sexParse(string sexString){
    return sexString == "男性" ? MALE : FEMALE;
}
Grade CSVProfileParseHandler::gradeParse(string gradeString){
    return grades[gradeString];
}
Address CSVProfileParseHandler::addressParse(string addressString){
    new Address(); //TODO implement
}



void CSVProfileParseHandler::init(){
    courses["iPhoneアプリ開発コース"] =  I_PHONE;
    courses["Androidアプリ開発コース"] =  ANDROID;
    courses["ゲームクリエイター入門コース（2D）"] =  GAME_2D;
    courses["Unityゲームプログラミングコース"] =  GAME_3D;
    courses["WEBデザインコース"] =  WEB_D;
    courses["WEBプログラミングコース"] =  WEB_P;
    courses["デザイナーコース"] =  DESIGN;
    courses["アニメーションコース"] =  ANIM;
    courses["映像編集コース"] =  MOVIE;
    courses["メディアアートコース"] =  MEDIA_ART;
    courses["デジタルミュージックコース"] =  DTM;
    courses["MINECRAFTプログラミングコース"] =  MINECRAFT;
    courses["初音ミクV3コース"] =  MIKU;
    courses["LINEスタンプコース"] =  LINE_STAMP;
    
    grades["小学6年生（新中1）"] = JHS_GRADE_1;
    grades["中学1年生（新中2）"] = JHS_GRADE_2;
    grades["中学2年生（新中3）"] = JHS_GRADE_3;
    grades["中学3年生（新高1/新高専1）"] = HS_GRADE_1;
    grades["高校1年生・高専1年生（新高2/新高専2）"] = HS_GRADE_2;
    grades["高校2年生・高専2年生（新高3/新高専3）"] = HS_GRADE_3;
}
