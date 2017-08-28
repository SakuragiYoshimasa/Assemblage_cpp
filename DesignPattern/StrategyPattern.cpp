//
//  StrategyPattern.hpp
//  CppDpLearning
//
//  Created by SakuragiYoshimasa on 2016/02/05.
//  Copyright © 2016年 SakuragiYoshimasa. All rights reserved.
//


//一連のアルゴリズムを定義し、それぞれをカプセル化して交換可能にする
//StrategyPatternによってアルゴリズムを使用するクライアントとは独立してアルゴリズムを変更できる

#ifndef StrategyPattern_hpp
#define StrategyPattern_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


class FlyBehavior{
public:
    virtual void fly()=0;
};

class QuackBehavior{
public:
    virtual void quack()=0;
};


class FlyWithWings : public FlyBehavior {
public:
    void fly(){
        cout << "FlyWing!" << endl;
    }
};

class Quack : public QuackBehavior {
public:
    void quack(){
        cout << "quaqua" << endl;
    }
};

class Duck{
public:
    FlyBehavior * fb;
    QuackBehavior * qb;
    
    Duck(){
        fb = new FlyWithWings();
        qb = new Quack();
        
    };
    
    void fly(){
        fb->fly();
    }
    
    void quack(){
        qb->quack();
    }
};
#endif /* StrategyPattern_hpp */
