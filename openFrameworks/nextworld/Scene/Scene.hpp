//
//  Scene.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#ifndef Scene_hpp
#define Scene_hpp

#include "ofMain.h"
#include "SceneElement.hpp"

class Scene {
public:
    int elementIndex;
    vector<SceneElement *> elements;
    
    virtual void setup()=0;
    void update(){
        elements[elementIndex]->update();
    };
    void draw(){
        elements[elementIndex]->draw();
    };
    
    void nextElement(){
        elements[elementIndex]->end();
        if(elementIndex < elements.size() - 1){
            elementIndex++;
            elements[elementIndex]->start();
        }
    }
};
#endif /* Scene_hpp */
