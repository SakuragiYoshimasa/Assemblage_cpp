//
//  TimeManager.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef TimeManager_hpp
#define TimeManager_hpp

#include "ofMain.h"
#include "Manager.hpp"

class TimeManager : public Manager {
private:
    TimeManager(){}
    int spentFrame;
    float deltaTime;
    float ElapesedTimef;
    
public:
    static TimeManager & getInstance(){
        static TimeManager sharedInstance;
        return sharedInstance;
    }
    
    void setup() override;
    void update() override;
    
    int getSpentFrame(){
        return spentFrame;
    }
    
    float getDeltaTime(){
        return deltaTime;
    }
    
    float getElapsedTime(){
        return ElapesedTimef;
    }
};

#endif /* TimeManager_hpp */
