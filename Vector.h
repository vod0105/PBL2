#pragma once
#include <iostream>
using namespace std;
 
class Vector
{
private:
    int n;
    double *vector;
 
public:
    Vector();
    Vector(int);
    Vector(int, double);
    Vector(const Vector &);
    ~Vector();
    void push_back(int);
    void pop_back();
    int size();
    void resize(int);
    double back();
    bool empty();
    const Vector &operator=(const Vector &);
    double &operator[](int);
};

