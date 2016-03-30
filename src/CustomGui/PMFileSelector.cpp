//
//  PMFileSelector.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 29/03/16.
//
//

#include "PMFileSelector.h"

PMFileSelector::PMFileSelector(){
    text = "Nothing";
}

void PMFileSelector::draw(){
    ofSetColor(ofColor::red);
    ofDrawRectRounded(rectangle, 5);
    
    ofSetColor(ofColor::green);
    int x = rectangle.getX() + 20;
    int y = rectangle.getY()+rectangle.getHeight() - ((rectangle.getHeight()-(font->stringHeight(text)))/1.5);   //font->stringHeight(text);
    font->drawString(text, x, y);
}

bool PMFileSelector::isInside(int x, int y){
    return rectangle.inside(x, y);
}

void PMFileSelector::setPosition(int x, int y){
    rectangle.setPosition(x, y);
}

void PMFileSelector::setSize(int width, int height){
    rectangle.setSize(width, height);
}


void PMFileSelector::selectToSave(){
    ofFileDialogResult result = ofSystemSaveDialog("hola.mov", "Select Save File");
    text = result.getName();
    filePath = result.getPath();
}

void PMFileSelector::selectToOpen(){
    ofDirectory dir("");
    ofFileDialogResult result = ofSystemLoadDialog(" ", false, dir.getAbsolutePath());
    text = result.getName();
    filePath = result.getPath();
}