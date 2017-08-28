//
//  ModelManager.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef ModelManager_hpp
#define ModelManager_hpp

#include "MembersModel.hpp"
#include "MentorsModel.hpp"

class ModelManager {
private:
    ModelManager(){
    }
    
    MentorsModel mentorsModel;
    MembersModel membersModel;
public:
    static ModelManager & getInstance(){
        static ModelManager sharedInstance;
        return sharedInstance;
    }
    
    MentorsModel & getMentorsModel(){
        return this->mentorsModel;
    }
    
    MembersModel & getMembersModel(){
        return this->membersModel;
    }

};
#endif /* ModelManager_hpp */
