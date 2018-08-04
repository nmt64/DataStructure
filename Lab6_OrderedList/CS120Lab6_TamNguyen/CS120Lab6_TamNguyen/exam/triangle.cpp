//
//  triangle.cpp
//  CS120Lab6_TamNguyen
//
//  Created by Nguyen Tam on 2/20/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include "triangle.hpp"
class Triangle {
public:
    Triangle();
    Triangle (double sideAB, double sideBC, double sideAC, double angleA, double angleB, double angleC);
    
    double get_sideAB() const;
    void set_sideAB(double x);
    double get_sideBC() const;
    void get_sideBC(double x);
    double get_sideAC() const;
    void get_sideAC(double x);
    
    double get_angleA() const;
    void set_angleA(double a);
    double get_angleB() const;
    void set_angleB(double a);
    double get_angleC() const;
    void set_angleC(double a);
    
    bool is_right() const;
    bool is_equi() const;
private:
    double side_AB, side_BC, side_AC;
    double angle_A, angle_B, angle_C;
};

const int Max_Sack_Size = 10;
int size;
Type *Sack;


// Data members
int maxSize,
size,             // Actual number of data item in the list
cursor;           // Cursor array index
DataType *dataItems;  // Array containing the list data item
};

template <Class Type>
Sack<Type>:: Sack(int maxNumber) : maxSize(maxNumber), size(0) {
    SackItems = new Sack[Maxsize];
}


template <Class Type>
void Sack<Type>:: grab() {
    if (size != 0)
    {
        delete sack[size--];
    }
}



Text textArray[4];


textArray[0] = Text("alpha");
textArray[1] = Text("ache");
textArray[2] = Text("aah");
textArray[3] = Text("able");


int max = textArray[0];
for (int i = 1, i <= maxSize, i++ )
    {
        if (textAarray[i] > max) {
            max = textArray[i];
        }
    }
cout << "The largest Text object is" << max << endl;

return 0;

for (int i = 4; i < maxSize;i--) {
    cout << "The list object is: " << textArray[size--] << "\n" << endl;
}

        
     






