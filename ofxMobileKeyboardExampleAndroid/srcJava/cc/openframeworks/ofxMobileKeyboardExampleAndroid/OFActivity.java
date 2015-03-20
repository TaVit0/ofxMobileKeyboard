package cc.openframeworks.ofxMobileKeyboardExampleAndroid;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.RelativeLayout;
import cc.openframeworks.OFAndroid;
import cc.openframeworks.ofxMobileKeyboardExampleAndroid.R;


public class OFActivity extends cc.openframeworks.OFActivity{
	
	//-----------------------------------keyboard
	EditText textBox;
	int marginX, marginY, margingWidth, marginHeight;
	String hintLabel;
	//-----------------------------------keyboard
	

	@Override
    public void onCreate(Bundle savedInstanceState)
    { 
        super.onCreate(savedInstanceState);
        String packageName = getPackageName();

        setContentView(R.layout.main_layout);
        
        ofApp = new OFAndroid(packageName,this);
    }
	
	@SuppressLint("MissingSuperCall")
	@Override
	public void onDetachedFromWindow() {
	}
	
    @Override
    protected void onPause() {
        super.onPause();
        ofApp.pause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        ofApp.resume();
    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
	if (OFAndroid.keyDown(keyCode, event)) {
	    return true;
	} else {
	    return super.onKeyDown(keyCode, event);
	}
    }
    
    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
	if (OFAndroid.keyUp(keyCode, event)) {
	    return true;
	} else {
	    return super.onKeyUp(keyCode, event);
	}
    }


	OFAndroid ofApp;
    

	
//-------------------------------------------------------------------- KEYBOARD METHODS  -----------------------------------------------------//
	
	
  	public String recieveKeyboard(){
  		
  		textBox = (EditText)findViewById(R.id.edittext1);	
  		String text = textBox.getText().toString();
  		
  		return text;
  		
  	}
  	
  	public void setHint(String hintString){
  		
  		hintLabel = hintString;
  		
  		Log.v("OF KEYBOARD", ".........HINT LABEL: " + hintLabel);
  	}
  	
  	
  	
  	public void showKeyboard(int x, int y, int width, int height){
  		
  		marginX = x;
  		marginY = y;
  		margingWidth = width;
  		marginHeight = height;
  		
  		
  		runOnUiThread(new Runnable() {
  		     @Override
  		     public void run() {

  		    	Log.v("OF KEYBOARD", "SHOW TEXTBOX AND KEYBOARD..................... ");
  		    	
  		    	textBox = (EditText)findViewById(R.id.edittext1);
  		    	
  		    	textBox.setHint(hintLabel);
  		 		  		 		
  		 		RelativeLayout.LayoutParams extraLayoutParams = new  RelativeLayout.LayoutParams(margingWidth, marginHeight);
  		 		
  		 		extraLayoutParams.setMargins(marginX, marginY, 0, 0);
  		 		
  		 		textBox.setLayoutParams(extraLayoutParams);
  		 		
  		 		textBox.setVisibility(View.VISIBLE);
  		 		textBox.bringToFront();
  		 		textBox.setEnabled(true);

  		    }
  		});
  		 		
  	}
  	
  	
  	public void hideKeyboard(){
  	
  		runOnUiThread(new Runnable() {
  		     @Override
  		     public void run() {

  		    	Log.v("OF KEYBOARD", "HIDE TEXTBOX AND KEYBOARD..................... ");
  		 		
  		    	textBox = (EditText)findViewById(R.id.edittext1);
  		 		
  		    	textBox.setVisibility(View.INVISIBLE);
  		    	textBox.setEnabled(false);

  		    }
  		});

  	}
    
    
    //----------------------------------------------------------------END KEYBOARD METHODS ----------------------------------------------------//
	
    // Menus
    // http://developer.android.com/guide/topics/ui/menus.html
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
    	// Create settings menu options from here, one by one or infalting an xml
        return super.onCreateOptionsMenu(menu);
    }
    
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
    	// This passes the menu option string to OF
    	// you can add additional behavior from java modifying this method
    	// but keep the call to OFAndroid so OF is notified of menu events
    	if(OFAndroid.menuItemSelected(item.getItemId())){
    		
    		return true;
    	}
    	return super.onOptionsItemSelected(item);
    }
    

    @Override
    public boolean onPrepareOptionsMenu (Menu menu){
    	// This method is called every time the menu is opened
    	//  you can add or remove menu options from here
    	return  super.onPrepareOptionsMenu(menu);
    }
	
}



