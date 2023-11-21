#include "ofApp.h"

int num = 30000;

//--------------------------------------------------------------
void ofApp::setup(){
	particles.resize(num);
	for (int i = 0; i < num; i++) {
		particles[i] = (Particle{ ofVec2f(ofRandomWidth(), ofRandomHeight()), ofVec2f(ofRandom(0, 1), ofRandom(0, 1)), ofFloatColor(ofRandom(0, 1), ofRandom(0, 1), ofRandom(0, 1), ofRandom(0, 1))});
	}
	drawParticles.setupShaderFromFile(GL_COMPUTE_SHADER, "particle.glsl");
	drawParticles.linkProgram();

	buffer.allocate(particles, GL_DYNAMIC_DRAW);
	vbo.setVertexBuffer(buffer, 2, sizeof(Particle));
	vbo.setColorBuffer(buffer, sizeof(Particle), offsetof(Particle, col));
	buffer.bindBase(GL_SHADER_STORAGE_BUFFER, 0);


}

//--------------------------------------------------------------
void ofApp::update(){
	


	drawParticles.begin();
	drawParticles.dispatchCompute(num/1000, 1, 1);
	
	drawParticles.end();
	glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
	


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);
	glPointSize(1);
	vbo.draw(GL_POINTS, 0, particles.size());
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
}

