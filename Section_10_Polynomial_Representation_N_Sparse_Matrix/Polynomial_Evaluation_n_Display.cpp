// Only valid for polynomials with coefficiants and powers < 10
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Term
{
    public:
     int i , j;
};
class Poly
{
    public:
        int coffs , pows;
        Term * arr;
        char * ops;
        Poly(int a) : coffs(a) , pows(a)
        {
            arr = new Term[coffs];
            ops = new char[coffs-1];
        }
};

#pragma region Verification
string Remove_Spaces(string str)
{   int i = 0;
    string str2; 
    while(i < str.length())
    {   
        if(str[i] != ' ')
        {   
            str2 += str[i]; 
        }
        i++;
    }
    return str2;
}

bool isOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_Exp_Invalid(string str)
{   int i = 0;
    while(i < str.length())
    {   
        if(isOperator(str[i]) && i == 0)
        {   
            return true;
        }

        if(isOperator(str[i]))
        {
            if(isOperator(str[i-1]))
            {
                return true;
            }
        }

        if(isOperator(str[i]) && i==str.length()-1)
        {
            return true;
        }
        i++;
    }
    return false;
}

#pragma endregion Verification

int which_op(char x)
{
    if(x == '+')
    {
        return 2;
    }
    if(x == '-')
    {
        return 1;
    }
    if(x == '*')
    {
        return 3;
    }
    if(x == '/')
    {
        return 4;
    }
    return 0;
}

int Count_coeff(string str)
{
    int i = 0 , c = 0;
    while(i < str.length())
    {
        if(isOperator(str[i]) == false && str[i] != 'x')
        {
            if(str[i]!= '^' && str[i-1] != '^')
            {
                c++;
            }
        }
        i++;
    }
    return c;
}


void Store_ops(char * arr , string str)
{
    int i = 0 , c = 0;
    while(i < str.length())
    {
        if(isOperator(str[i]))
        {
            arr[c] = str[i];
            c++;
        }
        i++;
    }
}

void fill_Info(Poly * a , string str)
{   int i = 0;
    int c = 0;
    while(i < str.length())
    {
        if(isOperator(str[i]) == false && str[i]!= '^')
        {   
            if(isOperator(str[i]) == false && i == 0)
            {
                a->arr[c].i = stoi(str.substr(i , 1));
                c++;
            }
            else if(isOperator(str[i-1]) && str[i-1]!= '^')
            {
                a->arr[c].i = stoi(str.substr(i , 1));
                c++;
            }
            
        }
        i++;
    }

    i = c = 0;
    while(i < str.length())
    {
        if(isOperator(str[i]) == false && str[i]!= '^')
        {
            if(str[i-1] == '^')
            {   //cout << str.substr(i , 1) << endl;
                a->arr[c].j = stoi(str.substr(i , 1));
                c++;
            }

            if(str[i] == 'x' && isOperator(str[i+1]))
            {
                a->arr[c].j = 1;
                c++;
            }
            if(isOperator(str[i-1]) && (isOperator(str[i+1]) || str[i+1] == '\0'))
            {
                a->arr[c].j = 0;
                c++;
            }
            
        }
        i++;
    }
}

int Calculate(Poly * a , char * ops , int x)
{
    int res = a->arr[0].i * pow(x , a->arr[0].j);
    for(int i = 0 ; i < a->coffs -1; i++)
    {
        if(which_op(ops[i]) == 1)
        {
            res = res - (a->arr[i+1].i * pow(x , a->arr[i+1].j));
        }

        if(which_op(ops[i]) == 2)
        {
            res = res + (a->arr[i+1].i * pow(x , a->arr[i+1].j));
        }

        if(which_op(ops[i]) == 3)
        {
            res = res * (a->arr[i+1].i * pow(x , a->arr[i+1].j));
        }

        if(which_op(ops[i]) == 4)
        {
            res = res / (a->arr[i+1].i * pow(x , a->arr[i+1].j));
        }


    }
    return res;
}

int main()
{   string exp;
    int x;
    cout << "Enter an Expression" << endl << "For Example 3x^2 + 2x + 1" << endl;
    getline(cin , exp);
    cout << "Enter the value of variable x" << endl;
    cin >> x;
    exp = Remove_Spaces(exp);
    if(is_Exp_Invalid(exp))
    {
        cout << "Invalid Polynomial" << endl;
        return 0;
    }
    
    int c = Count_coeff(exp);
    Poly e(c);
    char * ops = new char[c-1];
    fill_Info(&e , exp);
    
    Store_ops(ops , exp);
    
    cout << "Result : " << Calculate(&e , ops , x);
    return 0;
}

// No. of Cofficiennts = No. of powers