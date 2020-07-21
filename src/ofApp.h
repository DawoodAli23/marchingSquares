#pragma once

#include "ofMain.h"
#include "ofPath.h"
#include "ofxGui.h"
#include<math.h>
#include <vector>



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

		int getState(int a, int b, int c, int d);
		void drawLine(ofVec2f v1, ofVec2f v2);
		
		ofxPanel gui;
		ofxFloatSlider zOffset;
		ofxFloatSlider xyOffset;
		ofxIntSlider resolution;
		ofxIntSlider sizeOfCircle;
};
