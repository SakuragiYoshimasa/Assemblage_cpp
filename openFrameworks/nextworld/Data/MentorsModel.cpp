//
//  MentorsModel.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#include "MentorsModel.hpp"

void MentorsModel::loadMentors(){
    this->mentors = CSVLoadHandler::loadMentorsDataFromCSV("");
}