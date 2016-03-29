//
//  PMFileSelector.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 29/03/16.
//
//

#ifndef PMFileSelector_h
#define PMFileSelector_h

#include "ofMain.h"
#include "PMTextContainer.h"

class PMFileSelector
{
public:
    PMFileSelector();
    ~PMFileSelector(){};
    
    void draw();
    bool isInside(int x, int y);
    
    //SETERS
    void setFont(ofTrueTypeFont &_font){font = &_font;};
    void setString(string s){text = s;};
    void setPosition(int x, int y);
    void setSize(int width, int height);
    
    void selectToSave();
    void selectToOpen();
    
    
private:
    string text;
    string filePath;
    ofRectangle rectangle;
    ofTrueTypeFont *font;
};


#endif /* PMFileSelector_h */
