# ArtNet-player

Tested on of 0.9.0 and 0.9.2 on osX 10.11.3 and on RPi2 with Raspbian Jessie and of_linux_armv6

## Dependenvies
* [ofxVideoRecorder] (https://github.com/timscaffidi/ofxVideoRecorder)
* [ofxArtNet (PlaymodesStudio fork)] (https://github.com/PlaymodesStudio/ofxArtNet)

## ffmpeg
You need ffmpeg installed in your computer, at least in this version.
For raspberry you have to compile it, follow this instructions http://www.poison.ch/boards/ffmpeg.html
You only have to install dependencies (the ones with sudo apt-get install not the ones that you have to compile) becouse in this app we use a codec that is very simple and does not need all those libs.
For this reason when compiling you have to change the ./configure line to:
./configure --arch=armel --target-os=linux --enable-gpl
