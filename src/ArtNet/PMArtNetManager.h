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
    void setTargetIP(string ip, int universe){dmxDataPacket[universe].setIp(ip);};
    vector<unsigned char> getData(int universe){return dmxDataPacket[universe].getData();};
    void receiveData(ofxArtNetDmxData &data){dmxDataPacket[data.getPort()] = data;};
    void receivePollReply(ofxArtNetNodeEntry &node);
    bool isStarted(){return bStarted;};
    vector<pair<string, string>> getIfacesIps(){return artnet.getIfacesIps();};
    
    int getUniverses(){return dmxDataPacket.size();};
    void setUniverses(int universes);
    ofEvent<string> receivedNode;
    
private:
    bool bStarted;
    pmArtnetFunction function;
    ofxArtNet artnet;
    int nUniverses;
    vector<ofxArtNetDmxData> dmxDataPacket;
    
};

#endif /* PMArtNetManager_hpp */
