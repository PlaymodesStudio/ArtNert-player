//
//  PMVideoManager.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMVideoManager.h"

bool PMVideoManager::setup(string filename, ofLoopType loopType){
    
    videoPlayer.setPixelFormat(OF_PIXELS_RGB); //set pixel type to NATIVE, although it has to be always rgb
    videoPlayer.load(filename);  //load Video
    
    videoPlayer.setLoopState(loopType);
    
    return true;
}


void PMVideoManager::update(){
    videoPlayer.update();
}

void PMVideoManager::draw(int x, int y, int width, int height){
    videoPlayer.draw(x, y, width, height);
}

ofPixels& PMVideoManager::getFramePixels(){
    return videoPlayer.getPixels();
}

