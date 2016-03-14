//
//  PMArtNetSetup.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 14/03/16.
//
//

#include "PMArtNetSetup.h"

void PMArtNetSetup::setup(){
    buttons[0].set(ofGetWidth()/4, ofGetHeight()/2, ofGetWidth()/4, ofGetHeight()/4);
    buttons[1].set(ofGetWidth()*3/4, ofGetHeight()/2, ofGetWidth()/4, ofGetHeight()/4);
    font.load("LucidaGrande.ttc", 20);
}

void PMArtNetSetup::draw(){
    ofPushStyle();
    ofSetColor(ofColor::royalBlue);
    ofSetRectMode(OF_RECTMODE_CENTER);
    for(auto button : buttons)
        ofDrawRectRounded(button, 20);
    ofSetColor(ofColor::rosyBrown);
    drawCenteredFont("Player", buttons[0].getTopLeft().x, buttons[0].getTopLeft().y);
    drawCenteredFont("Recorder", buttons[1].getTopLeft().x, buttons[1].getTopLeft().y);
    
    ofPopStyle();
}

int PMArtNetSetup::checkPress(int x, int y){
    for(int i=0; i<2; i++){
        auto button = buttons[i];
        auto topLeft = button.getTopLeft()-ofPoint(button.getWidth()/2, button.getHeight()/2);
        auto bottomRight = button.getBottomRight() - ofPoint(button.getWidth()/2, button.getHeight()/2);
        if ( x > topLeft.x && x < bottomRight.x && y > topLeft.y && y < bottomRight.y)
            return i+1;
    }
    return -1;
}

void PMArtNetSetup::drawCenteredFont(string str, int x, int y){
    font.drawString(str, x-font.stringWidth(str)/2, y+font.stringHeight(str)/2);
}