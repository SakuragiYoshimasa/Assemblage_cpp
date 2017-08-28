//
//  AdaptorPattern.cpp
//  CppDpLearning
//
//  Created by SakuragiYoshimasa on 2016/02/22.
//  Copyright © 2016年 SakuragiYoshimasa. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*
 オブジェクトアダプタ
 クラスのインターフェイスをクライアントが期待する別のインターフェイスに変換する。
 アダプタは互換性のないインターフェイスのためにそのままでは連携できないクラスを連携させる
 クラスアダプタ
 多重継承が必要
 
*/

class Duck {
public:
    virtual void quack() = 0;
    virtual void fky() = 0;
};

class MallardDack : Duck {
public:
    void quack(){
        printf("ga-ga-");
    }
    
    void fly(){
        printf("flying");
    }
};

class Turkey {
public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey : Turkey {
public:
    void gobble(){
        printf("gorogoro");
    }
    
    void fly(){
        printf("Short fly");
    }
};

class TurkeyAdaptor : Duck {
public:
    Turkey * turkey;
    TurkeyAdaptor(Turkey * turkey){
        this->turkey = turkey;
    }
    
    void quack(){
        turkey->gobble();
    }
    
    void fly(){
        for(int i = 0; i < 5; i++){
            turkey->fly();
        }
    }
};