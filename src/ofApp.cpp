#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
    state = STATE_SETUP;
    setupScreen.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

    switch(state){
        case STATE_SETUP:
            break;
        case STATE_PLAYER:
            player.update();
            break;
        case STATE_RECORDER:
            recorder.update();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch(state){
        case STATE_SETUP:
            setupScreen.draw();
            break;
        case STATE_PLAYER:
            player.draw(0, 0, ofGetWidth(), ofGetHeight());
            break;
        case STATE_RECORDER:
            recorder.draw(0, 0, ofGetWidth(), ofGetHeight());
            break;
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    if (state == STATE_RECORDER)
        recorder.addAudioBuffer(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void ofApp::changeToScene(appState _state){
    switch (_state) {
        case STATE_SETUP:
            break;
        case STATE_PLAYER:
            if(ofGetTargetPlatform() == OF_TARGET_OSX)
                player.setup("artnettestProres.mov", "192.168.1.105", "192.168.1.112");
            else
                player.setup("artnettest.mov", "192.168.1.112", "192.168.1.105");
            player.play();
            break;
        case STATE_RECORDER:
            if(ofGetTargetPlatform() == OF_TARGET_OSX)
                recorder.setup("test.mov", "192.168.1.105");
            else
                recorder.setup("test.mov", "192.168.1.112");
            
            soundStream.setup(this, 0, 2, 48000, 256, 4);
            break;
        default:
            break;
    }
    state = _state;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(state == STATE_RECORDER){
        if (key == 'r')
            recorder.start();
        else
            recorder.stop();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (state == STATE_SETUP) {
        auto toChange = setupScreen.checkPress(x, y);
        if(toChange != -1)
            changeToScene(appState(toChange));
    }
    switch (state) {
        case STATE_PLAYER:
            break;
        case STATE_RECORDER:
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
