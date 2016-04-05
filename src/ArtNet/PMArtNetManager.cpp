//
//  PMArtNetManager.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetManager.h"

bool PMArtNetManager::setMachineIP(string machineIP){
    
    artnet.init(machineIP);
    ofAddListener(artnet.pollReply, this, &PMArtNetManager::receivePollReply);
    artnet.sendPoll();
    artnet.start();
}

bool PMArtNetManager::setup(pmArtnetFunction _function)
{
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
}

void PMArtNetManager::start(){
    artnet.start();
}

void PMArtNetManager::setFromPixels(ofPixels &pixels){
    for (int i = 0; i < pixels.getHeight(); i++){
        dmxDataPacket[i].data = &pixels[i];
        dmxDataPacket[i].port = i;
    }
}

bool PMArtNetManager::sendDmx(){
    for (auto dmxUniverse : dmxDataPacket)
        artnet.sendDmx(dmxUniverse);
}

bool PMArtNetManager::sendDmx(ofPixels &pixels){
    setFromPixels(pixels);
    sendDmx();
}

void PMArtNetManager::setUniverses(int universes){
    dmxDataPacket.reserve(universes);
}

void PMArtNetManager::receivePollReply(ofxArtNetNodeEntry &node){
    string ipOfNode = node.getIp();
    ofNotifyEvent(receivedNode,ipOfNode);
    cout<<"NODE FOUND: "<<node.getIp()<<endl;
}