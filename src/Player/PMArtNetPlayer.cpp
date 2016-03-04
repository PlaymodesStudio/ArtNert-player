//
//  PMArtNetPlayer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetPlayer.h"


bool PMArtNetPlayer::setup(string videoFilename){
    video.setup(videoFilename, OF_LOOP_NONE);
}

void PMArtNetPlayer::update(){
    video.getFramePixels();
}
