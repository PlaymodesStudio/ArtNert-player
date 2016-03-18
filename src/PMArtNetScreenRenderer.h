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
    void buildNodesPanel(int n_universes);
    void fillNodeIps(string &ip);
    
    void ipSelectorListener(ofAbstractParameter &ip);
    void nodeIpSelectorListener(ofAbstractParameter &nodeIp){};
    
    ofRectangle vidImageContainer;
    string fileName;
    
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
    
    ofxButton               btnStartAnalysis;
    ofxLabel                lblStatus;
    
    PMArtNetManager artnet;

};

#endif /* PMArtNetScreenRenderer_h */
