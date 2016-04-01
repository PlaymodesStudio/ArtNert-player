//
//  PMBaseCustomButton.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 01/04/16.
//
//

#include "PMBaseCustomButton.h"

PMBaseCustomButton::PMBaseCustomButton(){
    rectangle.set(0, 0, 20, 20);
    icon.lineTo(10,5);
    icon.lineTo(5, 10);
    icon.close();
}

void PMBaseCustomButton::draw(){
    ofDrawRectRounded(rectangle, 5);
    ofPopMatrix();
        ofTranslate(rectangle.getX(), rectangle.getY());
        ofScale(icon.getBoundingBox().getWidth()/rectangle.getWidth(), icon.getBoundingBox().getHeight()/rectangle.getHeight());
        icon.draw();
    ofPopMatrix();
}