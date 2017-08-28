//
//  CSVLoadHandler.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/24.
//
//

#include "CSVLoadHandler.hpp"

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

vector<Mentor> CSVLoadHandler::loadMentorsDataFromCSV(string fileName){
    vector<Mentor> mentors;
    mentors.clear();
    ofFile file(fileName);
    ofBuffer buffer(file);
    while (!buffer.isLastLine()) {
        string line = buffer.getNextLine();
        //TODO push back new MEntor
        
    }
    return mentors;
}

vector<Member>  CSVLoadHandler::loadMembersDataFromCSV(string fileName){
    vector<Member> members = *new vector<Member>;
    members.clear();
    ofFile file(fileName);
    ofBuffer buffer(file);
    CSVProfileParseHandler * parser = new CSVProfileParseHandler();
    int i = 0;
    while (!buffer.isLastLine()) {
        string line = buffer.getNextLine();
        vector<string> lineElements = split(line, ',');
        
        if(lineElements.size() == 0 || i == 0){
            i++;
            continue;
        }
        
        members.push_back(*new Member(
                                       i,
                                       parser->courseParse(lineElements[1]),
                                       parser->gradeParse(lineElements[3]),
                                       parser->sexParse(lineElements[4]),
                                       "Adress"));
        
    }
    delete parser;
    return members;
}

