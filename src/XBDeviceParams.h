//
// Created by Miquel Àngel Soler on 30/12/15.
//

#ifndef PEDRERAAUDIOANALYZERSENDER_XBDEVICEPARAMS_H
#define PEDRERAAUDIOANALYZERSENDER_XBDEVICEPARAMS_H

#include "ofMain.h"

class XBDeviceParams
{
public:

    XBDeviceParams(unsigned int deviceID, string name, unsigned int numInChannels);

    const ofParameterGroup &getParams() const   { return params; }
    unsigned int getDeviceID()                  { return deviceID; }
    vector<unsigned int> getEnabledChannels();
    bool getIsEnabled()                         { return enabled; }

    ofParameterGroup params;

    ofParameter<bool> enabled;
    vector<ofParameter<bool>> inputChannels;

    unsigned int deviceID;
};

#endif //PEDRERAAUDIOANALYZERSENDER_XBDEVICEPARAMS_H
