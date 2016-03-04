//
//  PMVideoManager.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#ifndef PMVideoManager_h
#define PMVideoManager_h

#include "ofMain.h"

class PMVideoManager{
    
public:
    PMVideoManager(){};
    ~PMVideoManager(){};
    
    bool setup(string filename, ofLoopType loopType);
    void update();
    void draw(int x, int y, int width, int height);
    ofPixels getFramePixels();
    
private:
    ofVideoPlayer videoPlayer;
    
};

#endif /* PMVideoManager_h */
