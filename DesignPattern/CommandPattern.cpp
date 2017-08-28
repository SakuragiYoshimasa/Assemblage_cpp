//
//  CommandPattern.cpp
//  CppDpLearning
//
//  Created by SakuragiYoshimasa on 2016/02/20.
//  Copyright © 2016年 SakuragiYoshimasa. All rights reserved.
//

/*
 リクエストをオブジェクトとしてカプセル化してその結果、
 他のオブジェクトを異なるリクエスト、キュー、またはログリクエストで
 パラメータ化でき、アンドゥ可能な操作もサポートする。
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Light {
public:
    void on(){};
    void off(){};
};

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class LightOnCommand : public Command {
public:
    Light light; //レシーバ
    
    LightOnCommand(Light light){
        this->light = light;
    }
    
    void execute(){
        light.on();
    }
    
    //取り消す処理をする
    void undo(){
        light.off();
    }
};

//リモコンはコマンドが何をするか知る必要はない
class SimpleRemoteControl {
public:
    Command * slot;
    
    void setCommand(Command * command){
        slot = command;
    }
    
    void buttonWasPresssed(){
        slot->execute();
    }
};


//マクロコマンド
class MacroCommand : Command {
    vector<Command*> commands;
    
    MacroCommand(vector<Command*> commands){
        this->commands = commands;
    }
    
    void execute(){
        for(int i = 0; i < commands.size(); i++){
            commands[i]->execute();
        }
    }

    void undo(){}
};
