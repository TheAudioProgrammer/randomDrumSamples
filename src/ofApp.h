#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void audioOut (float * output, int bufferSize, int nChannels);
		
    
private:
    
    //samples
    ofxMaxiSample blip;
    ofxMaxiSample snare;
    ofxMaxiSample hi;
    
    //to combine sounds
    maxiMix myMix;
    double outputs[2];
    
    //variables to load sounds
    double theSnare;
    double theBlip;
    double theHi;
    
    //randomly generated numbers
    double ranGen;
    double ranGen2;
    double ranGen3;
    
    //clock for timing
    maxiClock theClock;
    
    
    
};
