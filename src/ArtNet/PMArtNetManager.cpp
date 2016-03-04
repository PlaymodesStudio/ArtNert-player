//
//  PMArtNetManager.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetManager.h"

bool PMArtNetManager::setup(pmArtnetFunction _function)
{
    if(function == PM_ARTNET_PLAYER){
        
    }else{
        
    }
}

void PMArtNetManager::setFromPixels(ofPixels pixels){
    dmxData.data = pixels;
}

bool PMArtNetManager::sendDmx(){
    artnet.sendDmx(dmxData);
}

bool PMArtNetManager::sendDmx(ofPixels pixels){
    setFromPixels(pixels);
    sendDmx();
}