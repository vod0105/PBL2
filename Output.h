#pragma once
#include "Vector.h"
 
class Output
{
private:
    Vector arr;
 
public:
    Output();
    Output(Vector);
    void setArr(Vector);
    Vector getArr();
    string handle_arr(string);
};