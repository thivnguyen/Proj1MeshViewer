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
//    drawAxis();
    
    vector<vec3> vertices;
//    vertices.push_back(vec3(5,0,0)); //index 0
//    vertices.push_back(vec3(-5,0,0)); //index 1
//    vertices.push_back(vec3(0,-5,0)); //index 2
//    vertices.push_back(vec3(0,5,0)); //index 3
//    vertices.push_back(vec3(0,0,5)); //index 4
    
    vector<Triangle> triangles;
//    triangles.push_back(Triangle(0,3,2));
//    triangles.push_back(Triangle(3,1,2));
//    triangles.push_back(Triangle(0,3,4));
//    triangles.push_back(Triangle(3,1,4));
//    triangles.push_back(Triangle(1,2,4));
//    triangles.push_back(Triangle(0,4,2));
    
    MyMesh mesh (vertices, triangles);
    readFromOBJFile(mesh);
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

void ofApp::readFromOBJFile(MyMesh &mesh){
    fstream fin;

    //open file
    fin.open("/Users/thinguyen/Desktop/olaf.obj"); //enter file path

    if (fin.fail()) {
        cout << "Failed to open OBJ file" << endl;
    } else {
        while (!fin.eof()) {
            string line;
            char delim = ' ';
            getline(fin, line);
            int index = 0;
            string word = "";

            //find what type this is
            while (line[index] != ' ' && line[index] != '/0'){
                word += line[index];
                index++;
            }

            if (word == "v"){
                //split numbers up and create new vector
                string numAsString = "";
                vector <float> numbers;

                for (int i = index + 1; i < line.size();i++){
                if (line[i] != ' '){
                        numAsString += line[i];
                    }
                    else{
                        numbers.push_back(stod(numAsString));
                        numAsString = ""; //reset numAsString to an empty string
                    }
                }
                numbers.push_back(stod(numAsString)); //push in last element
                vec3 newVertice (numbers.at(0),numbers.at(1), numbers.at(2));
                mesh.addVertice(newVertice);
            }
            else if (word == "f"){
                string numAsString = "";
                bool first = true;
                vector<int> numbers;
                for (int i = index + 1; i < line.size();i++){
                    if (line[i]!='/' && line[i]!=' '){
                        numAsString += line[i];
                    }
                    else{
                        if(line[i] == ' '){
                            numAsString = "";
                            first = true;
                        }else{
                            if (first){
                                numbers.push_back(stoi(numAsString)-1);
                                first = false;
                            }
                        }
                    }
                }
                Triangle newTriangle (numbers.at(0),numbers.at(1), numbers.at(2));
                mesh.addTriangle(newTriangle);
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
