//
//  PMArtNetPlayer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetPlayer.h"


bool PMArtNetPlayer::setup(string videoFilename, const char* targetIP){
    video.setup(videoFilename, OF_LOOP_NORMAL);
    artnet.setup(PM_ARTNET_PLAYER);
    artnet.setIp(targetIP);
    artnet.start();
    video.start();
}

void PMArtNetPlayer::update(){
    video.update();
    artnet.sendDmx(video.getFramePixels());
}

void PMArtNetPlayer::draw(int x, int y, int w, int h){
    video.draw(x, y, w, h);
}