//
//  PMVideoManager.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMVideoManager.h"

bool PMVideoManager::setup(pmVideoFunction _function, string filename, ofLoopType loopType){
    
    if(_function == PM_VIDEO_PLAYER){
        videoPlayer.setPixelFormat(OF_PIXELS_RGB); //set pixel type to NATIVE, although it has to be always rgb
        videoPlayer.load(filename);  //load Video
        videoPlayer.setLoopState(loopType);
    }else{
        videoRecorder.setFfmpegLocation(ofFilePath::getAbsolutePath("ffmpeg"));
    }
    
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

