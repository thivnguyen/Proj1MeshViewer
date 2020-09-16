//
//  MyMesh.cpp
//  Proj1MeshViewer
//
//  Created by Thi Nguyen on 9/2/20.
//

#include "MyMesh.h"
using namespace glm;

MyMesh::MyMesh(){
    
}

//Construct MyMesh with given vector<vec3> and vector<Triangle>
MyMesh::MyMesh (vector<vec3> v, vector<Triangle> t){
    vertices = v;
    triangles = t;
}

//Add Vertice to vertices vector of MyMesh
void MyMesh::addVertice(vec3 &v){
    vertices.push_back(v);
}

//Add Triangle to triangles vector of MyMesh
void MyMesh::addTriangle(Triangle &tri){
    triangles.push_back(tri);
}

//Iterate through all triangles and draw them
void MyMesh::draw(){
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

void MyMesh::printMeshInfo(){
    cout << "Total # of vertices: " << vertices.size(); //prints out # of vertices
    cout << "Total # of faces: " << triangles.size(); //prints out # of faces
    
}

//Draw two pyramids that share the same square base
void MyMesh::testMesh(){
    
    //add vertices
    vector<vec3> vertices;
    vertices.push_back(vec3(5,0,0)); //index 0
    vertices.push_back(vec3(-5,0,0)); //index 1
    vertices.push_back(vec3(0,-5,0)); //index 2
    vertices.push_back(vec3(0,5,0)); //index 3
    vertices.push_back(vec3(0,0,5)); //index 4
    vertices.push_back(vec3(0,0,-5)); //index 5
    
    //add triangles
    vector<Triangle> triangles;
    //base of pyramid
    triangles.push_back(Triangle(0,3,4));
    triangles.push_back(Triangle(0,4,2));
    
    //upper pyramid
    triangles.push_back(Triangle(0,3,2));
    triangles.push_back(Triangle(3,1,2));
    triangles.push_back(Triangle(3,1,4));
    triangles.push_back(Triangle(1,2,4));
    
    //lower pyramid
    triangles.push_back(Triangle(0,5,3));
    triangles.push_back(Triangle(3,5,1));
    triangles.push_back(Triangle(0,5,2));
    triangles.push_back(Triangle(2,1,5));
    
    //create Mesh
    MyMesh testMesh (vertices, triangles);
    
    //draw Mesh
    testMesh.draw();
}
