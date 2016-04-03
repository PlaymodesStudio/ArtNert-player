//
//  PMArtNetScreenRenderer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 11/03/16.
//
//

#include "PMArtNetScreenRenderer.h"


void PMArtNetScreenRenderer::setupBase(){
    vidImageContainer.set(0,0,ofGetWidth()/2, ofGetHeight()/2);
    ofAddListener(artnet.receivedNode, this, &PMArtNetScreenRenderer::fillNodeIps);
    buildMachineIpPanel();
    
    font.load("LucidaGrande.ttc", 20);
    //build fileLoader/Saver
    fileSelectorCustom.setPosition(400, vidImageContainer.height + 300);
    fileSelectorCustom.setSize(320, 40);
    fileSelectorCustom.setFont(font);
}

void PMArtNetScreenRenderer::drawBasicLayout(){
    ofPushStyle();
        ofNoFill();
        ofSetColor(0);
        ofSetLineWidth(2);
        ofDrawRectRounded(vidImageContainer, 2);
    ofPopStyle();
    ofDrawBitmapString(ofGetFrameRate(), 20, ofGetHeight()-20);
    guiDevices.draw();
    guiMachineIp.draw();
    guiNodes.draw();
    
    fileSelectorCustom.draw();
}

void PMArtNetScreenRenderer::buildInputDevicesPanel()
{
    vector<ofSoundDevice> devices = ofSoundStreamListDevices();
    string DEVICE_SETTINGS_FILENAME = "devicesettings.xml";
    
    guiDevices.setup("Input Device Selector", DEVICE_SETTINGS_FILENAME);
    guiDevices.setPosition(10, vidImageContainer.height+10);
    
    for (int i=0; i<devices.size(); ++i)
    {
        if (devices[i].inputChannels < 2) continue;
        
        XBDeviceParams devParams(devices[i].deviceID, devices[i].name, devices[i].inputChannels);
        guiDevices.add(devParams.getParams());
        
        deviceParams.push_back(devParams);
    }
    
    ofFile file(DEVICE_SETTINGS_FILENAME);
    if (file.exists()) file.remove();
    
    guiDevices.loadFromFile(DEVICE_SETTINGS_FILENAME);
    
    guiDevices.add(lblStatus.setup("Current Status", "off"));
    lblStatus.setBackgroundColor(ofColor::darkRed);
    guiDevices.add(btnStartAnalysis.setup("START"));
    
    //btnStartAnalysis.addListener(this, &CelloApp::startButtonPressed);
    
    lblStatus.setDefaultWidth(300);
    
    guiDevices.setSize(300 , 300);
    guiDevices.setWidthElements(300);
}

//void PMArtNetScreenRenderer::buildOutputDevicesPanel(){
//    vector<ofSoundDevice> devices = ofSoundStreamListDevices();
//    
//    string DEVICE_SETTINGS_FILENAME = "devicesettings.xml";
//    
//    guiDevices.setup("Output Device Selector", DEVICE_SETTINGS_FILENAME);
//    guiDevices.setPosition(10, vidImageContainer.height+10);
//    
//    for (int i=0; i<devices.size(); ++i)
//    {
//        if (devices[i].outputChannels < 2) continue;
//        
//        XBDeviceParams devParams(devices[i].deviceID, devices[i].name, devices[i].outputChannels);
//        guiDevices.add(devParams.getParams());
//        
//        deviceParams.push_back(devParams);
//    }
//    
//    //ofFile file(DEVICE_SETTINGS_FILENAME);
//    //if (file.exists()) file.remove();
//    
//    guiDevices.loadFromFile(DEVICE_SETTINGS_FILENAME);
//    
//    guiDevices.add(lblStatus.setup("Current Status", "off"));
//    lblStatus.setBackgroundColor(ofColor::darkRed);
//    guiDevices.add(btnStartAnalysis.setup("START"));
//    
//    //btnStartAnalysis.addListener(this, &CelloApp::startButtonPressed);
//    
//    lblStatus.setDefaultWidth(300);
//    
//    guiDevices.setSize(300 , 300);
//    guiDevices.setWidthElements(300);
//}

void PMArtNetScreenRenderer::buildMachineIpPanel(){
    auto ifacesIps = artnet.getIfacesIps();
    
    string MACHINEIP_SETTINGS_FILENAME = "machineIPsettings.xml";
    guiMachineIp.setup("MACHINE IP", MACHINEIP_SETTINGS_FILENAME);
    guiMachineIp.setPosition(ofGetWidth()-310, ofGetHeight()-310);
    guiMachineIp.setHeaderBackgroundColor(ofGetBackgroundColor());
    
    machineIps.setName("Select machine IP from list");

    for (auto iface : ifacesIps){
        ofParameter<bool> machineIp;
        machineIfacesIp.push_back(machineIp);
        machineIps.add(machineIfacesIp.at(machineIfacesIp.size()-1).set(iface.second, false));
    }
    ofAddListener(machineIps.parameterChangedE(),this,  &PMArtNetScreenRenderer::ipSelectorListener);
    guiMachineIp.add(machineIps);
    
    //ofFile file(MACHINEIP_SETTINGS_FILENAME);
    //if (file.exists()) file.remove();

    guiMachineIp.loadFromFile(MACHINEIP_SETTINGS_FILENAME);
    
    guiMachineIp.setSize(300 , 300);
    guiMachineIp.setWidthElements(300);
}

void PMArtNetScreenRenderer::buildNodesPanel(int n_universes){
    
    string NODES_SETTINGS_FILENAME = "machineIPsettings.xml";
    guiNodes.setup("MACHINE IP", NODES_SETTINGS_FILENAME);
    guiNodes.setPosition(vidImageContainer.getX()+vidImageContainer.getRight()+10, vidImageContainer.getY()+10);
    guiNodes.setHeaderBackgroundColor(ofGetBackgroundColor());
    
    guiNodes.setName("Select node for each universe");
    
    for (int i = 0 ; i<n_universes ; i++){
        ofParameterGroup node;
        node.setName("Universe "+ofToString((i)));
        nodes.push_back(node);
        ofAddListener(nodes[nodes.size()-1].parameterChangedE(),this,  &PMArtNetScreenRenderer::nodeIpSelectorListener);
        guiNodes.add(nodes.at(nodes.size()-1));
    }
    
    //ofFile file(MACHINEIP_SETTINGS_FILENAME);
    //if (file.exists()) file.remove();
    
    guiNodes.loadFromFile(NODES_SETTINGS_FILENAME);
    
    guiNodes.setSize(300 , vidImageContainer.getHeight());
    guiNodes.setWidthElements(300);
}

void PMArtNetScreenRenderer::fillNodeIps(string &ip){
    vector<ofParameter<bool>> nodeIp;
    nodesIps.push_back(nodeIp);
    guiNodes.clear();
    for (int i = 0 ; i<nodes.size() ; i++){
        ofParameter<bool> tempIp;
        nodesIps[nodesIps.size()-1].push_back(tempIp);
        nodes[i].add(nodesIps[nodesIps.size()-1].at(i).set(ip, false));
        guiNodes.add(nodes[i]);
    }
    
}

void PMArtNetScreenRenderer::ipSelectorListener(ofAbstractParameter &ip){
    if(ip.toString() == "1"){
        artnet.setMachineIP(ip.getName());
        for (int i = 0; i < machineIfacesIp.size() ; i++){
            if (machineIfacesIp[i].getName() != ip.getName())
                machineIfacesIp[i] = false;
        }
    }
}


void PMArtNetScreenRenderer::nodeIpSelectorListener(ofAbstractParameter &nodeIp){
    if(nodeIp.toString() == "1"){
        string nodeClicked = nodeIp.getGroupHierarchyNames()[1];
        int universe = ofToInt(string(&nodeClicked.back()));
        cout<<universe<<"  "<<nodeIp.getName()<<endl;
        //artnet.setTargetIP(nodeIp.getName());
        //artnet.setMachineIP(ip.getName());
        for (int i = 0 ; i < nodesIps.size() ; i++){
            if ( nodesIps[i][universe].getName() != nodeIp.getName())
                nodesIps[i][universe] = false;
        }
    }
}


