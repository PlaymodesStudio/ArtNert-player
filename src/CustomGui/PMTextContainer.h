//
//  PMTextContainer.h
//  PMCancons_Visuals
//
//  Created by Eduard Frigola on 02/11/15.
//
//

#ifndef PMTextContainer_h
#define PMTextContainer_h

#include "PMSelectorContainer.h"

class PMTextContainer : public PMSelectorContainer
{
public:
    PMTextContainer();
    ~PMTextContainer(){};
    PMTextContainer(int x, int y, string s, ofTrueTypeFont &font, float scale);
    PMTextContainer(int x, int y, string s, ofTrueTypeFont &font);
    //PMTextContainer(int x, int y, string s, ofTrueTypeFont &font, float scale);
    void draw();
    void draw(float scale);
    void setFont(ofTrueTypeFont &font);
    void setScale(float _scale);
    void setString(string _s);
    string getString(){return s;};
    
private:
    string s;
    ofTrueTypeFont *font;
    float scale;
    float scaledWidth, scaledHeight;
};

#endif /* PMTextContainer_h */
