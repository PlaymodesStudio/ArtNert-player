//
//  PMArtNetScreenRenderer.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 11/03/16.
//
//

#ifndef PMArtNetScreenRenderer_h
#define PMArtNetScreenRenderer_h

#include "ofMain.h"
#include "ofxGui.h"
#include "XBDeviceParams.h"

class PMArtNetScreenRenderer{
protected:
    void setupBase();
    void drawBasicLayout();
    void buildInputDevicesPanel();
    void buildOutputDevicesPanel();
    
    ofRectangle vidImageContainer;
    string fileName;
    
    // Audio device selector
    ofxPanel                guiDevices;
    vector<XBDeviceParams>  deviceParams;
    ofxButton               btnStartAnalysis;
    ofxLabel                lblStatus;

};

#endif /* PMArtNetScreenRenderer_h */
