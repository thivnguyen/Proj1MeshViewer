//
//  Triangle.cpp
//  Proj1MeshViewer
//
//  Created by Thi Nguyen  on 9/3/20.
//

#include <stdio.h>
#include "Triangle.h"


Triangle::Triangle (int index1, int index2, int index3){
    indexes[0] = index1;
    indexes[1] = index2;
    indexes[2] = index3;
}

int* Triangle::getIndexes(){
    return indexes;
}

