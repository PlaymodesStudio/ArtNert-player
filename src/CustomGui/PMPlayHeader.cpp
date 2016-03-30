//
//  PMPlayHeader.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 29/03/16.
//
//

#include "PMPlayHeader.h"

PMPlayHeader::PMPlayHeader(){
    rectangle = ofRectangle(0,0, 10, 20);
    header = ofRectangle(0,0, 10, 40);
    headerPos = 0;
    duration = 0;
}


void PMPlayHeader::draw(){
    ofPushStyle();
        ofSetColor(ofColor::white);
        ofDrawRectangle(rectangle);
        ofPushMatrix();
            ofSetColor(ofColor::black);
            ofTranslate((headerPos*rectangle.getWidth())+rectangle.getX(), rectangle.getY());
            ofDrawRectRounded(header, 2);
        ofPopMatrix();
    ofPopStyle();
    cout<<"position: "<<headerPos<<"   Duration: "<<duration<<endl;
}

bool PMPlayHeader::dragged(int x, int y){
    if(rectangle.inside(x,y)){
        headerPos = (x-rectangle.getX())/rectangle.getWidth();
        float toSend = headerPos;//*duration;
        ofNotifyEvent(headerDragged, toSend, this);
        return true;
    }
}