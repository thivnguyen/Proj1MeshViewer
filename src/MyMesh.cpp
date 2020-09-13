//
//  MyMesh.cpp
//  Proj1MeshViewer
//
//  Created by Thi Nguyen  on 9/2/20.
//

#include "MyMesh.h"
using namespace glm;

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
