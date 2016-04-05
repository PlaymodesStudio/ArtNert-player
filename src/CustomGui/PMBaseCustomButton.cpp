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
    iconPath.curveTo(0,0);
    iconPath.curveTo(0,0);
    iconPath.curveTo(10,5);
    iconPath.curveTo(5,10);
    iconPath.curveTo(0,0);
    iconPath.curveTo(0,0);
    
    iconMargin = 1;
    //iconPath.close();
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
        iconPath.draw();
    ofPopMatrix();
    ofPopStyle();
}

void PMBaseCustomButton::setIconPredefined(PMbuttonType type){
    switch(type){
        case PMButtonPlay:
        {
            iconPath.clear();
            iconPath.moveTo(0,0);
            iconPath.lineTo(10, 5);
            iconPath.lineTo(0,10);
            iconPath.lineTo(0,0);
            iconPath.setColor(0);
            iconMargin = 5;
            break;
        }
        case PMButtonPause:
        {
            iconPath.clear();
            iconPath.moveTo(0,0);
            iconPath.lineTo(0,10);
            iconPath.moveTo(4,0);
            iconPath.lineTo(4,10);
            iconPath.setColor(0);
            iconPath.setStrokeColor(0);
            iconPath.setStrokeWidth(10);
            iconMargin = 5;
            break;
        }
        case PMButtonStop:
        {
            iconPath.clear();
            iconPath.moveTo(0, 0);
            iconPath.lineTo(10,0);
            iconPath.lineTo(10,10);
            iconPath.lineTo(0, 10);
            iconPath.lineTo(0, 0);
            iconPath.setColor(0);
            iconMargin = 5;
            break;
        }
        case PMButtonRecord:
        {
            iconPath.clear();
            iconPath.arc(10,10,10,10,0,360);
            iconPath.setColor(0);
            iconMargin=5;
            iconPath.setCircleResolution(50);
            break;
        }
        case PMButtonLoop:
        {
            iconPath.clear();
            
            //topArc
            iconPath.arc(ofPoint(189, 160), 150, 150, 220, 360);
            iconPath.arcNegative(ofPoint(189, 160), 107, 107, 360, 220);
            
            //botomArc
            iconPath.arc(ofPoint(189, 160), 150, 150, 40, 180);
            iconPath.arcNegative(ofPoint(189, 160), 107, 107, 180, 40);
            
            //right arrow
            iconPath.moveTo(258, 160);
            iconPath.lineTo(258, 160);
            iconPath.lineTo(310, 212);
            iconPath.lineTo(360, 160);
            iconPath.lineTo(258, 160);
            
            //left arrow
            iconPath.moveTo(120, 160);
            iconPath.lineTo(68, 105);
            iconPath.lineTo(15, 160);
            iconPath.lineTo(120, 160);
            
            iconPath.setColor(0);
            iconMargin=5;
            iconPath.setCircleResolution(90);
            iconPath.setCurveResolution(90);
            break;
        }
        case PMButtonNoLoop:
        {
            setIconPredefined(PMButtonLoop);
            auto lineWidth = 10;
            iconPath.moveTo(0,lineWidth);
            iconPath.lineTo(367-lineWidth, 334);
            iconPath.lineTo(367, 334-lineWidth);
            iconPath.lineTo(lineWidth,0);
            iconPath.moveTo(367, lineWidth);
            iconPath.lineTo(lineWidth, 334);
            iconPath.lineTo(0, 334-lineWidth);
            iconPath.lineTo(367-lineWidth,0);
            break;
        }
    }
    buttonType = type;
}

ofRectangle PMBaseCustomButton::getIconBoundingBox(){
    ofRectangle rect;
    rect.set(0,0,0,0);
    for (auto polyline : iconPath.getOutline()) {
        ofRectangle b = polyline.getBoundingBox();
        rect.growToInclude(b);
    }
    return rect;
}

