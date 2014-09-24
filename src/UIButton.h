//
//  UIButton.h
//  cooperFORM
//
//  Created by Tangible Media Group on 9/23/14.
//
//

#ifndef __cooperFORM__UIButton__
#define __cooperFORM__UIButton__

#include <iostream>

using namespace std;

class UIButton {
public:
    UIButton();
    UIButton(string name, int xPos, int yPos, int w, int h);
    
    string getName();
    
    
    void draw();
    
    
    // will tell you whether
    // an x,y coordinate is inside the button
    bool overButton(int xPos, int yPos);
    
    void mousePressed();
    void mouseReleased();
    
    // triggered when the mouse has left the button,
    // but didn't release
    void mouseLeft();
    
    // whether or not mouse is pressed on this button
    bool isPressed();
    
private:
    string name;
    int x, y, width, height;
    bool pressed = false;
};

#endif /* defined(__cooperFORM__UIButton__) */