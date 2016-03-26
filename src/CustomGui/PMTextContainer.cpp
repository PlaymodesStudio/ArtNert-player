//
//  PMTextContainer.cpp
//  PMCancons_Visuals
//
//  Created by Eduard Frigola on 02/11/15.
//
//

#include "PMTextContainer.h"

PMTextContainer::PMTextContainer(){
    PMSelectorContainer();
    s = "Nothing";
    scale = 1;
}

PMTextContainer::PMTextContainer(int _x, int _y, string _s, ofTrueTypeFont &_font, float _scale)
{
    this->scale=_scale;
    this->s=_s;
    this->font=&_font;
    this->x=_x;
    this->y=_y;
    this->width=font->stringWidth(s);
    this->height=font->stringHeight(s);
    this->scaledWidth=width*scale;
    this->scaledHeight=height*scale;
}

PMTextContainer::PMTextContainer(int _x, int _y, string _s, ofTrueTypeFont &_font)
{
    this->s=_s;
    this->font=&_font;
    this->scale=1;
    this->x=_x;
    this->y=_y;
    this->width=(font->stringWidth(s));
    this->height=(font->stringHeight(s));
    this->scaledWidth=width;
    this->scaledHeight=height;
}

void PMTextContainer::draw()
{
    ofSetColor(ofColor::white);
//    font->drawString(s, x-(scaledWidth/2), y+(scaledHeight/2));
    ofPushMatrix();
        ofTranslate(x, y);
        ofScale(scale, scale);
        ofSetColor(ofColor::white);
        font->drawString(s, -(width)/2, (height)/2);
    ofPopMatrix();

}

void PMTextContainer::draw(float _scale)
{
    setScale(_scale);
    ofPushMatrix();
        ofTranslate(x, y);
        ofScale(scale, scale);
        ofSetColor(ofColor::white);
        font->drawString(s, -(width)/2, (height)/2);
    ofPopMatrix();
}

void PMTextContainer::setString(string _s)
{
    this->s = _s;
    this->width = font->stringWidth(s);
    this->height = font->stringHeight(s);
    this->scaledWidth = width * scale;
    this->scaledHeight = height * scale;
}

void PMTextContainer::setFont(ofTrueTypeFont &_font)
{
    this->font=&_font;
    this->width=font->stringWidth(s);
    this->height=font->stringHeight(s);
    this->scaledWidth = width * scale;
    this->scaledHeight = height * scale;
}

void PMTextContainer::setScale(float _scale)
{
    scale=_scale;
    scaledWidth=width*scale;
    scaledHeight=height*scale;
}