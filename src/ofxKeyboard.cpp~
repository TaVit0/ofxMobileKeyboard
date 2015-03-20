/*
 * ofxMobileKeyboard.cpp
 *
 *  Created on: 13/03/2015
 *      Author: Enric Marco -- Relabtive
 */

#include "ofMain.h"

#ifdef TARGET_OF_IOS

#endif

#ifdef TARGET_ANDROID

#include "ofxMobileKeyboard.h"

#endif

#ifdef TARGET_ANDROID

//--------------------------------------------------------------
void ofxMobileKeyboard :: setup (const char * _projectName, float _x, float _y, float _w, float _h, const char * _hint){

	posX = _x;
	posY = _y;
	width = _w;
	height = _h;

	pathName = _projectName;
	prefix = "cc/openframeworks/";
	sufix =  "/OFActivity";

	isActive = false;
	str = "";

	hint = _hint;

	posXint = posX;
	posYint = posY;
	widthint = width;
	heightint = height;


	setupJNI();

}

//---------------------------------------------------------------
void ofxMobileKeyboard :: setupJNI (){

	JNIEnv *env = ofGetJNIEnv();

	char result[500];

	strcpy(result,prefix);
	strcat(result,pathName);
	strcat(result,sufix);

	localClass = env->FindClass(result);

    //get OFActivity class from java
    javaClass = (jclass) env->NewGlobalRef(localClass);
    if (!javaClass) {
        ofLog() << "javaClass NOT found!" << endl;
    }else if(javaClass){
        ofLog() << "javaClass found!" << endl;
    }

    //get OFActiviy object from java
    javaObject = ofGetOFActivityObject();
    javaObject = (jobject) env->NewGlobalRef(javaObject);
    if (!javaObject) {
        ofLog() << "javaObject NOT created!" << endl;
    }else if(javaObject) {
        ofLog() << "javaObject created!" << endl;
    }

}

//----------------------------------------------------------------
string ofxMobileKeyboard :: recieveKeyboard (){

	JNIEnv *env = ofGetJNIEnv();

	javaReturnMethod = env->GetMethodID(javaClass,"recieveKeyboard","()Ljava/lang/String;");

	if(!javaReturnMethod){
		ofLog() << "recieveKeyboard Method NOT found!" << endl;
	}else if(javaReturnMethod){
		//ofLog() << "Recieve Keyboard String: "<< str << endl;
	}

	 s = (jstring)  env->CallObjectMethod(javaObject, javaReturnMethod);
	// convert the Java String to use it in OF
	str = env->GetStringUTFChars(s, 0);


	return str;
}
//----------------------------------------------------------------

void ofxMobileKeyboard :: setHint(){

	JNIEnv *env = ofGetJNIEnv();

	char result[500];

	strcpy(result,hint);

	jstring name = env->NewStringUTF(result);

	javaReturnMethod = env->GetMethodID(javaClass,"setHint","(Ljava/lang/String;)V");
	if(!javaReturnMethod){
		ofLog() << "setHint Method NOT found!" << endl;
	}else if(javaReturnMethod){
		ofLog() << "setHint Method found!" << endl;
	}

	env->CallVoidMethod(javaObject, javaReturnMethod, name);
	env->DeleteLocalRef(name);

}


//-----------------------------------------------------------------
void ofxMobileKeyboard :: showKeyboard(){

	isActive = true;



	setHint();

	JNIEnv *env = ofGetJNIEnv();

	javaReturnMethod = env->GetMethodID(javaClass,"showKeyboard","(IIII)V");
	if(!javaReturnMethod){
		ofLog() << "showKeyboard Method NOT found!" << endl;
	}else if(javaReturnMethod){
		ofLog() << "showKeyboard Method found!" << endl;
	}

	env->CallVoidMethod(javaObject, javaReturnMethod, posXint, posYint, widthint, heightint );


}

//-------------------------------------------------------------------
void ofxMobileKeyboard :: hideKeyboard(){

	isActive = false;



	JNIEnv *env = ofGetJNIEnv();

	 javaReturnMethod = env->GetMethodID(javaClass,"hideKeyboard","()V");
	if(!javaReturnMethod){
		ofLog() << "hideKeyboard Method NOT found!" << endl;
	}else if(javaReturnMethod){
		ofLog() << "hideKeyboard Method found!" << endl;
	}

	env->CallVoidMethod(javaObject, javaReturnMethod);



}

//---------------------------------------------------------------------
bool ofxMobileKeyboard :: isKeyboardActive(){

	return isActive;

}

#endif


