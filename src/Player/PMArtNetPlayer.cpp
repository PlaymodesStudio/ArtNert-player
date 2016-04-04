//
//  PMArtNetPlayer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 04/03/16.
//
//

#include "PMArtNetPlayer.h"


bool PMArtNetPlayer::setup(){
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
    
    artnet.setup(PM_ARTNET_PLAYER);
}

void PMArtNetPlayer::update(){
    if(videoPlayer.isLoaded()){
        videoPlayer.update();
        if(!videoPlayer.isPaused() && videoPlayer.isPlaying()){
            artnet.sendDmx(videoPlayer.getPixels());
            playHeader.setHeaderPosition(videoPlayer.getPosition());
        }
    }
    
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

void PMArtNetPlayer::loadFile(string file){
    fileName = file;
    videoPlayer.setPixelFormat(OF_PIXELS_RGB); //set pixel type to NATIVE, although it has to be always rgb
    videoPlayer.setLoopState(OF_LOOP_NORMAL);
    videoPlayer.load(file);
    auto universes = videoPlayer.getPixels().getHeight();
    buildNodesPanel(universes);
    playHeader.setDuration(videoPlayer.getTotalNumFrames());
    
    ofAddListener(playHeader.headerDragged, this, &PMArtNetPlayer::changePlayHead);
}

void PMArtNetPlayer::mousePressed(int x, int y, int button){
    if(fileSelectorCustom.isInside(x, y)){
        fileSelectorCustom.selectToOpen();
        loadFile(fileSelectorCustom.getFilePath());
    }
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
//    playHeader.dragged(x, y);
}