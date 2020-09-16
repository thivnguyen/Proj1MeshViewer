#include "ofApp.h"
#include "MyMesh.h"
#include "Triangle.h"
#include <fstream>
using namespace glm;
using namespace std;
//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    //draw testMesh
    //createdMesh.testMesh();
    
    //draw mesh that was read from obj file
    createdMesh.draw();
    cam.end();
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
    fstream fin;
    string path = dragInfo.files[0]; //path of file
    
    //open file
    fin.open(path);
    
    //if file fails to open
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
            while (line[index] != ' ' && line[index] != '\0'){
                word += line[index];
                index++;
            }
            
            //if it is a vertice
            if (word == "v"){
                //split numbers up and create new vector
                string numAsString = "";
                vector <float> numbers; //store 3 values that will be added as a coordinate
                
                //go through string
                for (int i = index + 1; i < line.size();i++){
                    if (line[i] != ' '){ //concatenate numbers until space is found
                        numAsString += line[i];
                    }
                    else{
                        numbers.push_back(stod(numAsString)); //convert string to double
                        numAsString = ""; //reset numAsString to an empty string
                    }
                }
                numbers.push_back(stod(numAsString)); //push in last number
                
                //create and add vertice to mesh's vertices vector
                vec3 newVertice (numbers.at(0),numbers.at(1), numbers.at(2));
                createdMesh.addVertice(newVertice);
            }
            
            //if it is a face
            //consider that face on file is in the form: f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3
            else if (word == "f"){
            
                //we are only caring about vertice indices. That means we only want v1, v2, v3
                string numAsString = "";
                bool first = true; //indicates that number is the first one in the group of numbers
                vector<int> vertexIndices; //store 3 vertex indices that will be used to create triangle
                
                //search for v1, v2, v3 value
                for (int i = index + 1; i < line.size();i++){
                    if (line[i]!='/' && line[i]!=' '){ //concatenate numbers until space or / is found
                        numAsString += line[i];
                    }
                    else{
                        //if it is a space, that means we are starting to read next group of numbers
                        if(line[i] == ' '){
                            numAsString = "";
                            first = true;
                        }else{
                            //push first vertex index into vertexIndices vector
                            if (first){
                                vertexIndices.push_back(stoi(numAsString)-1);
                                first = false;
                            }
                        }
                    }
                }
                
                //create and add new Triangle to mesh's triangle vector
                Triangle newTriangle (vertexIndices.at(0),vertexIndices.at(1), vertexIndices.at(2));
                createdMesh.addTriangle(newTriangle);
            }
        }
    }
}
