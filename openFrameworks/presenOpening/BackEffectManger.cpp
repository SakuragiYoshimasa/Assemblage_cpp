//
//  BackEffectManger.cpp
//  presenOpening
//
//  Created by SakuragiYoshimasa on 2016/08/29.
//
//

#include "BackEffectManger.hpp"

void BackEffectManger::setup(){
    effects.push_back(new KinectEffect());
};

void BackEffectManger::update(){
    effects.at(effectIndex)->update();
};

void BackEffectManger::draw(){
    effects.at(effectIndex)->draw();
};

void BackEffectManger::keyPressed(int key){
    effects.at(effectIndex)->keyPressed(key);
};
void BackEffectManger::keyReleased(int key){
    effects.at(effectIndex)->keyPressed(key);
};
void BackEffectManger::mouseMoved(int x, int y ){
    effects.at(effectIndex)->mouseMoved(x, y);
};
void BackEffectManger::mouseDragged(int x, int y, int button){
    effects.at(effectIndex)->mouseDragged(x, y, button);
};
void BackEffectManger::mousePressed(int x, int y, int button){
    effects.at(effectIndex)->mousePressed(x, y, button);
};
void BackEffectManger::mouseReleased(int x, int y, int button){
    effects.at(effectIndex)->mouseReleased(x, y, button);
};