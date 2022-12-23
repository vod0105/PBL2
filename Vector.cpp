#include "Vector.h"
 
Vector::Vector()
{
    this->n = 0;
    this->vector = NULL;
}
Vector::Vector(int n)
{
    this->n = n;
    if (n == 0)
        this->vector = NULL;
    else
    {
        this->vector = new double[n];
        for (int i = 0; i < n; i++)
            *(this->vector + i) = 0;
    }
}
Vector::Vector(int n, double val)
{
    this->n = n;
    if (n == 0)
        this->vector = NULL;
    else
    {
        this->vector = new double[n];
        for (int i = 0; i < this->n; i++)
            *(this->vector + i) = val;
    }
}
Vector::Vector(const Vector &v)
{
    this->n = v.n;
    this->vector = new double[this->n];
    for (int i = 0; i < this->n; i++)
        *(this->vector + i) = v.vector[i];
}
Vector::~Vector()
{
    delete[] this->vector;
    this->n = 0;
}
 
void Vector::push_back(int val)
{
    double *v = new double[this->n + 1];
    for (int i = 0; i < this->n; i++)
        *(v + i) = *(this->vector + i);
    *(v + n) = val;
    delete[] this->vector;
    this->vector = v;
    this->n++;
}
void Vector::pop_back()
{
    if (this->n > 0)
    {
        this->n--;
        double *v = new double[this->n];
        for (int i = 0; i < this->n; i++)
            *(v + i) = *(this->vector + i);
        delete[] this->vector;
        this->vector = v;
    }
}
 
int Vector::size()
{
    return this->n;
}
void Vector::resize(int n)
{
    if (this->n > n)
    {
        while (this->n > n)
            this->pop_back();
    }
    else if (this->n < n)
    {
        while (this->n < n)
            this->push_back(0);
    }
}
 
double Vector::back()
{
    return this->vector[this->n - 1];
}
 
bool Vector::empty()
{
    if (this->n == 0)
        return true;
    return false;
}
 
const Vector &Vector::operator=(const Vector &v)
{
    if (this->n != v.n)
    {
        if (this->n > 0)
            delete[] this->vector;
        this->n = v.n;
        this->vector = new double[this->n];
    }
    for (int i = 0; i < this->n; i++)
        (*this)[i] = v.vector[i];
    return *this;
}
double &Vector::operator[](int index)
{
    static double res = 0;
    if (index >= 0 && index < this->n)
        return this->vector[index];
    return res;
}