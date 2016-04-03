//
//  PMArtNetRecorder.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetRecorder.h"


bool PMArtNetRecorder::setup(const char* machineIP){
    setupBase();
    buildInputDevicesPanel();
    
    //RECORD BUTTON
    recordButton.setPosition(ofGetWidth()-200, ofGetHeight()-100);
    recordButton.setSize(80, 80);
    recordButton.setIconPredefined(PMButtonRecord);
    
    //STOP BUTTON
    stopButton.setPosition(ofGetWidth()-100, ofGetHeight()-100);
    stopButton.setSize(80, 80);
    stopButton.setIconPredefined(PMButtonStop);

    
    this->fileName = "Artnet_Recording"+ofGetTimestampString()+".mov";
    
    vidRecorder.setPixelFormat("rgb24");
    vidRecorder.setVideoCodec("png");
    //vidRecorder.setAudioCodec("mp3");
    //vidRecorder.setAudioBitrate("256k");
    frame.allocate(171,1,OF_IMAGE_COLOR);

    artnet.setup(PM_ARTNET_RECORDER);
//    artnet.start();
    
    soundStream.setDeviceID(0);
    soundStream.setup(0, 2, 48000, 256, 4);
    soundStream.setInput(this);
}

void PMArtNetRecorder::update(){
    frame.setFromPixels(artnet.getData(), 171, artnet.getUniverses(), OF_IMAGE_COLOR);
    vidRecorder.addFrame(frame.getPixels());
}

void PMArtNetRecorder::draw(int x, int y, int w, int h){
    frame.draw(vidImageContainer);
    drawBasicLayout();
    recordButton.draw();
    stopButton.draw();
}

void PMArtNetRecorder::start(){
    if(ofGetTargetPlatform() == OF_TARGET_OSX)
        vidRecorder.setup(fileName, 171, artnet.getUniverses(), 24, 48000, 2);
    else
        vidRecorder.setup(fileName, 171, artnet.getUniverses(), 24);
    
    vidRecorder.start();
}

void PMArtNetRecorder::stop(){
    vidRecorder.close();
}

void PMArtNetRecorder::mousePressed(int x, int y, int button){
    if(fileSelectorCustom.isInside(x, y)){
        fileSelectorCustom.selectToSave();
    }
    if(recordButton.isPressed(x, y) && !vidRecorder.isRecording())
        start();
    if(stopButton.isPressed(x, y))
        stop();
}

//--------------------------------------------------------------
void PMArtNetRecorder::audioIn(float *input, int bufferSize, int nChannels){
    vidRecorder.addAudioSamples(input, bufferSize, nChannels);
}