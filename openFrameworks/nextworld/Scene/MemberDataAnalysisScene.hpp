//
//  MemberScene.hpp
//  NextWorld
//
//  Created by HirokiNaganuma on 2016/02/24.
//
//

#ifndef MemberScene_hpp
#define MemberScene_hpp


#include "ofMain.h"
#include "ModelManager.hpp"
#include "Scene.hpp"

class MemberDataAnalysisScene : public Scene {
public:
    virtual void setup() override;
    virtual void update() override;
    virtual void draw() override;
};

#endif /* MemberScene_hpp */
