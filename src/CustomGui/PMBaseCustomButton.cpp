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
    ofPopMatrix();
        ofPoint scale = ofPoint(rectangle.getWidth()/(icon.getBoundingBox().getWidth()+iconMargin), rectangle.getHeight()/(icon.getBoundingBox().getHeight()+iconMargin));
        ofTranslate(rectangle.getX()+(iconMargin*scale.x/2), rectangle.getY()+iconMargin*scale.y/2);
        ofScale(scale);
        icon.draw();
    ofPopMatrix();
    ofPopStyle();
}

void PMBaseCustomButton::setIconPredefined(PMbuttonType type){
    switch(type){
        case PMButtonPlay:
            int curveRes = 500;
            icon.clear();
            icon.curveTo(0,10, curveRes);
            icon.curveTo(0,0, curveRes);
            icon.curveTo(10,5, curveRes);
            icon.curveTo(0,10, curveRes);
            icon.curveTo(0,0, curveRes);
            icon.curveTo(0,0, curveRes);
            iconMargin = 5;
    }
}