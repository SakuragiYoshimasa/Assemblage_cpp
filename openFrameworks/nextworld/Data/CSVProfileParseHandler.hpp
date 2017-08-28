//
//  CSVProfileParseHandler.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/26.
//
//

#ifndef CSVProfileParseHandler_hpp
#define CSVProfileParseHandler_hpp

#include "ofMain.h"
#include "Profile.h"

//--------------------------------------------------------
//Need to init to Use!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//--------------------------------------------------------

class CSVProfileParseHandler {
public:
    CSVProfileParseHandler(){ init(); }
    
    map<string, Course> courses;
    map<string, Grade> grades;
    
    void init();
    Course courseParse(string courseString);
    Sex sexParse(string sexString);
    Grade gradeParse(string gradeString);
    Address addressParse(string addressString);
};
#endif /* CSVProfileParseHandler_hpp */
