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
    ofxDatGui::setAssetPath("");
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
//    for(auto guiNode : guiNodes)
//        guiNode->update();
//    for(auto guiNodeUniverse : guiNodesUniverse)
//        guiNodeUniverse->update();
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
//    for(auto guiNode : guiNodes)
//        guiNode->draw();
//    for(auto guiNodeUniverse : guiNodesUniverse)
//        guiNodeUniverse->draw();
    
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

void PMArtNetScreenRenderer::buildMachineIpPanel(){
    auto ifacesIps = artnet.getIfacesIps();
    for (auto iface : ifacesIps) machineIps.push_back(iface.second);
    
    guiMachineIp = new ofxDatGuiDropdown("Select your Machine Ip", machineIps);
    guiMachineIp->setWidth(200);
    guiMachineIp->setPosition(ofGetWidth()-310, ofGetHeight()-310);
    guiMachineIp->expand();
    guiMachineIp->onDropdownEvent(this, &PMArtNetScreenRenderer::ipSelectorListener);

}

void PMArtNetScreenRenderer::buildNodesPanel(int universes){
    this->n_universes = universes;
    
    if(guiLabels == nullptr) guiLabels = new ofxDatGui();
    else guiLabels->clear();
    guiLabels->setPosition(vidImageContainer.getRight()+10, vidImageContainer.getTop());
    guiLabels->setWidth(30);
    
    if(guiNodes == nullptr) guiNodes = new ofxDatGui();
    else guiNodes->clear();
    guiNodes->setPosition(guiLabels->getPosition().x + guiLabels->getWidth()+5, guiLabels->getPosition().y);
    guiNodes->onDropdownEvent(this, &PMArtNetScreenRenderer::nodeIpSelectorListener);;
    guiNodes->setWidth(200);
    
    if(guiNodesSubNet == nullptr) guiNodesSubNet = new ofxDatGui();
    else guiNodesSubNet->clear();
    guiNodesSubNet->setPosition(guiNodes->getPosition().x + guiNodes->getWidth()+5, guiNodes->getHeight());
    guiNodesSubNet->onDropdownEvent(this, &::PMArtNetScreenRenderer::nodeSubnetSelectorListener);
    guiNodesSubNet->setWidth(150);
    
    if(guiNodesUniverse == nullptr) guiNodesUniverse = new ofxDatGui();
    else guiNodesUniverse->clear();
    guiNodesUniverse->setPosition(guiNodesSubNet->getPosition().x + guiNodesSubNet->getWidth()+5, guiNodesSubNet->getHeight());
    guiNodesUniverse->onDropdownEvent(this, &::PMArtNetScreenRenderer::nodeUniverseSelectorListener);
    guiNodesUniverse->setWidth(150);
    
    vector<string> universeSubnetNumbers;
    for (int i=0; i<16; i++) universeSubnetNumbers.push_back(ofToString(i));
    
    int posX = vidImageContainer.getRight()+10;
    int posY = vidImageContainer.getTop();
    for(int i=0 ; i<n_universes; i++){
        //Line label
        guiLabels->addLabel(ofToString(i));
        //guiNodes IP
        auto dropDownNode = guiNodes->addDropdown("Ip for line "+ofToString(i), nodesIpsString);
        //guiNodes SubNet
        auto dropDownSubNet = guiNodesSubNet->addDropdown("SubNet line "+ofToString(i), universeSubnetNumbers);
        //guiNodes Universes
        auto dropDownUniverse = guiNodesUniverse->addDropdown("Univ for line "+ofToString(i), universeSubnetNumbers);
    }
}

void PMArtNetScreenRenderer::fillNodeIps(string &ip){
    nodesIpsString.push_back(ip);
    if(guiNodes != nullptr){//Gui Nodes is created
        ofPoint guiPos = guiNodes->getPosition();
        guiNodes->clear();
        guiNodes->setWidth(200);
        for(int i=0 ; i<n_universes ; i++){
            auto dropDownNode = guiNodes->addDropdown("Ip for line "+ofToString(i), nodesIpsString);
        }
    }
}

void PMArtNetScreenRenderer::ipSelectorListener(ofxDatGuiDropdownEvent e){
    artnet.setMachineIP(machineIps[e.child]);
}


void PMArtNetScreenRenderer::nodeIpSelectorListener(ofxDatGuiDropdownEvent e){
    int line = ofToInt(&e.target->getName()[e.target->getName().length()-1]);
    artnet.setTargetIP(nodesIpsString[e.child], line);
}

void PMArtNetScreenRenderer::nodeSubnetSelectorListener(ofxDatGuiDropdownEvent e){
    cout<<"Selected line"<<endl;
    int line = ofToInt(&e.target->getName()[e.target->getName().length()-1]);
    artnet.setTargetSubNet(e.child, line);
}

void PMArtNetScreenRenderer::nodeUniverseSelectorListener(ofxDatGuiDropdownEvent e){
    int line = ofToInt(&e.target->getName()[e.target->getName().length()-1]);
    artnet.setTargetUniverse(e.child, line);
}


