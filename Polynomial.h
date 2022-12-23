#pragma once
#include "Input.h"
#include "Output.h"

class Polynomial
{
private:
    Vector data;
    string variable;

public:
    Polynomial();
    Polynomial(Vector, string);
    Polynomial(string);
    Polynomial(Input);
    void setData(Vector);
    void setData(Input);
    Vector getData();
    void setVar(string);
    string getVar();
    void display();
        string result();
    Polynomial operator+(Polynomial &);
    Polynomial operator-(Polynomial &);
    Polynomial operator*(Polynomial &);
    friend Polynomial PolynomialsDivision(Polynomial, Polynomial, Polynomial &);
    const Polynomial &operator=(const Polynomial &);
};
