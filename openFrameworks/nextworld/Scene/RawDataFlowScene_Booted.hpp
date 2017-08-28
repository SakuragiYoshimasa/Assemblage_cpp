//
//  RawDataFlowScene_Booted.hpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/28.
//
//

#ifndef RawDataFlowScene_Booted_hpp
#define RawDataFlowScene_Booted_hpp

#include "SceneElement.hpp"
#include "TimeManager.hpp"
#include "PointCloudPainter.hpp"

class RawDataFlowScene_Booted : public SceneElement {
    void init() override;
    void start() override;
    void update() override;
    void end() override;
    void draw() override;
    
    string dataString;

};

#endif /* RawDataFlowScene_Booted_hpp */
