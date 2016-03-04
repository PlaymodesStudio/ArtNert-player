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
    
    void setup(string filename);
    ofPixels getFrame();
    
    
private:
    ofVideoPlayer videoPlayer;
    
    
};

#endif /* PMVideoManager_h */
