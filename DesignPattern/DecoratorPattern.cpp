//
//  DecoratorPattern.cpp
//  CppDpLearning
//
//  Created by SakuragiYoshimasa on 2016/02/05.
//  Copyright © 2016年 SakuragiYoshimasa. All rights reserved.
//

//Decoratorで装飾していく,Classの発散を防ぐ
//オブジェクトに付加的な責務をどう的に付与する。デコレータはサブクラス化の代替となる柔軟な機能拡張手段を提供する

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Beverage {
public:
    string description = "不明な飲み物";
    
    virtual string getDescription(){
        return description;
    }
    
    virtual double cost()=0;
};

class CondimentDecorator : public Beverage {
public:
    string getDescription();
};

class Espresso : public Beverage {
public:
    Espresso(){
        description = "エスプレッソ";
    }
    
    double cost(){
        return 1.99;
    }
};

class Mocha : CondimentDecorator {
public:
    Beverage * beverage;
    
    Mocha(Beverage * beverage){
        this->beverage = beverage;
    }
    
    string getDescription(){
        return beverage->getDescription() + ",モカ";
    }
    
    double cost(){
        return beverage->cost() + 0.20;
    }
};

