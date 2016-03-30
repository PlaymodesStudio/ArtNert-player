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
#include "PMArtNetScreenRenderer.h"
#include "PMPlayHeader.h"

class PMArtNetPlayer : public PMArtNetScreenRenderer{
    
public:
    PMArtNetPlayer(){};
    ~PMArtNetPlayer(){};
    
    bool setup(string videoFilename, const char* machineIP, const char* targetIP);
    void update();
    void draw(int x, int y, int w, int h);
    
    void play(){videoPlayer.play();};
    void changePlayHead(float &position);
    void mousePressed(int x, int y, int button);

    
private:
    ofVideoPlayer videoPlayer;
    PMPlayHeader playHeader;
};

#endif /* PMArtNetPlayer_h */
