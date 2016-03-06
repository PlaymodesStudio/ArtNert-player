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
#include "ofxVideoRecorder.h"

enum pmVideoFunction {
    PM_VIDEO_RECORDER,
    PM_VIDEO_PLAYER
};

class PMVideoManager{
    
public:
    PMVideoManager(){};
    ~PMVideoManager(){};
    
    bool setup(pmVideoFunction _function, string filename, ofLoopType loopType);
    void start(){videoPlayer.play();};
    void update();
    void draw(int x, int y, int width, int height);
    ofPixels& getFramePixels();
    
private:
    ofVideoPlayer videoPlayer;
    ofxVideoRecorder videoRecorder;
    
};

#endif /* PMVideoManager_h */
