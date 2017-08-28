//
//  ObserverPattern.cpp
//  CppDpLearning
//
//  Created by SakuragiYoshimasa on 2016/02/05.
//  Copyright © 2016年 SakuragiYoshimasa. All rights reserved.
//

#ifndef ObserverPattern_h
#define ObserverPattern_h

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
    virtual void update();
};

class Subject {
private:
    vector<Observer> observers;
    
public:
    void registerObserver(Observer o){
        observers.push_back(o);
    };
    void removeObserver(Observer o){
        
    };
    void notifyObservers(Observer o){
        for (int i = 0; i < observers.size(); i++) {
            observers.at(i).update(); //引数に情報を与える
        }
    };
};



#endif /* ObserverPattern_h */
