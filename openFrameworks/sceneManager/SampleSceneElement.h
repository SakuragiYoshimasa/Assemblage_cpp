//
//  SampleSceneElement.hpp
//  SceneManagerSample
//
//  Created by 櫻木善将 on 2015/10/26.
//
//

#ifndef SampleSceneElement_h
#define SampleSceneElement_h

#include "SceneElement.cpp"
class SampleSceneElement : public SceneElement {
public:
    void draw() override;
    SampleSceneElement();
    
private:
    ofColor backgroundColor;
};
#endif
