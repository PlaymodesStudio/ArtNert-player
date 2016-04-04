#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableAntiAliasing();
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
void ofApp::changeToScene(appState _state){
    switch (_state) {
        case STATE_SETUP:
            break;
        case STATE_PLAYER:
            player.setup();
            break;
        case STATE_RECORDER:
            if(ofGetTargetPlatform() == OF_TARGET_OSX)
                recorder.setup("192.168.1.105");
            else
                recorder.setup("192.168.1.112");
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
    switch (state) {
        case STATE_SETUP:
        {
            //            auto toChange = setupScreen.checkPress(x, y);
            //            if(toChange != -1)
            //                changeToScene(appState(toChange));
            //            break;
        }
        case STATE_PLAYER:
            player.mouseDragged(x, y, button);
            break;
        case STATE_RECORDER:
            //recorder.mousePressed(x, y, button);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    switch (state) {
        case STATE_SETUP:
        {
            auto toChange = setupScreen.checkPress(x, y);
            if(toChange != -1)
                changeToScene(appState(toChange));
            break;
        }
        case STATE_PLAYER:
            player.mousePressed(x, y, button);
            break;
        case STATE_RECORDER:
            recorder.mousePressed(x, y, button);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    switch (state) {
        case STATE_SETUP:
        {
//            auto toChange = setupScreen.checkPress(x, y);
//            if(toChange != -1)
//                changeToScene(appState(toChange));
//            break;
        }
        case STATE_PLAYER:
            player.mouseReleased(x, y, button);
            break;
        case STATE_RECORDER:
            //recorder.mousePressed(x, y, button);
            break;
        default:
            break;
    }

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
