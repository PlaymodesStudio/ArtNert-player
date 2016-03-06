//
//  PMArtNetRecorder.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetRecorder.h"


bool PMArtNetRecorder::setup(string videoFilename, const char* machineIP, const char* targetIP){
    this->vidFilename = videoFilename;
    vidRecorder.setFfmpegLocation(ofFilePath::getAbsolutePath("ffmpeg"));

    
    artnet.setup(PM_ARTNET_RECORDER, machineIP);
    artnet.setIp(targetIP);
    artnet.start();
}

void PMArtNetRecorder::update(){
    //artnet.sendDmx(video.getFramePixels());
}

void PMArtNetRecorder::draw(int x, int y, int w, int h){
    //video.draw(x, y, w, h);
}