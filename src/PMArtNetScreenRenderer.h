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
#include "PMTextContainer.h"
#include "PMColorContainer.h"
#include "PMFileSelector.h"
#include "PMBaseCustomButton.h"

class PMArtNetScreenRenderer{
protected:
    void setupBase();
    void drawBasicLayout();
    void buildInputDevicesPanel();
//    void buildOutputDevicesPanel();
    void buildMachineIpPanel();
    void buildNodesPanel(int n_universes);
    void fillNodeIps(string &ip);
    
    void ipSelectorListener(ofAbstractParameter &ip);
    void nodeIpSelectorListener(ofAbstractParameter &nodeIp);
    
    
    
    ofRectangle vidImageContainer;
    string fileName;
    
    ofTrueTypeFont font;
    
    // Audio device selector
    ofxPanel                guiDevices;
    vector<XBDeviceParams>  deviceParams;
    
    //MachineIp selector
    ofxPanel                guiMachineIp;
    ofParameterGroup        machineIps;
    vector<ofParameter<bool>>  machineIfacesIp;
    
    //Node Selector
    ofxPanel                    guiNodes;
    vector<ofParameterGroup>    nodes;
    vector<vector<ofParameter<bool>>>   nodesIps;
    vector<string>              nodesIpsString;
    
    //File Selector
    PMFileSelector          fileSelectorCustom;
    
    ofxButton               btnStartAnalysis;
    ofxLabel                lblStatus;
    
    PMArtNetManager artnet;
    
    int n_universes;

};

#endif /* PMArtNetScreenRenderer_h */
