#include "ofFood.h"


ofFood::ofFood() {
   // color.set(250, 0, 50);
	food.load("food.png");
    // set the first position of food randomly
    // otherwise food and snake have the same pos at (0,0) which leads to an error
    // in "snake's eat function > startcheck is increased w/o reason"
    pickLocation();
}

ofFood::~ofFood() {

}


void ofFood::pickLocation() {

	int celdasx = ofRandom(0, 7);
	int celdasy = ofRandom(0, 25);
	myPos.x = 95 + (celdasx * 180) + (15 * celdasx);
	myPos.y = 35 + (celdasy * 25) + (3 * celdasy);
}


void ofFood::drawFood() {
   // ofSetColor(color);
   // ofDrawRectangle(myPos.x,myPos.y, scl, scl);
	//food.draw(myPos.x, myPos.y, 81, 19);
	food.draw(myPos.x, myPos.y, 180, 25);
}

