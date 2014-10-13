//
//  UITriggers.cpp
//  cooperFORM
//
//  Created by Jared Counts on 9/24/14.
//
//

// All of the table-specific functions triggered by UI events


#include "UITriggers.h"

void UITriggers::buttonTrigger(UIButton *button) {
    UIHandler *ui = uiHandler;
    string name = button->getName();
    if (ofGetElapsedTimeMillis() - UITriggers::lastModeSwitched > UITriggers::modeSwitchTimeLimit) {
        if (name == "telepresence") {
            reliefApplication->setMode("telepresence");
            uiHandler->select(button);
            uiHandler->showUIGroup("telepresence");
            uiHandler->hideUIGroup("wavy");
            uiHandler->hideUIGroup("3D");
            uiHandler->hideUIGroup("math");
            UITriggers::lastModeSwitched = ofGetElapsedTimeMillis();
        }
        else if (name == "wavy") {
            reliefApplication->setMode("wavy");
            uiHandler->select(button);
            uiHandler->hideUIGroup("telepresence");
            uiHandler->showUIGroup("wavy");
            uiHandler->hideUIGroup("3D");
            uiHandler->hideUIGroup("math");
            UITriggers::lastModeSwitched = ofGetElapsedTimeMillis();
        }
        else if (name == "3D") {
            reliefApplication->setMode("3D");
            uiHandler->select(button);
            uiHandler->hideUIGroup("telepresence");
            uiHandler->hideUIGroup("wavy");
            uiHandler->showUIGroup("3D");
            uiHandler->hideUIGroup("math");
            UITriggers::lastModeSwitched = ofGetElapsedTimeMillis();
        }
        else if (name == "math") {
            reliefApplication->setMode("math");
            uiHandler->select(button);
            uiHandler->hideUIGroup("telepresence");
            uiHandler->hideUIGroup("wavy");
            uiHandler->showUIGroup("3D");
            uiHandler->hideUIGroup("math");
            UITriggers::lastModeSwitched = ofGetElapsedTimeMillis();
        }
    }
}

void UITriggers::sliderTrigger(UISlider *slider) {

}

// initialize relevant static variables
ReliefApplication* UITriggers::reliefApplication;
UIHandler* UITriggers::uiHandler;
int UITriggers::modeSwitchTimeLimit;
long UITriggers::lastModeSwitched;

void UITriggers::registerReliefApplication(ReliefApplication* relief) {
    UITriggers::reliefApplication = relief;
    UITriggers::uiHandler = relief->uiHandler;
    
    // initialize these too
    // since C++ spec won't let us initialize static members in-line the .h file
    UITriggers::modeSwitchTimeLimit = 300;
    UITriggers::lastModeSwitched = 0;
}