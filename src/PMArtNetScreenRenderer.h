//
//  PMArtNetScreenRenderer.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 11/03/16.
//
//

#ifndef PMArtNetScreenRenderer_h
#define PMArtNetScreenRenderer_h

#include "ofMain.h"

class PMArtNetScreenRenderer{
protected:
    void setupBase();
    void drawBasicLayout();
    
    ofRectangle vidImageContainer;
    string fileName;
};

#endif /* PMArtNetScreenRenderer_h */
