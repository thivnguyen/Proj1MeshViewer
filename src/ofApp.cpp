//
//  ofApp.cpp
//  Proj1MeshViewer
//
//  Last edited by Thi Nguyen on 9/17/20.
//

#include "ofApp.h"
#include "Mesh.h"
#include "Triangle.h"
#include <fstream>
using namespace glm;
using namespace std;
//--------------------------------------------------------------
void ofApp::setup(){
    cam.setDistance(30.0); //30 units from origin
    cam.lookAt(glm::vec3(0,0,0));
    createdMesh.testMesh(); //always start by drawing pyramind
    cout << "Please drag an OBJ file into the OF application in order to see it drawn!" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    //draw x,y,z axis
    drawAxis();
    
    //draw test mesh and draw mesh from obj file when file is dragged in
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
    createdMesh.clear(); //clear mesh
    readFromOBJFile(dragInfo.files[0]); //read information from OBJ file
    cout << endl;
    createdMesh.printMeshInfo(); //print mesh information
}
//--------------------------------------------------------------
//draw x, y, and z axis
void ofApp::drawAxis(){
    //x-axis
    ofSetColor(ofColor::red);
    ofDrawLine(glm::vec3(-50.0, 0, 0), glm::vec3(50.0, 0, 0));
    
    //y-axis
    ofSetColor(ofColor::green);
    ofDrawLine(glm::vec3(0, -50.0, 0), glm::vec3(0, 50.0, 0));
    
    //z-axis
    ofSetColor(ofColor::blue);
    ofDrawLine(glm::vec3(0, 0, -50.0), glm::vec3(0, 0, 50.0));
    
    //set color back to white
    ofSetColor(ofColor::white);
}
//--------------------------------------------------------------
//read through file line by line and add necessary vertices and triangles to mesh
void ofApp::readFromOBJFile(string path){
    fstream fin;
    
    //open file
    fin.open(path);

    //if file fails to open, print error message + return
    if (fin.fail()) {
        cout << "Failed to open OBJ file with the pathname: " << path << endl;
        return;
    }
    //if file successfully opens
    else {
        string line;
        //read entire file, line by line
        while (getline(fin, line)) {//read the line
            istringstream iss (line);
            string typeIdentfier; //identifies if line is storing values for v, vt, vn, vp, f, or l
            iss >> typeIdentfier;
            
            if (typeIdentfier == "v"){
                double x, y, z;
                iss >> x >> y >> z;
                vec3 newVertice (x,y,z);
                createdMesh.addVertice(newVertice);
            }

            //if it is a face
            //consider that face on file is in the form: f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3
            else if (typeIdentfier == "f"){
                string group1, group2, group3;
                //we are only caring about vertice indices. That means we only want v1, v2, v3
                string numAsString;
                
                iss >> group1 >> group2 >> group3;
            
                int ind1, ind2, ind3;
                if (group1.find_first_of('/') != -1){ //if face values are written with /, want only first number
                    string ind1AsString = group1.substr(0,group1.find_first_of('/'));
                    string ind2AsString = group2.substr(0,group2.find_first_of('/'));
                    string ind3AsString = group3.substr(0,group3.find_first_of('/'));
                    
                    ind1 = stoi(ind1AsString) - 1;
                    ind2 = stoi(ind2AsString) - 1;
                    ind3 = stoi(ind3AsString) - 1;
                }
                else{ //if face values are written without vt and vn
                    ind1 = stoi(group1) - 1; //subtract 1 because it refers to offset in vertex list starting at 1 and vector index starts at 0
                    ind2 = stoi(group2) - 1;
                    ind3 = stoi(group3) - 1;
                }

                //create and add new Triangle to mesh's triangle vector
                Triangle newTriangle (ind1, ind2, ind3);
                createdMesh.addTriangle(newTriangle);
            }
        }
    }
    fin.close(); //close file stream
}
