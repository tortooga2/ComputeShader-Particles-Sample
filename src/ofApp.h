#pragma once

#include "ofMain.h"

struct alignas(16) Particle {
	ofVec2f Pos;
	ofVec2f vel;
	ofFloatColor col;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		/*void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);*/

		ofBufferObject buffer;
		ofVbo vbo;

		ofShader drawParticles;

		vector<Particle> particles;

		
};





