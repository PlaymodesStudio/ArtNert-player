//
//  PMArtNetScreenRenderer.cpp
//  ArtNet-player
//
//  Created by Eduard Frigola on 11/03/16.
//
//

#include "PMArtNetScreenRenderer.h"


void PMArtNetScreenRenderer::setupBase(){
    ofAddListener(ofEvents().update, this, &PMArtNetScreenRenderer::update);
    
    vidImageContainer.set(0,0,ofGetWidth()/2, ofGetHeight()/2);
    ofAddListener(artnet.receivedNode, this, &PMArtNetScreenRenderer::fillNodeIps);
    buildMachineIpPanel();
    
    font.load("LucidaGrande.ttc", 20);
    //build fileLoader/Saver
    fileSelectorCustom.setPosition(400, vidImageContainer.height + 300);
    fileSelectorCustom.setSize(320, 40);
    fileSelectorCustom.setFont(font);
}

void PMArtNetScreenRenderer::update(ofEventArgs &a){
    guiMachineIp->update();
}

void PMArtNetScreenRenderer::drawBasicLayout(){
    ofPushStyle();
        ofNoFill();
        ofSetColor(0);
        ofSetLineWidth(2);
        ofDrawRectRounded(vidImageContainer, 2);
    ofPopStyle();
    ofDrawBitmapString(ofGetFrameRate(), 20, ofGetHeight()-20);
//    guiDevices.draw();
    guiMachineIp->draw();
//    guiNodes.draw();
    
    fileSelectorCustom.draw();
}

void PMArtNetScreenRenderer::buildInputDevicesPanel()
{
//    vector<ofSoundDevice> devices = ofSoundStreamListDevices();
//    string DEVICE_SETTINGS_FILENAME = "devicesettings.xml";
//    
//    guiDevices.setup("Input Device Selector", DEVICE_SETTINGS_FILENAME);
//    guiDevices.setPosition(10, vidImageContainer.height+10);
//    
//    for (int i=0; i<devices.size(); ++i)
//    {
//        if (devices[i].inputChannels < 2) continue;
//        
//        XBDeviceParams devParams(devices[i].deviceID, devices[i].name, devices[i].inputChannels);
//        guiDevices.add(devParams.getParams());
//        
//        deviceParams.push_back(devParams);
//    }
//    
//    ofFile file(DEVICE_SETTINGS_FILENAME);
//    if (file.exists()) file.remove();
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
    for (auto iface : ifacesIps) machineIps.push_back(iface.second);
    
    guiMachineIp = new ofxDatGuiDropdown("Select your Machine Ip", machineIps);
    guiMachineIp->setPosition(ofGetWidth()-310, ofGetHeight()-310);
    guiMachineIp->expand();
    guiMachineIp->onDropdownEvent(this, &PMArtNetScreenRenderer::ipSelectorListener);

}

void PMArtNetScreenRenderer::buildNodesPanel(int universes){
//    this->n_universes = universes;
//    
//    string NODES_SETTINGS_FILENAME = "nodesIPsettings.xml";
//    guiNodes.setup("MACHINE IP", NODES_SETTINGS_FILENAME);
//    guiNodes.setPosition(vidImageContainer.getRight()+10, vidImageContainer.getY()+50);
//    guiNodes.setHeaderBackgroundColor(ofGetBackgroundColor());
//    
//    guiNodes.setName("Select node");
//    
//    if(nodesIpsString.size() == 0){
//        for (int i = 0 ; i<n_universes ; i++){
//            ofParameterGroup node;
//            node.setName("Universe "+ofToString((i)));
//            nodes.push_back(node);
//            ofAddListener(nodes[nodes.size()-1].parameterChangedE(),this,  &PMArtNetScreenRenderer::nodeIpSelectorListener);
//            guiNodes.add(nodes.at(nodes.size()-1));
//        }
//    }else{
//        for (int i = 0; i<nodesIpsString.size(); i++) {
//            vector<ofParameter<bool>> nodeIp;
//            nodesIps.push_back(nodeIp);
//        }
//        for (int i = 0 ; i<n_universes ; i++){
//            ofParameterGroup node;
//            node.setName("Universe "+ofToString((i)));
//            for (int j = 0; j<nodesIpsString.size(); j++){
//                ofParameter<bool> tempIp;
//                nodesIps[j].push_back(tempIp);
//                node.add(nodesIps[j].at(i).set(nodesIpsString[j], false));
//            }
//            nodes.push_back(node);
//            ofAddListener(nodes[nodes.size()-1].parameterChangedE(),this,  &PMArtNetScreenRenderer::nodeIpSelectorListener);
//            guiNodes.add(nodes.at(nodes.size()-1));
//        }
//    }
//    
////    ofFile file(NODES_SETTINGS_FILENAME);
////    if (file.exists()) file.remove();
//    
//    //guiNodes.loadFromFile(NODES_SETTINGS_FILENAME);
//    
//    guiNodes.setSize(200 , 300);
//    guiNodes.setWidthElements(200);
}

void PMArtNetScreenRenderer::fillNodeIps(string &ip){
//    if(guiNodes.getName() == ""){//Gui Nodes is not yet created
//        nodesIpsString.push_back(ip);
//    }else{
//        vector<ofParameter<bool>> nodeIp;
//        nodesIps.push_back(nodeIp);
//        guiNodes.clear();
//        for (int i = 0 ; i<nodes.size() ; i++){
//            ofParameter<bool> tempIp;
//            nodesIps[nodesIps.size()-1].push_back(tempIp);
//            nodes[i].add(nodesIps[nodesIps.size()-1].at(i).set(ip, false));
//            guiNodes.add(nodes[i]);
//        }
//    }
}

void PMArtNetScreenRenderer::ipSelectorListener(ofxDatGuiDropdownEvent e){
    artnet.setMachineIP(machineIps[e.child]);
}


void PMArtNetScreenRenderer::nodeIpSelectorListener(ofAbstractParameter &nodeIp){
    if(nodeIp.toString() == "1"){
        string nodeClicked = nodeIp.getGroupHierarchyNames()[1];
        int universe = ofToInt(string(&nodeClicked.back()));
        cout<<universe<<"  "<<nodeIp.getName()<<endl;
        artnet.setTargetIP(nodeIp.getName(), universe);
        for (int i = 0 ; i < nodesIps.size() ; i++){
            if ( nodesIps[i][universe].getName() != nodeIp.getName())
                nodesIps[i][universe] = false;
        }
    }
}


