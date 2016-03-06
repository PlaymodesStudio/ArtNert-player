//
//  PMArtNetRecorder.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#ifndef PMArtNetRecorder_h
#define PMArtNetRecorder_h

#include "ofMain.h"
#include "PMArtNetManager.h"
#include "ofxVideoRecorder.h"


class PMArtNetRecorder{
    
public:
    PMArtNetRecorder(){};
    ~PMArtNetRecorder(){};
    
    bool setup(string videoFilename, const char* machineIP, const char* targetIP);
    void update();
    void draw(int x, int y, int w, int h);
    int getVideoFrameRate();
    
private:
    ofxVideoRecorder vidRecorder;
    string vidFilename;
    
    PMArtNetManager artnet;
};
#endif /* PMArtNetRecorder_h */
