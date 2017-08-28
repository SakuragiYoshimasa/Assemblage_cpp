//
//  MembersModel.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef MembersModel_hpp
#define MembersModel_hpp

#include "ofMain.h"
#include "Member.hpp"
#include "CSVLoadHandler.hpp"

class MembersModel {
public:
    MembersModel(){
        load_data();
        cout << "ModelSize" << members.size() << endl;
    }
    
    vector<Member> members;
    void load_data();
};
#endif /* MembersModel_hpp */
