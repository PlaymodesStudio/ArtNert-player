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
    icon.curveTo(0,0);
    icon.curveTo(0,0);
    icon.curveTo(10,5);
    icon.curveTo(5,10);
    icon.curveTo(0,0);
    icon.curveTo(0,0);
    //icon.close();
}

void PMBaseCustomButton::draw(){
    ofPushStyle();
    ofSetColor(ofColor::blueSteel);
    ofDrawRectRounded(rectangle, 5);
    ofSetColor(0);
    ofPushMatrix();
        ofPoint scale = ofPoint(rectangle.getWidth()/(getIconBoundingBox().getWidth()+iconMargin), rectangle.getHeight()/(getIconBoundingBox().getHeight()+iconMargin));
        ofTranslate(rectangle.getX()+(iconMargin*scale.x/2), rectangle.getY()+iconMargin*scale.y/2);
        ofScale(scale);
        icon.draw();
    ofPopMatrix();
    ofPopStyle();
}

void PMBaseCustomButton::setIconPredefined(PMbuttonType type){
    switch(type){
        case PMButtonPlay:
        {
            icon.clear();
            icon.moveTo(0,0);
            icon.lineTo(10, 5);
            icon.lineTo(0,10);
            icon.lineTo(0,0);
            icon.setColor(0);
            iconMargin = 5;
            break;
        }
        case PMButtonPause:
        {
            icon.clear();
            icon.moveTo(0,0);
            icon.lineTo(0,10);
            icon.moveTo(4,0);
            icon.lineTo(4,10);
            icon.setColor(0);
            icon.setStrokeColor(0);
            icon.setStrokeWidth(10);
            iconMargin = 5;
            break;
        }
        case PMButtonStop:
        {
            
            break;
        }
    }
}

ofRectangle PMBaseCustomButton::getIconBoundingBox(){
    ofRectangle rect;
    rect.set(0,0,0,0);
    for (auto polyline : icon.getOutline()) {
        ofRectangle b = polyline.getBoundingBox();
        rect.growToInclude(b);
    }
    return rect;
}

