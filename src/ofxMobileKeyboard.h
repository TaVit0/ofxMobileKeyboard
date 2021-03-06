/*
 * ofxMobileKeyboard.h
 *
 *  Created on: 13/03/2015
 *      Author: Enric Marco -- Relabtive
 */

#pragma once

#ifndef __ofxMobileKeyboard__
#define __ofxMobileKeyboard__

#include "ofMain.h"

#ifdef TARGET_ANDROID
	#include "ofxAndroid.h"
	#include <jni.h>
#endif
#ifdef TARGET_OF_IOS
    #include "ofxiOS.h"
    #include "ofxiOSExtras.h"
#endif

class ofxMobileKeyboard {


private:


#ifdef TARGET_ANDROID
	void setupJNI();
	void setHint();

    const char *pathName;
    const char *hint;
	const char *prefix, *sufix;
    int posXint, posYint, widthint, heightint;

	jclass javaClass;
	jclass localClass;
	jstring s;
	jstring hintString;
	jmethodID javaReturnMethod;
	jmethodID javaReturnMethodAux;
	jobject javaObject;

#endif

#ifdef TARGET_OF_IOS
    ofxiOSKeyboard * keyboard;
#endif


	float posX, posY, width, height;

	string str;

	bool isActive;


public:


#ifdef TARGET_ANDROID

	void setup(const char * projectName, float x, float y, float w, float h, const char * hint);
	string recieveKeyboard();
	void showKeyboard();
	void hideKeyboard();
	bool isKeyboardActive();

#endif



#ifdef TARGET_OF_IOS

    void setup(float x, float y, float w, float h){

        posX = x;
        posY = y;
        width = w;
        height = h;

        isActive = false;
        str = "";

        keyboard = new ofxiOSKeyboard(posX, posY, width, height);

        keyboard->setPosition(posX, posY);
        keyboard->setBgColor(255,255,255,255);
        keyboard->setFontColor(0,0,0,255);
        keyboard->setFontSize(height-5);
        keyboard->setPlaceholder("Type your message here");

    }

    void setup(string hintString, float x, float y, float w, float h){

        posX = x;
        posY = y;
        width = w;
        height = h;

        isActive = false;
        str = "";

        keyboard = new ofxiOSKeyboard(posX, posY, width, height);

        keyboard->setPosition(posX, posY);
        keyboard->setBgColor(255,255,255,255);
        keyboard->setFontColor(0,0,0,255);
        keyboard->setFontSize(height-5);
        keyboard->setPlaceholder(hintString);

    }

    string recieveKeyboard(){
        str = keyboard->getLabelText();

        return str;
    }

    void showKeyboard(){
        isActive = true;
        keyboard->openKeyboard();
        keyboard->setVisible(true);

    };
    void hideKeyboard(){
        isActive = false;
        keyboard->setVisible(false);
    };

    bool isKeyboardActive(){
        return isActive;
    };

    void setBackgroundColor(int r, int g, int b, int a){
        keyboard->setBgColor(r,g,b,a);
    }

    void setFontColor(int r, int g, int b, int a){
        keyboard->setFontColor(r,g,b,a);
    }

#endif


};

#endif /* defined(__ofxMobileKeyboard__) */

