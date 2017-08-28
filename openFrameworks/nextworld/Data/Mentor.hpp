//
//  Mentor.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef Mentor_hpp
#define Mentor_hpp

#include "Profile.h"
#include "Data.hpp"

using namespace University;

class Mentor : public Data {
private:
    Mentor(){}
public:
    Mentor(string name, Sex sex, UniversityType univ, Course course, string skill){
        this->name = name;
        this->sex = sex;
        this->univ = univ;
        this->course = course;
        this->skill = skill;
    }
    
    string name;
    Sex sex;
    UniversityType univ;
    Course course;
    string skill;
};


#endif /* Mentor_hpp */
