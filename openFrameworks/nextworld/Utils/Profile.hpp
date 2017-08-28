//
//  Profile.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//
#include <stdio.h>
#include "ofMain.h"

enum Sex {
    MALE = 0,
    FEMALE = 1,
    ERROR_SEX,
};

enum Grade {
    JHS_GRADE_1,
    JHS_GRADE_2,
    JHS_GRADE_3,
    HS_GRADE_1,
    HS_GRADE_2,
    HS_GRADE_3,
    ERROR_GRADE,
};

enum Cource {
    I_PHONE,
    ANDROID,
    GAME_2D,
    GAME_3D,
    WEB_D,
    WEB_P,
    DESIGN,
    ANIM,
    MOVIE,
    MEDIA_ART, //Very Cool
    DTM,
    MINECRAFT,
    MIKU,
    LINE_STAMP,
    ERROR_COURCE,
};


struct Address {
    Address(){};
    Address(float latitude, float longitude){
        this->latitude = latitude;
        this->longitude = longitude;
    }
    
    float latitude;
    float longitude;
    //ofVec2f displayPos;
};

namespace University {
    
    enum UniversityType {
        KYOTO_UNIV,
        TOKYO_TECH
    };
    
    
    class University {
        static string univToString(UniversityType type){
            switch (type) {
                case KYOTO_UNIV:
                    return "Kyoto University";
                case TOKYO_TECH:
                    return "Tokyo Institute of Technology";
                default:
                    return "";
                    break;
            }
        }
    };
};

