#include "ofApp.h"
#include "MyMesh.h"
#include "Triangle.h"
#include <fstream>
using namespace glm;
using namespace std;
//--------------------------------------------------------------
void ofApp::setup(){
    createdMesh.testMesh(); //always start by drawing pyramind
    cout << "Please drag an OBJ file into the OF application in order to see it drawn!" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
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
    createdMesh.clear();
    readFromOBJFile(dragInfo.files[0]);
    cout << endl;
    createdMesh.printMeshInfo();
}
//--------------------------------------------------------------
void ofApp::readFromOBJFile(string path){
    fstream fin;
    
    //open file
    fin.open(path);

    //if file fails to open
    if (fin.fail()) {
        cout << "Failed to open OBJ file with the path: " << path << endl;
    } else {
        //read until end of file
        string line;
        while (getline(fin, line)) {//read the line
            istringstream iss (line);
            string word;
            iss >> word;
            
            if (word == "v"){
                double x, y, z;
                iss >> x >> y >> z;
                vec3 newVertice (x,y,z);
                createdMesh.addVertice(newVertice);
            }

            //if it is a face
            //consider that face on file is in the form: f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3
            else if (word == "f"){
                string group1, group2, group3;
                //we are only caring about vertice indices. That means we only want v1, v2, v3
                string numAsString;
                
                iss >> group1 >> group2 >> group3;
            
                int ind1, ind2, ind3;
                if (group1.find_first_of('/') != -1){ //if face values are written with /
                    string ind1AsString = group1.substr(0,group1.find_first_of('/'));
                    string ind2AsString = group2.substr(0,group2.find_first_of('/'));
                    string ind3AsString = group3.substr(0,group3.find_first_of('/'));
                    
                    ind1 = stoi(ind1AsString) - 1;
                    ind2 = stoi(ind2AsString) - 1;
                    ind3 = stoi(ind3AsString) - 1;
                }
                else{ //if face values are written without vt and vn
                    ind1 = stoi(group1) - 1;
                    ind2 = stoi(group2) - 1;
                    ind3 = stoi(group3) - 1;
                }

                //create and add new Triangle to mesh's triangle vector
                Triangle newTriangle (ind1, ind2, ind3);
                createdMesh.addTriangle(newTriangle);
            }
        }
    }
    fin.close();
}
