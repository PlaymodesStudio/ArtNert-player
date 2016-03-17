//
//  PMArtNetPlayer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetPlayer.h"


bool PMArtNetPlayer::setup(string videoFilename, const char* machineIP, const char* targetIP){
    setupBase();
    buildOutputDevicesPanel();
    
    videoPlayer.setPixelFormat(OF_PIXELS_RGB); //set pixel type to NATIVE, although it has to be always rgb
    videoPlayer.load(videoFilename);  //load Video
    videoPlayer.setLoopState(OF_LOOP_NORMAL);
    
    artnet.setup(PM_ARTNET_PLAYER);
    artnet.setTargetIP(targetIP);
//    artnet.start();
}

void PMArtNetPlayer::update(){
    videoPlayer.update();
    artnet.sendDmx(videoPlayer.getPixels());
}

void PMArtNetPlayer::draw(int x, int y, int w, int h){
    videoPlayer.draw(vidImageContainer);
    drawBasicLayout();
}