//
//  PMImageContainer.h
//  PMCancons_Visuals
//
//  Created by Eduard Frigola on 02/11/15.
//
//

#ifndef PMImageContainer_h
#define PMImageContainer_h

#include "PMSelectorContainer.h"

class PMImageContainer : public PMSelectorContainer
{
public:
    PMImageContainer(ofImage image);
    PMImageContainer(string filename);
    PMImageContainer(int x, int y, int width, int height, ofImage image);
    void draw();
    void setImage(ofImage image);
    void loadImage(string _filename);
    void setSize(int _width, int _height){width=_width; height=_height;};
    void setAngle(float angle);
    
private:
    ofImage image;
    float angle;
};

#endif /* PMImageContainer_h */
