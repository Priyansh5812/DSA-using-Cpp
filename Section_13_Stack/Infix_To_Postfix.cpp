#include <iostream>
using namespace std;
// Infix to Postfix Conversion valid only for basic operators +,-,*,/

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

char Pop(char *& arr, int & top)
{
    int temp = top;
    top--;
    return arr[temp];
}

char stacktop(char *& arr , int top)
{
    return arr[top];
}

void Push(char * &arr , char x , int &top)
{
    top++;
    arr[top] = x;
}

int Pre(char x)
{
    if(x == '+' || x == '-')
    {
        return 1;
    }
    else if(x == '/' || x == '*')
    {
        return 2;
    }
    return 0;
}


void convert(string inf , string & pos)
{
    char * arr = new char[inf.size()];
    int top = -1 , pdrev= 0;
    for(int i = 0 ; inf[i] != '\0' ; i++)
    {
        if(isOperator(inf[i]))
        {
            if(top == -1)
            {
                Push(arr , inf[i], top);
            }
            else if(Pre(inf[i]) > Pre(stacktop(arr, top)))
            {
                Push(arr , inf[i], top);
            }
            else
            {
                pos = pos + Pop(arr , top);
                i--;
                continue;
            }
        }
        else
        {
            pos=pos + inf[i];
        }
    }
    while(top!= -1)
    {
        pos = pos + Pop(arr , top);
    }
    cout << endl << pos << endl;
}



int main()
{   string inf , pos;
    cout << "Enter the infix" << endl;
    getline(cin , inf);
    convert(inf , pos);
    return 0;
}