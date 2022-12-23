#include "Polynomial.h"
#include <fstream>
#include "graphic.h"
#include <iostream>
using namespace std;


typedef char str[40];
str Thaotac[3] = { "READING DATA FROM FILE . ", "READING DATA FROM KEYBOARD. ", "EXIT!!" };
str Thaotac1[5] = { "ADD POLYNOMIALS","SUBTRACT POLYNOMIALS", "MULTIPLY POLYNOMIALS", "DIVIDE POLYNOMIALS", "EXIT" };
str Thaotac2[5] = { "REUSING TWO POLYNOMIALS","REUSING FIRST POLYNOMIAL","REUSING SECOND POLYNOMIAL","USING NEW POLYNOMIALS","EXIT" };
str Thaotac3[2] = { "YES !", "NO !" };
// Reading data from keyboard.
void input(string &, string &);
void input(string &);

//MENU LUA CHON BAN DAU
void MENU(string& str1, string& str2);
// Reading data from file.
void readfile(string &, string &);
void readfile(string &);

// ham luu du lieu vao file
void writefile(string, string, Polynomial, int);
void writefile(string, string, Polynomial, Polynomial);

// check and handle string
bool check(char x);
bool checkPoly(string str);
void transfor(string &);

void thankyou();

//MENU

int main(){
	    string str1, str2;
system("color 70");
	resizeConsole(1920, 1018);	
            
	{
		TextColor(114);
        fflush(stdin);
        ifstream input("Polynomial_calculator.txt");
        int e=20, f=2;
        while (!input.eof())
        {
        	gotoXY(e,f++);	
            char temp[255];
            input.getline(temp, 255);
            string str = temp;
            cout << str<<endl;
        }
        input.close();
    }
    {
    	TextColor(124);
            fflush(stdin);
        ifstream input("Logo.txt");
        int e=110, f=16;
        while (!input.eof())
        {
        	gotoXY(e,f++);	
            char temp[255];
            input.getline(temp, 255);
            string str = temp;
            cout << str<<endl;
        }
        input.close();
    }
		SetColor(116);  
    Box(20,20,70,20);
    {
    			TextColor(118);  
    	int m=25,n=22;
        fflush(stdin);
        ifstream input("vovanduc.txt");
        while (!input.eof())
        {
        		gotoXY(m,n++);	
            char temp[100];
            input.getline(temp, 100);
            string str = temp;
            cout << str << endl;
        }
        input.close();
    }
    gotoXY(22,45);
    system ("pause");
	do{
		system("cls");
	//	MENU(str1,str2);
	    int x=100,y=20;	
    int t = menu(Thaotac, 3, AD);
    if (t == 0)
    {
        while (true)
        {

            char file[20];
            BOX(x, y, 80, 4);
            gotoXY(x + 1, y + 2);
            cout << "Enter the filename: ";
              fflush(stdin);
            cin >> file;
            ifstream input(file);
            
            if (input.fail())
	        {
	        	            box(100, 15, 80, 2, " !!Failed to open this file!  ", 124);
            gotoXY(121, 22);
            for (int i = 0; i < 20; i++)
            {
                SetColor(120);
                cout << " ";
            }       
	            continue;
	        }
            input >> str1;
            input >> str2;
            input.close();
            bool cnt = true;
            int count1 = 0;
            for (int i = 0; i < str1.length(); i++)
            {
                if (!check(str1[i]))
                {
                    cnt = false;
                    break;
                }
                if (str1[i] == '(')
                    count1++;
                else if (str1[i] == ')')
                    count1--;
            }
            int count2 = 0;
            for (int i = 0; i < str2.length(); i++)
            {
                if (!check(str2[i]))
                {
                    cnt = false;
                    break;
                }
                if (str2[i] == '(')
                    count2++;
                else if (str2[i] == ')')
                    count2--;
            }
            if (cnt && checkPoly(str1) && checkPoly(str2) && count1 == 0 && count2 == 0)
                break;
            box(x, y - 3, 80, 2, " !! The polynomial you entered is not valid, please correct it and try again.  ", 124);
            gotoXY(x + 21, y + 2);
            for (int i = 0; i < 20; i++)
            {
                SetColor(120);
                cout << " ";
            }
        }
    }
    else if (t == 1)
    {
        while (true)
        {
            BOX(100, 18, 80, 4);
            gotoXY(101, 20);
            cout << "Polynomal 1 : ";
            cin >> str1;
            bool cnt = true;
            int count = 0;
            for (int i = 0; i < str1.length(); i++)
            {
                if (!check(str1[i]))
                {
                    cnt = false;
                    break;
                }
                if (str1[i] == '(')
                    count++;
                else if (str1[i] == ')')
                    count--;
            }
            if (cnt && checkPoly(str1) && count == 0)
                break;
            box(100, 15, 80, 2, " !! The polynomial you entered is not valid, please correct it and try again.  ", 124);
            gotoXY(115, 20);
            for (int i = 0; i < str1.length(); i++)
            {
                SetColor(120);
                cout << " ";
            }       

        }
             gotoXY(101, 16);
            for (int i = 0; i < 79; i++)
            {
                SetColor(120);
                cout << " ";
            }		
		       
        while (true)
        {

            BOX(100, 24, 80, 4);
            gotoXY(101, 26);
            cout << "Polynomal 2 : ";
            cin >> str2;
            bool cnt = true;
            int count = 0;
            for (int i = 0; i < str2.length(); i++)
            {
                if (!check(str2[i]))
                {
                    cnt = false;
                    break;
                }
                if (str2[i] == '(')
                    count++;
                else if (str2[i] == ')')
                    count--;
            }
            if (cnt && checkPoly(str2) && count == 0)
                break;
            box(100, 15, 80, 2, " !! The polynomial you entered is not valid, please correct it and try again.  ", 124);
            gotoXY(115, 26);
            for (int i = 0; i < str2.length(); i++)
            {
                SetColor(120);
                cout << " ";
            }
        }
    }else if(t==2){
    thankyou();	
    return 0;	 
	} 
		 int option1;
        transfor(str1);
        transfor(str2);
        Input in1(str1);
        Input in2(str2);
        Polynomial P1(in1);
        Polynomial P2(in2);
	    		
    do{
                string var;
            if (P1.getVar()=="") var=P2.getVar();
            else var=P1.getVar();
            //hienthi 2 chuoi
            system("cls");
            Str(P1.result(), P2.result()); 
            //system("pause");
            int t=menu(Thaotac1, 5, ADD);	
            Polynomial ans;
            Polynomial Re;
            // hien ket qua
            if (t == 0)
            {
                ans = P1 + P2;
                ans.display();
            }
            else if (t == 1)
            {
                ans = P1 - P2;
                ans.display();
            }
            else if (t == 2)
            {
                ans = P1 * P2;
                ans.display();
            }
            else if (t == 3)
            {
                Re.setVar(P1.getVar());
                ans = PolynomialsDivision(P1, P2, Re);
                ans.display();
                gotoXY(95, 24);
                cout << "Remaindent: ";
                gotoXY(95, 26);
                cout<<Re.result();
            }
            else if (t == 4)
            {
                break;
            }

         int n;
     gotoXY(100,33);
	 system("pause");
	             // Save
            system("cls");
            int tt = menu(Thaotac3, 2, Save);
            if (tt == 0)
            {
                if (t == 3)
                {
 	              	int x=100,y=20;
                    char file[20];
                    BOX(x, y, 80, 4);
                    gotoXY(x + 1, y + 2);                    
                    cout << "Enter the file name: ";
                    cin >> file;
                    ofstream output(file);
                    output << "Your caculation is:\n";
                    output << "( " << str1 << " ) / ( " << str2 << " )" << endl;
                    Output out(ans.getData());
                    output << "The answer of the calculation:\n";
                    output << "Quotient: " << out.handle_arr(ans.getVar()) << endl;
                    out.setArr(Re.getData());
                    output << "Redmaindent: " << out.handle_arr(ans.getVar()) << endl;

                    output.close();
                }
                else
                {
                	int x=100,y=20;
                    char file[20];
                    BOX(x, y, 80, 4);
                    gotoXY(x + 1, y + 2);
                    cout << "Enter the filename: ";
                    fflush(stdin);
                    cin >> file;
                    ofstream output(file);
                    Output out(ans.getData());
                    output << "Your caculation is:\n";
                    output << "( " << str1 << " ) ";
                    switch (t)
                    {
                    case 1:
                        output << "+";
                        break;
                    case 2:
                        output << "-";
                        break;
                    default:
                        output << "*";
                        break;
                    }
                    output << "( " << str2 << " ) ";
                    output << "The answer of the calculation:\n";
                    output << out.handle_arr(ans.getVar()) << endl;
                    output.close();
                }
               system ("cls");             
            BOX(100, 20, 50, 4);
            gotoXY(101, 22);    
            cout<<" Saved successfully!!";
            }
            if(tt!=0)  system ("cls");
            int m=menu(Thaotac3,2,continuee);
       //     if(m==0) continue;
            if(m==1) {
            thankyou();	
            return 0;	
			}
            
        //bang lua chon 2
		            system("cls");
            int ttt = menu(Thaotac2, 5, ADD);
            if (ttt == 0)
            {
                continue;
            }
            else if (ttt == 1)
            {
                system("cls");
                int a = menu(Thaotac, 3, AD);
                if (a == 0)
                {
                    readfile(str2);
                }
                else if (a == 1)
                {
                    input(str2);
                }
                else
                {
                    break;
                }
                transfor(str2);
                in2.setStr(str2);
                P2.setData(in2);
            }
            else if (ttt == 2)
            {
                system("cls");
                int a = menu(Thaotac, 3, AD);
                if (a == 0)
                {
                    readfile(str1);
                }
                else if (a == 1)
                {
                    input(str1);
                }
                else
                {
                    break;
                }
                transfor(str1);
                in1.setStr(str1);
                P1.setData(in1);
            }
            else if (ttt == 3)
            {
            //	system("cls");
                break;
            }
            else if (ttt == 4)
            {
            	thankyou();	
                return 0;
            }
	}while(true);
		
	}while(true);
}




void readfile(string &str1, string &str2)
{
    while (true)
    {
        char file[20];
        cout << ("Enter the filename: ");
        fflush(stdin);
        cin >> file;
        ifstream input(file);
        if (input.fail())
        {
            cout << "Failed to open this file!" << endl;
            continue;
        }
        input >> str1;
        input >> str2;
        input.close();
        bool cnt = true;
        int count1 = 0;
        for (int i = 0; i < str1.length(); i++)
        {
            if (!check(str1[i]))
            {
                cnt = false;
                break;
            }
            if (str1[i] == '(')
                count1++;
            else if (str1[i] == ')')
                count1--;
        }
        int count2 = 0;
        for (int i = 0; i < str2.length(); i++)
        {
            if (!check(str2[i]))
            {
                cnt = false;
                break;
            }
            if (str2[i] == '(')
                count2++;
            else if (str2[i] == ')')
                count2--;
        }
        if (cnt && checkPoly(str1) && checkPoly(str2) && count1 == 0 && count2 == 0)
            break;
        cout << "The polynomial you entered is not valid, please correct it and try again." << endl;
    }
}

void readfile(string& str)
{
    while (true)
    {
        BOX(100, 24, 80, 4);
        gotoXY(101, 26);
       	char file[20];
    	cout << ("Input the filename: ");
        fflush(stdin);
        cin >> file;
        ifstream input(file);
        if (input.fail())
        {
            cout << "Failed to open this file!" << endl;
            continue;
        }
        input >> str;
        input.close();
        bool cnt = true;
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (!check(str[i]))
            {
                cnt = false;
                break;
            }
            if (str[i] == '(')
                count++;
            else if (str[i] == ')')
                count--;
        }
        if (cnt && checkPoly(str) && count == 0)
            break;
        box(100, 15, 80, 2, " !! The polynomial you entered is not valid, please correct it and try again.  ", 124);
    }
}
void writefile(string str1, string str2, Polynomial ans, int option)
{
    char file[20];
    cout << "Enter the filename: ";
    cin >> file;
    ofstream output(file);

    Output out(ans.getData());
    output << "Your caculation is:\n";
    output << "( " << str1 << " ) ";
    switch (option)
    {
    case 1:
        output << "+";
        break;
    case 2:
        output << "-";
        break;
    default:
        output << "*";
        break;
    }
    output << "( " << str2 << " ) ";
    output << "The answer of the calculation:\n";
    output << out.handle_arr(ans.getVar()) << endl;
    cout << "Your file saved.\n";
    cout << "Mission accomplished.\n";
    output.close();
}

void writefile(string str1, string str2, Polynomial ans, Polynomial re)
{
    char file[20];
    cout << "Enter the file name: ";
    cin >> file;
    ofstream output(file);

    output << "Your caculation is:\n";
    output << "( " << str1 << " ) / ( " << str2 << " )" << endl;
    Output out(ans.getData());
    output << "The answer of the calculation:\n";
    output << "Quotient: " << out.handle_arr(ans.getVar()) << endl;
    out.setArr(re.getData());
    output << "Redmaindent: " << out.handle_arr(ans.getVar()) << endl;
    cout << "Your file saved.\n";
    cout << "Mission accomplished.\n";
    output.close();
}

void input(string &str1, string &str2)
{
    while (true)
    {
        cout << "Enter first polynomial: ";
        cin >> str1;
        bool cnt = true;
        int count = 0;
        for (int i = 0; i < str1.length(); i++)
        {
            if (!check(str1[i]))
            {
                cnt = false;
                break;
            }
            if (str1[i] == '(')
                count++;
            else if (str1[i] == ')')
                count--;
        }
        if (cnt && checkPoly(str1) && count == 0)
            break;
        cout << "The polynomial you entered is not valid, please correct it and try again." << endl;
    }
    while (true)
    {
        cout << "Enter second polynomial: ";
        cin >> str2;
        bool cnt = true;
        int count = 0;
        for (int i = 0; i < str2.length(); i++)
        {
            if (!check(str2[i]))
            {
                cnt = false;
                break;
            }
            if (str2[i] == '(')
                count++;
            else if (str2[i] == ')')
                count--;
        }
        if (cnt && checkPoly(str2) && count == 0)
            break;
        cout << "The polynomial you entered is not valid, please correct it and try again." << endl;
    }
}

void input(string& str)
{
    while (true)
    {    
        BOX(100, 24, 80, 4);
        gotoXY(101, 26);
        cout << "Enter polynomial: ";
        cin >> str;
        bool cnt = true;
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (!check(str[i]))
            {
                cnt = false;
                break;
            }
            if (str[i] == '(')
                count++;
            else if (str[i] == ')')
                count--;
        }
        if (cnt && checkPoly(str) && count == 0)
            break;
        box(100, 15, 80, 2, " !! The polynomial you entered is not valid, please correct it and try again.  ", 124);
    }
}
bool check(char x)
{
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9') || (x >= '(' && x <= '.') || x == '^')
        return true;
    return false;
}

bool checkPoly(string str)
{
    if (!((str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == '(') || !((str[str.length() - 1] >= '0' && str[str.length() - 1] <= '9') || str[str.length() - 1] == ')'))
        return false;
    int cnt = true;
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (!((str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i + 1] >= '*' && str[i + 1] <= '.') || (str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == ')'))
                return false;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (!((str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z') || str[i + 1] == '^'))
                return false;
        }
        else if (str[i] == '*')
        {
            if (!((str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z')))
                return false;
        }
        else if ((str[i] >= '+' && str[i] <= '.') || str[i] == '^')
        {
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
                if (!((str[i] == '+' || str[i] == '-') && str[i + 1] == '('))
                    return false;
        }
        else if (str[i] == '(')
        {
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9') && str[i + 1] != '(' && str[i + 1] != '-')
                return false;
        }
        else if (str[i] == ')')
        {
            if (str[i + 1] != '+' && str[i + 1] != '-' && str[i + 1] != '*' && str[i + 1] != ')')
                return false;
        }
    }
    return true;
}

void transfor(string &str)
{
    if (str[0] == '(')
        str[0] = '|';
    for (int i = str.length() - 1; i > 0; i--)
    {
        while (i >= 0 && str[i] != '(')
            i--;
        if (i < 0)
            break;
        if (i == 0)
        {
            while (i < str.length() && str[i] != ')')
                i++;
            str[i] = '|';
            break;
        }
        int left = i;
        bool negative = false;
        if (str[left - 1] == '-')
            negative = true;
        if (str[left + 1] >= '0' && str[left + 1] <= '9')
        {
            if (negative)
                str[left] = '-';
            else
                str[left] = '+';
        }
        else
            str[left] = '|';
        str[left - 1] = '|';
        while (i < str.length() && str[i] != ')')
            i++;
        if (negative)
        {
            for (int k = left + 1; k < i; k++)
            {
                if (str[k] == '-')
                    str[k] = '+';
                else if (str[k] == '+')
                    str[k] = '-';
            }
        }
        str[i] = '|';
        i = left;
    }
}

void thankyou(){
	{
		system("cls");
        fflush(stdin);
        		TextColor(116);
        ifstream input("Thank_you.txt");
        int x=40,y=15;
        while (!input.eof())
        {
        	gotoXY(x,y++);
            char temp[255];
            input.getline(temp, 255);
            string str = temp;
            cout << str << endl;
        }
        input.close();
    }
}
