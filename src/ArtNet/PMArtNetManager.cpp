//
//  PMArtNetManager.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetManager.h"

bool PMArtNetManager::setup(pmArtnetFunction _function, const char* machineIp)
{
    artnet.init(machineIp);
    if(_function == PM_ARTNET_PLAYER){
        artnet.setSubNet(0);
        artnet.setPortType(0, ARTNET_PORT_ENABLE_INPUT, ARTNET_DATA_DMX);
        artnet.setPortAddress(0, ARTNET_PORT_INPUT, 0);
    }else{
        artnet.setShortName("Artnet receive");
        artnet.setLongName("Artnet Mac receiver");
        artnet.setNodeType(ARTNET_TYPE_NODE);
        artnet.setSubNet(0);
        artnet.setPortType(0, ARTNET_PORT_ENABLE_OUTPUT, ARTNET_DATA_DMX);
        artnet.setPortAddress(0, ARTNET_PORT_OUTPUT, 0);
        ofAddListener(artnet.dmxData, this, &PMArtNetManager::receiveData);
    }
    //artnet.sendPoll("192.168.1.112");
}

void PMArtNetManager::start(){
    artnet.start();
}

void PMArtNetManager::setFromPixels(ofPixels &pixels){
    dmxData.data = pixels;
//    for (int i=0; i<512; i++){
//        dmxData.data[i] = ofRandom(255);
//    }
}

bool PMArtNetManager::sendDmx(){
    artnet.sendDmx(dmxData);
}

bool PMArtNetManager::sendDmx(ofPixels &pixels){
    setFromPixels(pixels);
    sendDmx();
}