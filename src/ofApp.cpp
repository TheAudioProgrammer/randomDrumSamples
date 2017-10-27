#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //load sounds...only takes 16 bit mono wav
    blip.load("/Users/djatwar/Desktop/blip.wav");
    snare.load("/Users/djatwar/Desktop/snare.wav");
    hi.load("/Users/djatwar/Desktop/hi.wav");
    
    //clock & timing settings
    theClock.setTicksPerBeat(8);
    theClock.setTempo(100);
    
    
    //turn on soundcard....must be at the end of setup
    ofSoundStreamSetup(2, 0, 44100, 512, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //generate some random numbers
    ranGen = ofRandom (0.2f, 4.0f);
    ranGen2 = ofRandom (0.2f, 5.0f);
    ranGen3 = ofRandom (0.2f, 5.0f);

}

//--------------------------------------------------------------
void ofApp::audioOut (float * output, int bufferSize, int nChannels)
{
    
    
    
    
    
    
    for (int sample = 0; sample < bufferSize; sample++)
    {
        //initialize clock
        theClock.ticker();
        
        
        //set random times for various samples to trigger
        if (theClock.tick && ofRandom(0.0f, 1.0f) > 0.1f && theClock.playHead % 16 == 2)
        {
            snare.trigger();
        }
        
        if (theClock.tick && ofRandom(0.0f, 1.0f) > 0.3f && theClock.playHead % 8 == 0)
        {
             blip.trigger();
        }
        
        if (theClock.tick && ofRandom (0.0f, 1.0f) > 0.6 && theClock.playHead % 2 == 0)
        {
            hi.trigger();
        }
        
        
        
        
        //play at random speeds
        theHi = hi.playOnce(ranGen) * ofRandom (0.2f, 0.6f);
        theBlip = blip.playOnce(ranGen2) * ofRandom (0.4f, 0.8f);
        theSnare = snare.playOnce(ranGen3) * ofRandom (0.4f, 0.8f);
        
        //add them all together
        myMix.stereo(theSnare + theHi + theBlip, outputs , 0.5);
        
        //output to speakers
        output [sample * nChannels] = outputs[0];
        output [sample * nChannels + 1] = outputs[1];
        
        
    }
    
    
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
