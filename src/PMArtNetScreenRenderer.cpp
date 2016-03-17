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
    
    buildOutputDevicesPanel();
    buildMachineIpPanel();
}

void PMArtNetScreenRenderer::drawBasicLayout(){
    ofDrawBitmapString(ofGetFrameRate(), 20, ofGetHeight()-20);
    guiDevices.draw();
    guiMachineIp.draw();
}

void PMArtNetScreenRenderer::buildInputDevicesPanel()
{
    vector<ofSoundDevice> devices = ofSoundStreamListDevices();
    string DEVICE_SETTINGS_FILENAME = "devicesettings.xml";
    
    guiDevices.setup("Device Selector", DEVICE_SETTINGS_FILENAME);
    guiDevices.setPosition(10, 10);
    
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

void PMArtNetScreenRenderer::buildOutputDevicesPanel(){
    vector<ofSoundDevice> devices = ofSoundStreamListDevices();
    
    string DEVICE_SETTINGS_FILENAME = "devicesettings.xml";
    
    guiDevices.setup("Device Selector", DEVICE_SETTINGS_FILENAME);
    guiDevices.setPosition(10, 10);
    
    for (int i=0; i<devices.size(); ++i)
    {
        if (devices[i].outputChannels < 2) continue;
        
        XBDeviceParams devParams(devices[i].deviceID, devices[i].name, devices[i].outputChannels);
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

void PMArtNetScreenRenderer::buildMachineIpPanel(){
    auto ifacesIps = artnet.getIfacesIps();
    
    string MACHINEIP_SETTINGS_FILENAME = "machineIPsettings.xml";
    guiMachineIp.setup("MACHINE IP", MACHINEIP_SETTINGS_FILENAME);
    guiMachineIp.setPosition(10, 10);
    guiMachineIp.setHeaderBackgroundColor(ofGetBackgroundColor());
    
    machineIps.setName("Select machine IP from list");

    for (auto iface : ifacesIps){
        ofParameter<bool> machineIp;
        machineIfacesIp.push_back(machineIp);
        //machineIps.add(machineIfacesIp.at(machineIfacesIp.size()-1).set("Interface: "+iface.first+"   ip: "+iface.second, false));
        machineIps.add(machineIfacesIp.at(machineIfacesIp.size()-1).set(iface.second, false));
    }
    ofAddListener(machineIps.parameterChangedE(),this,  &PMArtNetScreenRenderer::ipSelectorListener);
    guiMachineIp.add(machineIps);
    
    ofFile file(MACHINEIP_SETTINGS_FILENAME);
    if (file.exists()) file.remove();

    guiMachineIp.loadFromFile(MACHINEIP_SETTINGS_FILENAME);
    
    guiMachineIp.setSize(300 , 300);
    guiMachineIp.setWidthElements(300);
}

void PMArtNetScreenRenderer::ipSelectorListener(ofAbstractParameter &ip){
    if(ip.toString() == "1"){
        //artnet.setIp(ip.getName());
        for (int i = 0; i < machineIfacesIp.size() ; i++){
            if (machineIfacesIp[i].getName() != ip.getName())
                machineIfacesIp[i] = false;
        }
    }
    
}