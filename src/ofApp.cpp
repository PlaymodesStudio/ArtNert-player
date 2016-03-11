#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
    
    isPlayer = true;
    
    if(isPlayer){
        if(ofGetTargetPlatform() == OF_TARGET_OSX)
            player.setup("artnettestProres.mov", "192.168.1.105", "192.168.1.112");
        else
            player.setup("artnettest.mov", "192.168.1.112", "192.168.1.105");
        player.play();
    }
    else{
        if(ofGetTargetPlatform() == OF_TARGET_OSX)
            recorder.setup("test.mov", "192.168.1.105");
        else
            recorder.setup("test.mov", "192.168.1.112");
    
        soundStream.setup(this, 0, 2, 48000, 256, 4);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(isPlayer)
        player.update();
    else
        recorder.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(isPlayer)
        player.draw(0, 0, ofGetWidth(), ofGetHeight());
    else
    recorder.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    ofDrawBitmapString(ofGetFrameRate(), 20, ofGetHeight()-20);
}

//--------------------------------------------------------------
void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    if (!isPlayer)
    recorder.addAudioBuffer(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(!isPlayer){
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
