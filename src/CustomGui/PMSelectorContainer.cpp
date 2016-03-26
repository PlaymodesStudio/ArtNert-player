//
//  PMSelectorContainer.cpp
//  PMCancons_Visuals
//
//  Created by Eduard Frigola on 02/11/15.
//
//

#include "PMSelectorContainer.h"

PMSelectorContainer::PMSelectorContainer()
{
    this->x=ofGetWidth()/2;
    this->y=ofGetHeight()/2;
    this->width=ofGetWidth()/20;
    this->height=ofGetHeight()/20;
}

PMSelectorContainer::PMSelectorContainer(int _x, int _y, int _width, int _height)
{
    this->x=_x;
    this->y=_y;
    this->width=_width;
    this->height=_height;
}

void PMSelectorContainer::update(int _x, int _y)
{
    this->x=_x;
    this->y=_y;
}

void PMSelectorContainer::update(int _x, int _y, int _width, int _height)
{
    this->x=_x;
    this->y=_y;
    this->width=_width;
    this->height=_height;
}

bool PMSelectorContainer::isInside(int _x, int _y)
{
    int x1=x-width/2;
    int x2=x+width/2;
    int y1=y-height/2;
    int y2=y+height/2;
    if(_x>=x1 && _x<=x2 && _y>=y1 && _y<=y2){
        return true;
    }else{
        return false;
    }
}