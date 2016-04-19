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
#include "ofxDatGui.h"
#include "XBDeviceParams.h"
#include "PMArtNetManager.h"
#include "PMFileSelector.h"
#include "PMBaseCustomButton.h"

class PMArtNetScreenRenderer{
protected:
    void setupBase();
    void update(ofEventArgs &a);
    void drawBasicLayout();
    void buildInputDevicesPanel();
//    void buildOutputDevicesPanel();
    void buildMachineIpPanel();
    void buildNodesPanel(int n_universes);
    void fillNodeIps(string &ip);
    
    void ipSelectorListener(ofxDatGuiDropdownEvent e);
    void nodeIpSelectorListener(ofAbstractParameter &nodeIp);
    
    
    
    ofRectangle vidImageContainer;
    string fileName;
    
    ofTrueTypeFont font;
    
    // Audio device selector
//    ofxPanel                guiDevices;
    vector<XBDeviceParams>  deviceParams;
    
    //MachineIp selector
    vector<string>                  machineIps;
    ofxDatGuiDropdown*              guiMachineIp;
    
    //Node Selector
//    ofxPanel                    guiNodes;
    vector<ofParameterGroup>    nodes;
    vector<vector<ofParameter<bool>>>   nodesIps;
    vector<string>              nodesIpsString;// = {"192.168.1.105"};
    
    //File Selector
    PMFileSelector          fileSelectorCustom;
    
//    ofxButton               btnStartAnalysis;
//    ofxLabel                lblStatus;
    
    PMArtNetManager artnet;
    
    int n_universes;

};

#endif /* PMArtNetScreenRenderer_h */
