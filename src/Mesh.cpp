//
//  Mesh.cpp
//  Proj1MeshViewer
//
//  Created by Thi Nguyen  on 9/2/20.
//

#include "Mesh.h"
using namespace glm;

Mesh::Mesh (vector<vec3> v, vector<Triangle> t){
    vertices = v;
    triangles = t;
}

//iterate through all triangles and draw them
void Mesh::draw(){
    //iterate all triangles
    for (Triangle t: triangles){
        
        //grab coordinates
        int* indexes = t.getIndexes();
        
        //draw triangle
        ofDrawLine(vertices.at(indexes[0]),vertices.at(indexes[1]));
        ofDrawLine(vertices.at(indexes[0]),vertices.at(indexes[2]));
        ofDrawLine(vertices.at(indexes[1]),vertices.at(indexes[2]));
    }
}

void Mesh::addVertice(vec3 &v){
    vertices.push_back(v);
}

void Mesh::addTriangle(Triangle &tri){
    triangles.push_back(tri);
}
