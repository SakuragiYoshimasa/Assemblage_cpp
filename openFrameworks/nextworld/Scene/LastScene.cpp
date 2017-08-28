//
//  LastScene.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/03/04.
//
//

#include "LastScene.hpp"

void LastScene::setup(){
    elements.push_back(new LastScene_StreamShader());
    for(int i = 0; i < elements.size(); i++){
        elements[i]->init();
        
        function<void(void)> cb = [&]{
            nextElement();
        };
        elements[i]->callback = cb;
    }
    
    elements[0]->start();
}