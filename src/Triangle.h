//
//  Triangle.h
//  Proj1MeshViewer
//
//  Created by Thi Nguyen  on 9/3/20.
//

#ifndef Triangle_h
#define Triangle_h

class Triangle{
public:
    Triangle (int coord1, int coord2, int coord3);
    int* getIndexes();
    
private:
    int indexes [3]; //index in vertices array
};

#endif /* Triangle_h */
