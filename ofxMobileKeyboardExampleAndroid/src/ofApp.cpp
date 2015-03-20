#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	textBoxWidth = 720;
	textBoxHeight = 130;
	/*
	 * @param projectName, the project name needed for JNI bridge setup
	 * @param x, the textBox x position
	 * @param y, the textBox y position
	 * @param w, the textBox width
	 * @param h, the textBox height
	 * @param hint, the textBox hint text
	 */
	keyboard.setup("ofxMobileKeyboardExampleAndroid", (ofGetWidth()/2)-(textBoxWidth/2), (ofGetHeight()/2)-(textBoxHeight/2), textBoxWidth, textBoxHeight, "Type text here");

	keyboard.showKeyboard();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


	if(keyboard.isKeyboardActive()==true){

		keyboardText = keyboard.recieveKeyboard();

		ofLog() << "Recieve Keyboard String: "<< keyboardText << endl;

	}

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

	if(keyboard.isKeyboardActive()==true){
		keyboard.hideKeyboard();
	}else if(keyboard.isKeyboardActive()==false){
		keyboard.showKeyboard();
	}

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
