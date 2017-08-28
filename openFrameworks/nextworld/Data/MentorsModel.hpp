//
//  MentorsModel.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef MentorsModel_hpp
#define MentorsModel_hpp

#include "ofMain.h"
#include "Mentor.hpp"
#include "CSVLoadHandler.hpp"

class MentorsModel {
public:
    vector<Mentor> mentors;
    
    void loadMentors();
};
#endif /* MentorsModel_hpp */
