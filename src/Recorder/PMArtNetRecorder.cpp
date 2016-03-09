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
    isRecording = false;
    frame.allocate(171,1,OF_IMAGE_COLOR);

    
    artnet.setup(PM_ARTNET_RECORDER, machineIP);
    artnet.setIp(targetIP);
    artnet.start();
}

void PMArtNetRecorder::update(){
    frame.setFromPixels(artnet.getData(), 171, 1, OF_IMAGE_COLOR);
    vidRecorder.addFrame(frame);
}

void PMArtNetRecorder::draw(int x, int y, int w, int h){
    frame.draw(x, y, w, h);
}