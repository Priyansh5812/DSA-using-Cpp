#include <iostream>
using namespace std;

bool isOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int In_Stack_Pre(char x)
{
    if(x == '+' || x == '-')
    {
        return 1;
    }
    else if(x == '*' || x == '/')
    {
        return 3;
    }
    else if(x == '^')
    {
        return 6;
    }
    else if(x == '(')
    {
        return 7;
    }
    else
    {
        return 0;
    }
}

int Out_Stack_Pre(char x)
{
    if(x == '+' || x == '-')
    {
        return 2;
    }
    else if(x == '*' || x == '/')
    {
        return 4;
    }
    else if(x == '^')
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

char StackTop(char * &arr , int &top)
{
    return arr[top];
}


void Push(char * & arr , int & top , char x)
{
    top++;
    arr[top] = x;
    cout << "Value Pushed " << x << endl;
}

char Pop(char *& arr , int &top)
{   cout << "Value Poped " << arr[top] << endl; 
    return arr[top--];
}

void convert(string &inf , string &pos)
{
    char* arr = new char [inf.size()];
    int top = -1;
    for(int i =0 ; inf[i] != '\0'; i++)
    {
     if(isOperator(inf[i]))
     {  
        cout << "Operator is =" << inf[i] << endl;
        if(top == -1 && inf[i] != ')') 
        {
            Push(arr , top , inf[i]);
        }
        else if(In_Stack_Pre(inf[i]) > Out_Stack_Pre(StackTop(arr , top)))
        {
            Push(arr , top , inf[i]);
        }
        else
        {
            if(StackTop(arr , top) == '(')
            {
                Pop(arr , top);
            
            }
            else
            {
                pos = pos + Pop(arr , top);
                i--;
            }
            continue;
        }

        
     }
     else
     {
        pos = pos + inf[i];
     }   
    }
    
    while(top!=-1)
    {   cout << "While loop" << endl;
        if(StackTop(arr , top) != '(')
        {
            pos = pos + Pop(arr , top);
        }
        else
        {
            Pop(arr , top);
        }
        
    }
    cout << pos << endl;
}
int main()
{   string inf , pos;
    cout << "Enter the Expression" << endl;
    getline(cin , inf);
    convert(inf , pos);
    return 0;
}