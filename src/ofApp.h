#pragma once

#include "ofMain.h"
#include "PMArtNetSetup.h"
#include "PMArtNetPlayer.h"
#include "PMArtNetRecorder.h"

enum appState{
    STATE_SETUP,
    STATE_PLAYER,
    STATE_RECORDER
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void changeToScene(appState scene);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
private:
    PMArtNetSetup setupScreen;
    PMArtNetPlayer player;
    PMArtNetRecorder recorder;
    appState state;
    
};
