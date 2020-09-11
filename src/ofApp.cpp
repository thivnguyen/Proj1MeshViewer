#include "ofApp.h"
#include "Mesh.h"
#include "Triangle.h"
#include <fstream>
using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
    //cam.rotate(90, cam.getUpDir() );
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    drawAxis();
    
    vector<vec3> vertices;
    vertices.push_back(vec3(5,0,0)); //index 0
    vertices.push_back(vec3(-5,0,0)); //index 1
    vertices.push_back(vec3(0,-5,0)); //index 2
    vertices.push_back(vec3(0,5,0)); //index 3
    vertices.push_back(vec3(0,0,5)); //index 4
    
    vector<Triangle> triangles;
    triangles.push_back(Triangle(0,3,2));
    triangles.push_back(Triangle(3,1,2));
    triangles.push_back(Triangle(0,3,4));
    triangles.push_back(Triangle(3,1,4));
    triangles.push_back(Triangle(1,2,4));
    triangles.push_back(Triangle(0,4,2));
    
    Mesh mesh (vertices, triangles);

    mesh.draw();
    cam.end();
}

void ofApp::drawAxis(){
    //x
    ofSetColor(ofColor::red);
    ofDrawLine(vec3(-10.0,0,0), vec3(10.0,0,0));
    
    //y
    ofSetColor(ofColor::green);
    ofDrawLine(vec3(0,-10.0,0), vec3(0,10.0,0)); //draw vertical line from origin
    
    
    //z
    ofSetColor(ofColor::blue);
    ofDrawLine(vec3(0,0,-10.0), vec3(0,0,10.0)); //draw vertical line from origin
    
    ofSetColor(ofColor::white);
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
