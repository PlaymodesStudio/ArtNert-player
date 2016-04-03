//
//  PMArtNetManager.hpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#ifndef PMArtNetManager_hpp
#define PMArtNetManager_hpp

#include "ofMain.h"
#include "ofxArtNet.h"

enum pmArtnetFunction {
    PM_ARTNET_RECORDER,
    PM_ARTNET_PLAYER
};

class PMArtNetManager{
    
public:
    PMArtNetManager(){};
    ~PMArtNetManager(){};
    
    bool setMachineIP(string machineIP);
    bool setup(pmArtnetFunction _function);
    void start();
    void setFromPixels(ofPixels &pixels);
    bool sendDmx();
    bool sendDmx(ofPixels &pixels);
    void setTargetIP(string ip){dmxDataPacket.setIp(ip.c_str());};
    unsigned char* getData(){return dmxDataPacket.data;};
    void receiveData(ofxArtNetDmxData &data){dmxDataPacket = data;};
    void receivePollReply(ofxArtNetNodeEntry &node);
    
    vector<pair<string, string>> getIfacesIps(){return artnet.getIfacesIps();};
    
    int getUniverses(){return 1;};
    ofEvent<string> receivedNode;
    
private:
    pmArtnetFunction function;
    ofxArtNet artnet;
    int nUniverses;
    ofxArtNetDmxData dmxDataPacket;
    
};

#endif /* PMArtNetManager_hpp */
