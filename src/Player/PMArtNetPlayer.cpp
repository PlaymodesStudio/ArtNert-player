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
    playButton.setPosition(ofGetWidth()-100, ofGetHeight()-100);
    playButton.setSize(80, 80);
    playButton.setIconPredefined(PMButtonPlay);
    
    
    videoPlayer.setPixelFormat(OF_PIXELS_RGB); //set pixel type to NATIVE, although it has to be always rgb
    videoPlayer.load(videoFilename);  //load Video
    auto universes = videoPlayer.getPixels().getHeight();
    buildNodesPanel(3);
    videoPlayer.setLoopState(OF_LOOP_NORMAL);
    
    playHeader.setDuration(videoPlayer.getTotalNumFrames());
    ofAddListener(playHeader.headerDragged, this, &PMArtNetPlayer::changePlayHead);
    
    artnet.setup(PM_ARTNET_PLAYER);
    artnet.setTargetIP(targetIP);
//    artnet.start();
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
    playButton.draw();
}

void PMArtNetPlayer::changePlayHead(int &position){
    videoPlayer.setFrame(position);
}


void PMArtNetPlayer::mousePressed(int x, int y, int button){
    if(fileSelectorCustom.isInside(x, y))
        fileSelectorCustom.selectToOpen();
    if(playHeader.dragged(x, y))
        videoPlayer.setPaused(true);
}

void PMArtNetPlayer::mouseReleased(int x, int y, int button){
    if(videoPlayer.isPaused() && videoPlayer.isPlaying()){
        videoPlayer.setPaused(false);
    }
}

void PMArtNetPlayer::mouseDragged(int x, int y, int button){
    playHeader.dragged(x, y);
}