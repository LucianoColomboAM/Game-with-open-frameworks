#include "ofSnake.h"



ofSnake::ofSnake() {
	Snake.load("snake.png");
	
	//color.set(255);


}

ofSnake::~ofSnake() {

}

void ofSnake::updateSnake() {

    

}


void ofSnake::drawSnake() {
	myPos.x = myPos.x + xSpeed*0.5;
	myPos.y = myPos.y + ySpeed*0.85;

	//min-max range maped to canvas
	myPos.x = ofClamp(myPos.x, 0, ofGetWidth() - scl);
	myPos.y = ofClamp(myPos.y, 0, ofGetHeight() - scl);

    ofSetColor(color);
	Snake.draw(myPos.x, myPos.y, 180, 25);
    //ofDrawRectangle(myPos.x, myPos.y, scl, scl);
    
}


void ofSnake::setDir(int x, int y) {
    xSpeed = x;
    ySpeed = y;
}



bool ofSnake::eat(ofVec2f foodPos) {

    if (myPos.distance(foodPos) < 50) {
        return true;
    }

    return false;

}
