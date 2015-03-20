#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    
    keyboard.setup("Type text here", 0, 200, ofGetWidth(), 50);
    keyboard.setBackgroundColor(255, 255, 255, 90);
    keyboard.setFontColor(0, 0, 0, 255);
    
    keyboard.showKeyboard();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(keyboard.isKeyboardActive()==true){
        
        recievedString = keyboard.recieveKeyboard();
        
        ofLog() << "string recived: " << recievedString << endl;
        
    }
    
    
    
	
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

    if (keyboard.isKeyboardActive()==true) {
        keyboard.hideKeyboard();
    } else {
        keyboard.showKeyboard();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
