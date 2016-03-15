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
    auto ippairs = artnet.getIfacesIps();
    for (auto ippair : ippairs)
        cout<<ippair.first<<"   "<<ippair.second<<endl;
    auto ip = artnet.getIP();
    artnet.init(ip);
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
    artnet.sendPoll("192.168.1.112");
}

void PMArtNetManager::start(){
    artnet.start();
}

void PMArtNetManager::setFromPixels(ofPixels &pixels){
    dmxDataPacket.data = pixels;
}

bool PMArtNetManager::sendDmx(){
    artnet.sendDmx(dmxDataPacket);
}

bool PMArtNetManager::sendDmx(ofPixels &pixels){
    setFromPixels(pixels);
    sendDmx();
}