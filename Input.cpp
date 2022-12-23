#include "Input.h"
 
int str_int(string, int &);
double str_double(string, int &);
 
Input::Input()
{
    this->str = "";
}
Input::Input(string s)
{
    this->str = s;
}
 
void Input::setStr(string s)
{
    this->str = s;
}
 
string Input::getStr()
{
    return str;
}
 
int Input::getDegree()
{
    int n = 0, i = 0;
    int size = str.length();
    if (str[0] == '-')
        i++;
    while (i < size && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' || str[i]=='|'))
        i++;
    if (i != size)
    {
        while (true)
        {
            while (str[i] != '+' && str[i] != '-' && str[i]!='|' && i < size)
                i++;
            int j = i - 1;
            while (j >= 0 && str[j] != '^' && str[j] != '+' && str[j] != '-')
                j--;
            if (j >= 0 && str[j] == '^')
            {
                j = i;
                i--;
                n = max(n, str_int(str, i));
                i = j;
            }
            if (i == size)
                break;
            i++;
        }
    }
    return n;
}
 
string Input::getVar()
{
    int n=this->getDegree();
    if (n==0) return "";
    int i = 0;
    while (!((this->str[i] >= 'a' && this->str[i] <= 'z') || (this->str[i] >= 'A' && this->str[i] <= 'Z')))
        i++;
    string var = "";
    while ((this->str[i] >= 'a' && this->str[i] <= 'z') || (this->str[i] >= 'A' && this->str[i] <= 'Z'))
    {
        var += this->str[i];
        i++;
    }
    return var;
}
 
Vector Input::handle_string()
{
    int n = this->getDegree();
    Vector data(n+1);

    int size = str.length(); 
    int i = size - 1;
 
    while (i >= 0)
    {
        if (str[i] == '|')
        {
            i--;
            continue;
        }
        int j = i;
        while ((j >= 0 && str[j] != '^' && str[j] != '+' && str[j] != '-') || str[j] == '|')
            j--;
        if (j >= 0 && str[j] == '^')
        {
            int degree_x = str_int(str, i);
            while (str[i] < '0' || str[i] > '9')
                i--;
            double res = str_double(str, i);
            if (i >= 0 && str[i] == '-')
                res = 0 - res;
            data[degree_x] += res;
        }
        else
        {
            double res = str_double(str, i);
            if (i >= 0 && str[i] == '-')
                res = 0 - res;
            data[0] += res;
        }
        i--;
    }
 
    return data;
}
 
int str_int(string s, int &i)
{
    int k = 1;
    int ans = 0;
    while (i >= 0 && s[i] >= '0' && s[i] <= '9')
    {
        ans += (s[i] - '0') * k;
        k *= 10;
        i--;
    }
    return ans;
}
 
double str_double(string s, int &i)
{
    int k = 1;
    double ans = 0;
    while (i >= 0 && s[i] >= '0' && s[i] <= '9')
    {
        ans += (s[i] - '0') * k;
        k *= 10;
        i--;
    }
    if (s[i] == ',' || s[i] == '.')
    {
        ans /= k;
        k = 1;
        i--;
        while (i >= 0 && s[i] >= '0' && s[i] <= '9')
        {
            ans += (s[i] - '0') * k;
            k *= 10;
            i--;
        }
    }
    return ans;
}