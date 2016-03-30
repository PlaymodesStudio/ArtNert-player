//
//  PMPlayHeader.h
//  ArtNet-player
//
//  Created by Eduard Frigola on 29/03/16.
//
//

#ifndef PMPlayHeader_h
#define PMPlayHeader_h

#include "ofMain.h"

class PMPlayHeader{
public:
    PMPlayHeader();
    ~PMPlayHeader(){};
    
    void draw();
    
    bool dragged(int x, int y);
    
    void setPosition(int x, int y){rectangle.setPosition(x, y);};
    void setSize(int width, int height){
        rectangle.setSize(width, height);
        header.setHeight(height);
    };
    void setDuration(float _duration){duration = _duration;};
    void setHeaderPosition(float position){headerPos = position;};

    ofEvent<float> headerDragged;
    
private:
    ofRectangle rectangle;
    ofRectangle header;
    float headerPos, duration;
};

#endif /* PMPlayHeader_h */
