//
//  Mesh.cpp
//  Proj1MeshViewer
//
//  Created by Thi Nguyen on 9/2/20.
//

#include "Mesh.h"
using namespace glm;

Mesh::Mesh(){
    
}

//Construct Mesh with given vector<vec3> and vector<Triangle>
Mesh::Mesh (vector<vec3> v, vector<Triangle> t){
    vertices = v;
    triangles = t;
}

//Add Vertice to vertices vector of Mesh
void Mesh::addVertice(vec3 &v){
    vertices.push_back(v);
}

//Add Triangle to triangles vector of Mesh
void Mesh::addTriangle(Triangle &tri){
    triangles.push_back(tri);
}

//Iterate through all triangles and draw them
void Mesh::draw(){
    //iterate all triangles
    for (Triangle t: triangles){
        
        //grab array of ints that store indexes
        int* indexes = t.getIndexes();
        
        ofNoFill(); //don't fill in triangles
        
        //draw triangle from three vec3 in vertices vector
        vec3 i (vertices.at(indexes[0])); //construct vec3 with coordinates from vertices vector
        vec3 j (vertices.at(indexes[1]));
        vec3 k (vertices.at(indexes[2]));
        ofDrawTriangle(i,j,k);
    }
}

void Mesh::printMeshInfo(){
    cout << "Mesh Information: " << endl;
    cout << "Total # of vertices: " << vertices.size() << endl; //prints out # of vertices
    cout << "Total # of faces: " << triangles.size() << endl; //prints out # of faces
    cout << "Mesh size (kB): " << sizeof(Triangle) * triangles.size()  * 0.001 << endl; //prints our size of Mesh in kB
    
}

//Draw two pyramids that share the same square base
void Mesh::testMesh(){
    
    //add vertices
    vertices.push_back(vec3(5,0,0)); //index 0
    vertices.push_back(vec3(-5,0,0)); //index 1
    vertices.push_back(vec3(0,0,-5)); //index 2
    vertices.push_back(vec3(0,0,5)); //index 3
    vertices.push_back(vec3(0,5,0)); //index 4
    
    //add triangles
    //base of pyramid
    triangles.push_back(Triangle(0,3,2));
    triangles.push_back(Triangle(3,1,2));
    
    //upper pyramid
    triangles.push_back(Triangle(0,3,4));
    triangles.push_back(Triangle(0,4,2));
    triangles.push_back(Triangle(3,1,4));
    triangles.push_back(Triangle(1,2,4));
    
    printMeshInfo();
    
}

//read from obj file
void Mesh::clear(){
    vertices.clear();
    triangles.clear();
}
