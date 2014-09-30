//
//  UISlider.h
//  cooperFORM
//
//  Created by Tangible Media Group on 9/26/14.
//
//

#ifndef __cooperFORM__UISlider__
#define __cooperFORM__UISlider__

#include <iostream>

using namespace std;

//        handle
//     track |
//       |   v
//       v  ___
// ---------| |--
//          ---

class UISlider {
public:
    UISlider();
    UISlider(string name, bool horizontal, int trackX, int trackY, int trackLength, int handleWidth, int handleHeight);
    
    void draw();
    
    int getHandleX();
    int getHandleY();

    // will tell you whether
    // an x,y coordinate is inside the button
    bool overHandle(int xPos, int yPos);
    
    void mousePressed(int x, int y);
    void mouseDragged(int x, int y);
    void mouseReleased();

    bool isGrabbed();
private:
    string name;
    
    int trackX, trackY;
    
    // how far along the track the handle is
    // value is from 0 to 1
    double handlePos;
    
    int trackLength;
    int handleWidth, handleHeight;
    
    // true for horizontal
    // false for vertical
    bool horizontal;
    
    bool grabbed = false;
    int mouseOffsetX, mouseOffsetY;
};

#endif /* defined(__cooperFORM__UISlider__) */
