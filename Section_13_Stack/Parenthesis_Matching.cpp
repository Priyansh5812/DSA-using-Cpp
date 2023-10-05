#include <iostream>
using namespace std;

bool isEmpty(int top)
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(int top , string s)
{
    if(top == s.size()-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{   int top = -1;
    string s;
    cout << "Enter the expression" << endl;
    getline(cin , s);
    char * ptr = new char[s.size()];
    for(int i =0 ; s[i]!= '\0' ;i++)
    {
        if(s[i]== ')' || s[i] == '(')
        {
            if(s[i] == '(')
            {
                if(isFull(top , s))
                {
                    cout << "Expression not Perfectly Parenthesized" << endl;
                    return 0;
                }
                else
                {
                    top++;
                    ptr[top]= s[i];
                }
            }
            else
            {
                if(isEmpty(top))
                {
                    cout << "Expression not Perfectly Parenthesized" << endl; 
                    return 0;
                }
                else
                {
                    top--;
                }
            }
        }
    }
    if(top == -1)
    {
        cout << "Expression is Perfectly Parenthesized" << endl;
    }
    else
    {
        cout << "Expression not Perfectly Parenthesized" << endl; 
    }
    
    return 0;
}