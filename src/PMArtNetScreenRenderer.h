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
#include "PMArtNetManager.h"

class PMArtNetScreenRenderer{
protected:
    void setupBase();
    void drawBasicLayout();
    void buildInputDevicesPanel();
    void buildOutputDevicesPanel();
    void buildMachineIpPanel();
    
    void ipSelectorListener(ofAbstractParameter &ip);
    
    ofRectangle vidImageContainer;
    string fileName;
    
    // Audio device selector
    ofxPanel                guiDevices, guiMachineIp;
    vector<XBDeviceParams>  deviceParams;
    ofParameterGroup        machineIps;
    vector<ofParameter<bool>> machineIfacesIp;
    ofxButton               btnStartAnalysis;
    ofxLabel                lblStatus;
    
    PMArtNetManager artnet;

};

#endif /* PMArtNetScreenRenderer_h */
