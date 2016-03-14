//
//  PMArtNetScreenRenderer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 11/03/16.
//
//

#include "PMArtNetScreenRenderer.h"

void PMArtNetScreenRenderer::drawBasicLayout(){
    ofDrawBitmapString(ofGetFrameRate(), 20, ofGetHeight()-20);
}