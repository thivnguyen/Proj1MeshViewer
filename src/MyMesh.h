//
//  MyMesh.h
//  Proj1MeshViewer
//
//  Created by Thi Nguyen on 9/3/20.
//

#ifndef Mesh_h
#define Mesh_h

#include "ofMain.h"
#include "Triangle.h"

using namespace glm;

class MyMesh{
public:
    MyMesh();
    MyMesh (vector<vec3> v, vector<Triangle> t);
    void addVertice(vec3 &v);
    void addTriangle(Triangle &tri);
    void draw();
    void printMeshInfo(); 
    void testMesh();
    void clear();
    
private:
    vector<vec3> vertices; //vertices
    vector<Triangle> triangles; //triangles
};

#endif /* Mesh_h */
