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
    
    bool setup(string videoFilename, const char* machineIP);
    void update();
    void draw(int x, int y, int w, int h);
    
    void start();
    void stop();
    void addAudioBuffer(float *input, int bufferSize, int nChannels);
    
private:
    ofxVideoRecorder vidRecorder;
    string vidFilename;
    bool isRecording;
    ofImage frame;
    
    PMArtNetManager artnet;
};
#endif /* PMArtNetRecorder_h */
