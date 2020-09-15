//
//  MyMesh.cpp
//  Proj1MeshViewer
//
//  Created by Thi Nguyen  on 9/2/20.
//

#include "MyMesh.h"
using namespace glm;

MyMesh::MyMesh(){
   
}

MyMesh::MyMesh (vector<vec3> v, vector<Triangle> t){
    vertices = v;
    triangles = t;
}

//iterate through all triangles and draw them
void MyMesh::draw(){
    //iterate all triangles
    for (Triangle t: triangles){
        
        //grab coordinates
        int* indexes = t.getIndexes();
        
        ofNoFill(); //don't fill in triangles
        
        //draw triangle
        ofDrawTriangle(vertices.at(indexes[0]),vertices.at(indexes[1]),vertices.at(indexes[2]));
    }
}

void MyMesh::addVertice(vec3 &v){
    vertices.push_back(v);
}

void MyMesh::addTriangle(Triangle &tri){
    triangles.push_back(tri);
}

void MyMesh::printMeshInfo(){
    cout << "Total # of vertices: " << vertices.size();
    cout << "Total # of faces: " << triangles.size();
    
}

void MyMesh::testMesh(){
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
    
    MyMesh testMesh (vertices, triangles);
    testMesh.draw();
}
