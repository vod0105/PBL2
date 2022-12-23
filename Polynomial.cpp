#include "Polynomial.h"
#include"graphic.h"
Polynomial::Polynomial()
{
    this->data.push_back(0);
    this->variable = "";
}
Polynomial::Polynomial(Vector data, string var = "")
{
    this->data = data;
    this->variable = var;
}
Polynomial::Polynomial(Input in)
{
    this->data = in.handle_string();
    this->variable = in.getVar();
}
Polynomial::Polynomial(string var){
    this->data.push_back(0);
    this->variable = var;
}

void Polynomial::setData(Vector data)
{
    this->data = data;
}
void Polynomial::setData(Input in)
{
    this->data = in.handle_string();
    this->variable = in.getVar();
}

Vector Polynomial::getData()
{
    return this->data;
}

void Polynomial::setVar(string var)
{
    this->variable = var;
}
string Polynomial::getVar()
{
    return this->variable;
}

void Polynomial::display()
{
    Output out(this->data);
    Hienketqua(out.handle_arr(this->variable));
}

string Polynomial::result(){
	Output out(this->data);
    return out.handle_arr(this->variable);
}

const Polynomial &Polynomial::operator=(const Polynomial &v)
{
    this->data = v.data;
    this->variable = v.variable;
    return *this;
}

Polynomial Polynomial::operator+(Polynomial &p)
{
    Vector p1 = this->data;
    Vector p2 = p.data;
    int size1 = p1.size();
    int size2 = p2.size();

    Vector ans(max(size1, size2));
    for (int i = 0; i < min(size1, size2); i++)
        ans[i] = p1[i] + p2[i];
    for (int i = min(size1, size2); i < size1; i++)
        ans[i] = p1[i];
    for (int i = min(size1, size2); i < size2; i++)
        ans[i] = p2[i];

    string var;
    if (this->getVar()=="") var=p.getVar();
    else var=this->getVar();
    Polynomial c(ans, var);
    return c;
}

Polynomial Polynomial::operator-(Polynomial &p)
{
    Vector p1 = this->data;
    Vector p2 = p.data;
    int size1 = p1.size();
    int size2 = p2.size();

    Vector ans(max(size1, size2));
    for (int i = 0; i < min(size1, size2); i++)
        ans[i] = p1[i] - p2[i];
    for (int i = min(size1, size2); i < size1; i++)
        ans[i] = p1[i];
    for (int i = min(size1, size2); i < size2; i++)
        ans[i] = -p2[i];

    string var;
    if (this->getVar()=="") var=p.getVar();
    else var=this->getVar();
    Polynomial c(ans, var);
    return c;
}

Polynomial Polynomial::operator*(Polynomial &p)
{
Vector p1 = this->data;
    Vector p2 = p.data;
    int size1 = p1.size();
    int size2 = p2.size();
    int size = size1 + size2 - 1;
    Vector ans(size);
    for (int m = size1 - 1; m >= 0; m--)
        for (int n = size2 - 1; n >= 0; n--)
            ans[m + n] += p1[m] * p2[n];
    string var;
    if (this->getVar() == "")
        var = p.getVar();
    else
        var = this->getVar();
    Polynomial c(ans, var);
    return c;
}

Polynomial PolynomialsDivision(Polynomial a, Polynomial b, Polynomial &c)
{
string var;
    if (a.getVar() == "")
        var = b.getVar();
    else
        var = a.getVar();

    Vector p1 = a.data;
    Vector p2 = b.data;
    int degree1 = p1.size() - 1;
    int degree2 = p2.size() - 1;
    Vector remainder(p1);

    if (degree1 < degree2)
    {
        c.setData(remainder);
        Polynomial ans(var);
        return ans;
    }
    Vector quotient(degree1 - degree2 + 1, 0);
    while (degree1 >= degree2)
    {
        quotient[degree1 - degree2] = remainder[degree1] / p2[degree2];
        Vector res(degree1 + 1, 0);
        for (int i = degree2; i >= 0; i--)
            res[degree1 - degree2 + i] = quotient[degree1 - degree2] * p2[i];
        for (int i = 0; i <= degree1; i++)
            remainder[i] -= res[i];
        remainder.pop_back();
        degree1--;
    }
    while (!remainder.empty() && remainder.back() == 0)
        remainder.pop_back();
    if (remainder.empty())
        remainder.push_back(0);
    c.setData(remainder);
    Polynomial ans(quotient, var);
    return ans;
}
