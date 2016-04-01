//
//  PMBaseCustomButton.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 01/04/16.
//
//

#ifndef PMBaseCustomButton_h
#define PMBaseCustomButton_h

#include "ofMain.h"

class PMBaseCustomButton{
public:
    PMBaseCustomButton();
    ~PMBaseCustomButton(){};
    
    void draw();
    void setPosition(int x, int y){rectangle.setPosition(x, y);};
    void setSize(int width, int height){rectangle.setSize(width, height);};
    
    bool isPressed(int x, int y){return rectangle.inside(x,y);};
    
private:
    ofRectangle     rectangle;
    ofPolyline      icon;
};

#endif /* PMBaseCustomButton_h */
