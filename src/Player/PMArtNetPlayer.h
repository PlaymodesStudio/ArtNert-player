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
#include "PMVideoManager.h"

class PMArtNetPlayer{
    
public:
    PMArtNetPlayer(){};
    ~PMArtNetPlayer(){};
    
    bool setup(string videoFilename, const char* targetIP);
    void update();
    void draw(int x, int y, int w, int h);
    int getVideoFrameRate();
    
private:
    PMVideoManager video;
    PMArtNetManager artnet;
};

#endif /* PMArtNetPlayer_h */
