//
//  CSVLoadHandler.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/24.
//
//

#ifndef CSVLoadHandler_hpp
#define CSVLoadHandler_hpp

#include "ofMain.h"
#include "Mentor.hpp"
#include "Member.hpp"
#include "CSVProfileParseHandler.hpp"

class CSVLoadHandler {
public:
    static vector<Mentor> loadMentorsDataFromCSV(string fileName);
    static vector<Member> loadMembersDataFromCSV(string fileName);
};
#endif /* CSVLoadHandler_hpp */
