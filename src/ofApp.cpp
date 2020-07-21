#include "ofApp.h"
#include <vector>
#include <graphics\ofPath.cpp>

std::vector<std::vector<float>> fields;
int res = 10;
int col, rows;
float increment = .1;
float zoff = 0;
//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	
	gui.add(zOffset.setup("Z OFFSET", .01f, 0, 2));
	gui.add(xyOffset.setup("X & Y OFFSET", 5, 0, 25));
	gui.add(resolution.setup("RESOLUTION", 10, 0, 50));
	gui.add(sizeOfCircle.setup("SIZE OF CIRCLES", 1, 0, 20));


	col = ofGetWindowWidth() / resolution;
	rows = ofGetWindowWidth() / resolution;
	fields.resize(rows, std::vector<float>(col));
	std::cout << col << "\t" << rows << std::endl;
	
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	float xoff = 0;
	float yoff = 0;
	for (int i = 0; i < rows; i++) {
		xoff += increment;
		for (int j = 0; j < col; j++) {
			fields[i][j] = ofSignedNoise(xoff * xyOffset, yoff * xyOffset, zoff);
			yoff += increment;
		}
	}
	zoff += zOffset;


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			ofFill();
			ofSetColor(fields[i][j] * 255);
			ofRectMode(OF_RECTMODE_CENTER);
			ofCircle(i * resolution, j * resolution, sizeOfCircle);
		}
	}

	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < col - 1; j++) {
			float x = i * resolution;
			float y = j * resolution;
			ofVec2f a(x + resolution * .5,	y);
			ofVec2f b(x + resolution,		y + resolution * .5);
			ofVec2f c(x + resolution * .5,	y + resolution);
			ofVec2f d(x,					y + resolution * .5);
			int state = getState(ceil(fields[i][j]), ceil(fields[i + 1][j]), ceil(fields[i + 1][j + 1]), ceil(fields[i][j + 1]));
			ofSetColor(255);
			//ofLine(a.x, a.y, b.x, b.y);
			switch (state)
			{
			case 1:
				drawLine(c, d);
				break;
			case 2:
				drawLine(b, c);
				break;
			case 3:
				drawLine(b, d);
				break;
			case 4:
				drawLine(a, b);
				break;
			case 5:
				drawLine(a, d);
				drawLine(b, c);
				break;
			case 6:
				drawLine(a, c);
				break;
			case 7:
				drawLine(a, d);
				break;
			case 8:
				drawLine(a, d);
				break;
			case 9:
				drawLine(a, c);
				break;
			case 10:
				drawLine(a, b);
				drawLine(c, d);
				break;
			case 11:
				drawLine(a, b);
				break;
			case 12:
				drawLine(b, d);
				break;
			case 13:
				drawLine(b, c);
				break;
			case 14:
				drawLine(c, d);
				break;
			}
		}
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

int ofApp::getState(int a, int b, int c, int d)
{
	return a * 8 + b * 4 + c * 2 + d * 1;
}

void ofApp::drawLine(ofVec2f v1, ofVec2f v2)
{
	ofLine(v1.x, v1.y, v2.x, v2.y);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
