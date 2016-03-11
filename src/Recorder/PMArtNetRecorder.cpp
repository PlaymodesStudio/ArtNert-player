//
//  PMArtNetRecorder.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetRecorder.h"


bool PMArtNetRecorder::setup(string videoFilename, const char* machineIP){
    this->vidFilename = videoFilename;
    
    vidRecorder.setPixelFormat("rgb24");
    vidRecorder.setVideoCodec("png");
    //vidRecorder.setAudioCodec("mp3");
    //vidRecorder.setAudioBitrate("256k");
    isRecording = false;
    frame.allocate(171,1,OF_IMAGE_COLOR);

    
    artnet.setup(PM_ARTNET_RECORDER, machineIP);
    artnet.start();
}

void PMArtNetRecorder::update(){
    frame.setFromPixels(artnet.getData(), 171, artnet.getUniverses(), OF_IMAGE_COLOR);
    vidRecorder.addFrame(frame.getPixels());
}

void PMArtNetRecorder::draw(int x, int y, int w, int h){
    frame.draw(x, y, w, h);
}

void PMArtNetRecorder::start(){
    if(ofGetTargetPlatform() == OF_TARGET_OSX)
        vidRecorder.setup(vidFilename, 171, artnet.getUniverses(), 24, 48000, 2);
    else
        vidRecorder.setup(vidFilename, 171, artnet.getUniverses(), 24);
    
//    artnet.start();
    vidRecorder.start();
}

void PMArtNetRecorder::stop(){
    vidRecorder.close();
}

void PMArtNetRecorder::addAudioBuffer(float *input, int bufferSize, int nChannels){
     vidRecorder.addAudioSamples(input, bufferSize, nChannels);
}