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
    
//    ofParameter<bool> paramiter1;
//    ofParameter<bool> paramiter2;
//    ipSelector.add(paramiter1.set("192.168.1.6", true));
//    ipSelector.add(paramiter2.set("192.168.1.9", false));
//    ipSelector.setName("IpChoose");
//    paramiter1 = false;
//    
//    //gui SETUP
//    gui.setup(); //most of the time you don't need a name
//    gui.add(ipSelector);
    buildOutputDevicesPanel();
}

void PMArtNetScreenRenderer::drawBasicLayout(){
    ofDrawBitmapString(ofGetFrameRate(), 20, ofGetHeight()-20);
    guiDevices.draw();
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