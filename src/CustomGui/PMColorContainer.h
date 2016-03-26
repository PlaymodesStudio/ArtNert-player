//
//  PMColorContainer.h
//  PMCancons_Visuals
//
//  Created by Eduard Frigola on 02/11/15.
//
//

#ifndef PMColorContainer_h
#define PMColorContainer_h

#include "PMSelectorContainer.h"

class PMColorContainer :public PMSelectorContainer
{
public:
    PMColorContainer(){PMSelectorContainer();};
    ~PMColorContainer(){};
    PMColorContainer(int x, int y, int width, int height, ofColor color);
    void draw();
    void setColor(ofColor color);

private:
    ofColor color;
};

#endif /* PMColorContainer_h */
