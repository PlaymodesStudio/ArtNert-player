//
//  PMSelectorContainer.h
//  PMCancons_Visuals
//
//  Created by Eduard Frigola on 02/11/15.
//
//

#ifndef PMSelectorContainer_h
#define PMSelectorContainer_h

#include "ofMain.h"

class PMSelectorContainer
{
public:
    PMSelectorContainer();
    ~PMSelectorContainer(){};
    PMSelectorContainer(int x, int y, int width, int height);
    void update(int x, int y);
    void update(int x, int y, int width, int height);
    bool isInside(int x, int y);
    
    int getX(){return x;};
    int getY(){return y;};
    int getWidth(){return width;};
    int getHeight(){return height;};
    
    
protected:
    int x;
    int y;
    int width;
    int height;
};

#endif /* PMSelectorContainer_h */
