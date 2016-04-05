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

enum PMbuttonType{
    PMButtonPlay,
    PMButtonPause,
    PMButtonStop,
    PMButtonRecord,
    PMButtonLoop,
    PMButtonNoLoop,
};

class PMBaseCustomButton{
public:
    PMBaseCustomButton();
    ~PMBaseCustomButton(){};
    
    void draw();
    void setPosition(int x, int y){rectangle.setPosition(x, y);};
    void setSize(int width, int height){rectangle.setSize(width, height);};
    void setIcon(ofPath _icon){iconPath = _icon;};
    void setIconPredefined(PMbuttonType type);
    
    PMbuttonType getIconType(){return buttonType;}
    ofRectangle getIconBoundingBox();
    
    bool isPressed(int x, int y){return rectangle.inside(x,y);};
    
private:
    ofRectangle     rectangle;
    ofPath          iconPath;
    int             iconMargin;
    PMbuttonType    buttonType;
};

#endif /* PMBaseCustomButton_h */
