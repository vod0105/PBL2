#pragma once
#include "Vector.h"
 
class Input
{
private:
    string str;
 
public:
    Input();
    Input(string);
    void setStr(string);
    string getStr();
    int getDegree();
    string getVar();
    Vector handle_string();
    friend class Polynomial;
};