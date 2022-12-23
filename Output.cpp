#include "Output.h"
#include <math.h>
 
string num_str(int);
string num_str(double);
 
Output::Output()
{
}
Output::Output(Vector arr)
{
    this->arr = arr;
}
 
void Output::setArr(Vector arr)
{
    this->arr = arr;
}
 
Vector Output::getArr()
{
    return this->arr;
}
 
string Output::handle_arr(string var)
{
    string str = "";
    if (arr.size() == 1)
    {
        str += num_str(arr[0]);
        return str;
    }
    int n = arr.size() - 1;
    str += num_str(arr[n]) + "*" + var + "^" + num_str(n);
 
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] == 0)
            continue;
        if (arr[i] > 0 && i < n)
            str += "+";
        str += num_str(arr[i]) + "*" + var + "^" + num_str(i);
    }
    
    if (arr[0] > 0)
        str += "+" + num_str(arr[0]);
    else if (arr[0] < 0)
        str += num_str(arr[0]);
    return str;
}
 
string num_str(int n)
{
    string str = "";
    bool negative = false;
    if (n < 0)
    {
        n = -n;
        negative = true;
    }
    if (n == 0)
        str += "0";
    while (n != 0)
    {
        str = (char)('0' + n % 10) + str;
        n = n / 10;
    }
    if (negative)
        str = "-" + str;
    return str;
}
string num_str(double n)
{
    string str = "";
    bool negative = false;
    if (n < 0)
    {
        n = -n;
        negative = true;
    }
 
    int intP = n;
    int fracP = round((n - (int)n) * 10000);
    if (fracP == 0)
    {
        if (negative)
            return "-" + num_str(intP);
        else
            return num_str(intP);
    }
 
    if (intP == 0)
        str += "0";
    while (intP)
    {
        str = (char)('0' + intP % 10) + str;
        intP = intP / 10;
    }
    str += ".";
 
    int fracN = 1000;
    while (fracP < fracN && fracN > 0)
    {
        str += "0";
        fracN /= 10;
    }
    while (fracP % 10 == 0)
        fracP /= 10;
    string frac = "";
    while (fracP)
    {
        frac = (char)('0' + fracP % 10) + frac;
        fracP = fracP / 10;
    }
 
    str = str + frac;
    if (negative)
        str = "-" + str;
    return str;
}