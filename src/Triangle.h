//
//  Triangle.h
//  Proj1MeshViewer
//
//  Created by Thi Nguyen on 9/3/20.
//  Last edited by Thi Nguyen on 9/17/20.

#ifndef Triangle_h
#define Triangle_h

class Triangle{
public:
    Triangle (int coord1, int coord2, int coord3);
    int* getIndexes();
    
private:
    int indexes [3]; //stores 3 integers that indicate which index in vertices array are the triangle's coordinates
};

#endif /* Triangle_h */
