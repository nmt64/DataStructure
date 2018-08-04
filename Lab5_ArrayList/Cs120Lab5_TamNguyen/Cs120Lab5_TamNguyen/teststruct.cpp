//
//  teststruct.cpp
//  Cs120Lab5_TamNguyen
//
//  Created by Nguyen Tam on 2/15/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include "ListArray.cpp"
#include <iostream>
using namespace std;

struct coords
{
    float x;
    float y;
    float z;
};

int main ()
{
    List<coords> coords(20);// Set of samples
//    struct newCoords(float x,float y, float z);
    
    struct coords a;
    cout << "Enter list of samples (end with EOF) : ";
    while ( cin >> a.x >> a.y >> a.z ) {
        coords.insert(a);
    }
}




