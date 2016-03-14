//
//  PMArtNetSetup.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 14/03/16.
//
//

#ifndef PMArtNetSetup_h
#define PMArtNetSetup_h

#include "ofMain.h"

class PMArtNetSetup{
public:
    PMArtNetSetup(){};
    ~PMArtNetSetup(){};
    
    void setup();
    void draw();
    
    int checkPress(int x, int y);
    
    void drawCenteredFont(string str, int x, int y);
    
private:
    ofRectangle buttons[2];
    ofTrueTypeFont font;
};

#endif /* PMArtNetSetup_h */
