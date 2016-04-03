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
#include "PMArtNetScreenRenderer.h"
#include "ofxVideoRecorder.h"

class PMArtNetRecorder : public PMArtNetScreenRenderer, ofBaseSoundInput{
    
public:
    PMArtNetRecorder(){};
    ~PMArtNetRecorder(){};
    
    bool setup(const char* machineIP);
    void update();
    void draw(int x, int y, int w, int h);
    
    void start();
    void stop();
    void addAudioBuffer(float *input, int bufferSize, int nChannels);
    void mousePressed(int x, int y, int button);
    void audioIn(float *input, int bufferSize, int nChannels);
    
private:
    ofxVideoRecorder vidRecorder;
    ofImage frame;
    ofSoundStream soundStream;
    PMBaseCustomButton recordButton, stopButton;
};
#endif /* PMArtNetRecorder_h */
