//
// Created by Miquel Àngel Soler on 30/12/15.
//

#include "XBDeviceParams.h"

XBDeviceParams::XBDeviceParams(unsigned int _deviceID, string name, unsigned int numInChannels)
{
    deviceID = _deviceID;

    ofStringReplace(name, ":", "-");
    ofStringReplace(name, ",", "-");
    ofStringReplace(name, ".", "-");
    params.setName(name);

    params.add(enabled.set("Enabled", false));

    for (unsigned int i=0; i<numInChannels; ++i)
    {
        ofParameter<bool> channelEnabled;
        inputChannels.push_back(channelEnabled);
        params.add(inputChannels[i].set("Channel" + ofToString(i), false));
    }
}

vector<unsigned int> XBDeviceParams::getEnabledChannels()
{
    vector<unsigned int> result;

    for (unsigned int i=0; i<inputChannels.size(); ++i) {
        if (inputChannels[i].get())
            result.push_back(i);
    }

    return result;
}
