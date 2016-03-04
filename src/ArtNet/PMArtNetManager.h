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
    
    bool setup(pmArtnetFunction _function);
    void receiveData(ofxArtNetDmxData &data){data = dmxData;};
    bool sendDmx();
    bool sendDmx(ofPixels pixels);
    void setFromPixels(ofPixels pixels);
    
private:
    pmArtnetFunction function;
    ofxArtNet artnet;
    int nUniverses;
    ofxArtNetDmxData dmxData;
    
};

#endif /* PMArtNetManager_hpp */
