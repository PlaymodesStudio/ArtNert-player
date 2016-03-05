#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    if(ofGetTargetPlatform() == OF_TARGET_OSX)
        player.setup("artnettestProres.mov", "192.168.1.105", "192.168.1.112");
    else
        player.setup("artnettest.mov", "192.168.1.112", "192.168.1.105");
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
