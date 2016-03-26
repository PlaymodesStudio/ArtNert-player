//
//  PMImageContainer.cpp
//  PMCancons_Visuals
//
//  Created by Eduard Frigola on 02/11/15.
//
//

#include "PMImageContainer.h"

PMImageContainer::PMImageContainer(ofImage _image)
{
    this->image=_image;
    this->x=ofRandomWidth();
    this->y=ofRandomHeight();
    this->width=20;
    this->height=20;
    this->angle=0;
}

PMImageContainer::PMImageContainer(string filename)
{
    image.load(filename);
    this->x=ofRandomWidth();
    this->y=ofRandomHeight();
    this->width=20;
    this->height=20;
    this->angle=0;
}

PMImageContainer::PMImageContainer(int _x, int _y, int _width, int _height, ofImage _image)
{
    this->image=_image;
    this->x=_x;
    this->y=_y;
    this->width=_width;
    this->height=_height;
    this->angle=0;
}

void PMImageContainer::draw()
{
        ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
        ofTranslate(x, y, 0);
        ofRotateZ(angle);
        image.draw(0,0,width, height);
    ofPopMatrix();
    ofSetRectMode(OF_RECTMODE_CORNER);
}

void PMImageContainer::setImage(ofImage _image)
{
    image=_image;
}

void PMImageContainer::loadImage(string filename)
{
    image.load(filename);
}

void PMImageContainer::setAngle(float _angle)
{
    angle=_angle;
}