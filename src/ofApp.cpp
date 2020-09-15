#include "ofApp.h"
#include "MyMesh.h"
#include "Triangle.h"
#include <fstream>
using namespace glm;
using namespace std;
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
    
//    vector<vec3> vertices;
//    vertices.push_back(vec3(5,0,0)); //index 0
//    vertices.push_back(vec3(-5,0,0)); //index 1
//    vertices.push_back(vec3(0,-5,0)); //index 2
//    vertices.push_back(vec3(0,5,0)); //index 3
//    vertices.push_back(vec3(0,0,5)); //index 4
    
//    vector<Triangle> triangles;
//    triangles.push_back(Triangle(0,3,2));
//    triangles.push_back(Triangle(3,1,2));
//    triangles.push_back(Triangle(0,3,4));
//    triangles.push_back(Triangle(3,1,4));
//    triangles.push_back(Triangle(1,2,4));
//    triangles.push_back(Triangle(0,4,2));
    createdMesh.testMesh();
    createdMesh.draw();
    cam.end();
}

//draw the x, y, z axis
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
    cout << "Please drag .obj file into OF application!" <<endl;
    fstream fin;

    string path = dragInfo.files[0];
    
    //open file
    fin.open(path); //enter file path

         if (fin.fail()) {
             cout << "Failed to open OBJ file" << endl;
         } else {
             //read until end of file
             while (!fin.eof()) {
                 string line;
                 getline(fin, line); //read the line
                 int index = 0; //index in string
                 string word = "";

                 //find out if it is a vertice or face
                 while (line[index] != ' ' && line[index] != '/0'){
                     word += line[index];
                     index++;
                 }

                 //if it is a vertice
                 if (word == "v"){
                     //split numbers up and create new vector
                     string numAsString = "";
                     vector <float> numbers;

                     //go through string
                     for (int i = index + 1; i < line.size();i++){
                     if (line[i] != ' '){ //concatenate numbers until space is found
                             numAsString += line[i];
                         }
                         else{
                             numbers.push_back(stod(numAsString)); //convert string to float
                             numAsString = ""; //reset numAsString to an empty string
                         }
                     }
                     numbers.push_back(stod(numAsString)); //push in last element
                     
                     //create and add vertice to mesh's vertices vector
                     vec3 newVertice (numbers.at(0),numbers.at(1), numbers.at(2));
                     createdMesh.addVertice(newVertice);
                 }
                 
                 //if it is a face
                 else if (word == "f"){
                     string numAsString = "";
                     bool first = true; //indicates that number is the first one
                     vector<int> numbers; //store 3 values that will be used to create triangle
                     
                     //search for values that indicate index in vertice vector
                     for (int i = index + 1; i < line.size();i++){
                         if (line[i]!='/' && line[i]!=' '){
                             numAsString += line[i];
                         }
                         else{
                             if(line[i] == ' '){
                                 numAsString = "";
                                 first = true;
                             }else{
                                 //push first number into numbers vector
                                 if (first){
                                     numbers.push_back(stoi(numAsString)-1);
                                     first = false;
                                 }
                             }
                         }
                     }
                     
                     //create and add new Triangle to mesh's triangle vector
                     Triangle newTriangle (numbers.at(0),numbers.at(1), numbers.at(2));
                     createdMesh.addTriangle(newTriangle);
                 }
             }
         }
}
