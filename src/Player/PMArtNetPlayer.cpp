//
//  PMArtNetPlayer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetPlayer.h"


bool PMArtNetPlayer::setup(string videoFilename, const char* machineIP, const char* targetIP){
    setupBase();
    //buildOutputDevicesPanel();
    
    //header
    playHeader.setPosition(vidImageContainer.getX(), vidImageContainer.getBottom()+20);
    playHeader.setSize(vidImageContainer.getWidth(), 20);
    
    //playbutton
    playButton.setPosition(ofGetWidth()-300, ofGetHeight()-100);
    playButton.setSize(80, 80);
    playButton.setIconPredefined(PMButtonPlay);
    
    pauseButton.setPosition(ofGetWidth()-200, ofGetHeight()-100);
    pauseButton.setSize(80, 80);
    pauseButton.setIconPredefined(PMButtonPause);
    
    stopButton.setPosition(ofGetWidth()-100, ofGetHeight()-100);
    stopButton.setSize(80, 80);
    stopButton.setIconPredefined(PMButtonStop);
    
    
    videoPlayer.setPixelFormat(OF_PIXELS_RGB); //set pixel type to NATIVE, although it has to be always rgb
    videoPlayer.load(videoFilename);  //load Video
    auto universes = videoPlayer.getPixels().getHeight();
    buildNodesPanel(3);
    videoPlayer.setLoopState(OF_LOOP_NORMAL);
    
    playHeader.setDuration(videoPlayer.getTotalNumFrames());
    ofAddListener(playHeader.headerDragged, this, &PMArtNetPlayer::changePlayHead);
    
    artnet.setup(PM_ARTNET_PLAYER);
    artnet.setTargetIP(targetIP);
}

void PMArtNetPlayer::update(){
    videoPlayer.update();

    artnet.sendDmx(videoPlayer.getPixels());
    if(!videoPlayer.isPaused() && videoPlayer.isPlaying())
        playHeader.setHeaderPosition(videoPlayer.getPosition());
    
    //videoPlayer.setFrame(ofGetMouseX()/videoPlayer.getDuration());
}

void PMArtNetPlayer::draw(int x, int y, int w, int h){
    videoPlayer.draw(vidImageContainer);
    drawBasicLayout();
    playHeader.draw();
    pauseButton.draw();
    playButton.draw();
    stopButton.draw();
    
}

void PMArtNetPlayer::changePlayHead(int &position){
    videoPlayer.setFrame(position);
}


void PMArtNetPlayer::mousePressed(int x, int y, int button){
    if(fileSelectorCustom.isInside(x, y))
        fileSelectorCustom.selectToOpen();
    if(playHeader.dragged(x, y))
        videoPlayer.setPaused(true);
    if(playButton.isPressed(x, y))
        videoPlayer.play();
    if(pauseButton.isPressed(x, y)){
        if(videoPlayer.isPaused())
            videoPlayer.setPaused(false);
        else
            videoPlayer.setPaused(true);
    }
    if(stopButton.isPressed(x, y)){
        videoPlayer.stop();
        playHeader.setHeaderPosition(0);
    }
}

void PMArtNetPlayer::mouseReleased(int x, int y, int button){
    if(videoPlayer.isPaused() && videoPlayer.isPlaying()){
        videoPlayer.setPaused(false);
    }
}

void PMArtNetPlayer::mouseDragged(int x, int y, int button){
    playHeader.dragged(x, y);
}