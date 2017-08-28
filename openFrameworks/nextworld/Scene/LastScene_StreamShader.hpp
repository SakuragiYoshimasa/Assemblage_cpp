//
//  LastScene_StreamShader.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/03/04.
//
//

#ifndef LastScene_StreamShader_hpp
#define LastScene_StreamShader_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"

class LastScene_StreamShader : public SceneElement {
    void init() override;
    void draw() override;
    
    ofShader shader;
};

#endif /* LastScene_StreamShader_hpp */
