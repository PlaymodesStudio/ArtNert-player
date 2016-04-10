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
    buildUniversesSelector();
    
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

    artnet.setup(PM_ARTNET_RECORDER);
//    artnet.start();
    
    soundStream.setDeviceID(0);
    soundStream.setup(0, 2, 48000, 256, 4);
    soundStream.setInput(this);
}

void PMArtNetRecorder::update(){
    if(artnet.isStarted()){
        vector<unsigned char> pixels;
        pixels.assign(513*n_universes, sizeof(unsigned char));
        //memset(&pixels, 0, 513*n_universes);
        for (int i = 0; i < n_universes ; i++){
            for(int j=0; j < 512 ; j++){
                pixels[(i*513)+j] = artnet.getData(i)[j];
            }
            pixels[((i+1)*513)-1] = ' ';
        }
        frame.setFromPixels(pixels.data(), 171, n_universes, OF_IMAGE_COLOR);
        //frame.setFromPixels(artnet.getData(0).data(), 171, 1, OF_IMAGE_COLOR);
        vidRecorder.addFrame(frame.getPixels());
    }
}

void PMArtNetRecorder::draw(int x, int y, int w, int h){
    if(artnet.isStarted())
        frame.draw(vidImageContainer);
    drawBasicLayout();
    universesSelector.draw();
    recordButton.draw();
    stopButton.draw();
}

void PMArtNetRecorder::start(){
    if(ofGetTargetPlatform() == OF_TARGET_OSX)
        vidRecorder.setup(fileName, 171, n_universes, 24, 48000, 2);
    else
        vidRecorder.setup(fileName, 171, n_universes, 24);
    
    vidRecorder.start();
}

void PMArtNetRecorder::stop(){
    vidRecorder.close();
}

void PMArtNetRecorder::buildUniversesSelector(){
    string UNIVERSESSELECTOR_SETTINGS_FILENAME = "NumUniversesSettings.xml";
    universesSelector.setup("MACHINE IP", UNIVERSESSELECTOR_SETTINGS_FILENAME);
    universesSelector.setPosition(vidImageContainer.getRight()+10, 0);
    universesSelector.setHeaderBackgroundColor(ofGetBackgroundColor());
    
    universesTrigger.addListener(this, &PMArtNetRecorder::setUniverses);
    universesSelector.add(universesSlider.setup("Num Universes", 1, 1, 16));
    universesSelector.add(universesTrigger.setup("Set Num Universes"));
    
    //ofFile file(MACHINEIP_SETTINGS_FILENAME);
    //if (file.exists()) file.remove();
    
    universesSelector.loadFromFile(UNIVERSESSELECTOR_SETTINGS_FILENAME);
    
    universesSelector.setSize(300 , 300);
    universesSelector.setWidthElements(300);

}

void PMArtNetRecorder::setUniverses(){
    buildNodesPanel(universesSlider);
    artnet.setUniverses(universesSlider);
    n_universes = universesSlider;
    frame.allocate(171,universesSlider,OF_IMAGE_COLOR);
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