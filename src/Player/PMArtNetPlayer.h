//
//  PMArtNetPlayer.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#ifndef PMArtNetPlayer_h
#define PMArtNetPlayer_h

#include "ofMain.h"
#include "PMArtNetManager.h"

class PMArtNetPlayer{
    
public:
    PMArtNetPlayer(){};
    ~PMArtNetPlayer(){};
    
    bool setup(string videoFilename, const char* machineIP, const char* targetIP);
    void update();
    void draw(int x, int y, int w, int h);
    int getVideoFrameRate();
    
private:
    ofVideoPlayer videoPlayer;
    PMArtNetManager artnet;
};

#endif /* PMArtNetPlayer_h */
