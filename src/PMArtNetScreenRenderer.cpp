//
//  PMArtNetScreenRenderer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 11/03/16.
//
//

#include "PMArtNetScreenRenderer.h"

void PMArtNetScreenRenderer::setupBase(){
    vidImageContainer.set(0,0,ofGetWidth()/2, ofGetHeight()/2);
}

void PMArtNetScreenRenderer::drawBasicLayout(){
    ofDrawBitmapString(ofGetFrameRate(), 20, ofGetHeight()-20);
}
