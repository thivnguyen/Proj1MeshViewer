//
//  Mesh.h
//  Proj1MeshViewer
//
//  Created by Thi Nguyen  on 9/3/20.
//

#ifndef Mesh_h
#define Mesh_h

#include "ofMain.h"
#include "Triangle.h"

using namespace glm;

class Mesh{
public:
    Mesh (vector<vec3> v, vector<Triangle> t);
    void addVertice(vec3 &v);
    void addTriangle(Triangle &tri);
    void draw(); //iterate through all triangles and draw them
    
private:
    vector<vec3> vertices; //vertices
    vector<Triangle> triangles; //triangles
};

#endif /* Mesh_h */
