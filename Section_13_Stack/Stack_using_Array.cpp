// Implementation of Stack using arrays and Templates
#include <iostream>
using namespace std;
template <class T> class Stack
{
    public:
        int top , size;
        int * arr;
        Stack(int n) : top(-1), size(n)
        {
            arr = new int[size];
        }

        void Push(T x);
        void Pop();
        void Peek(int index);
        void StackTop(); 
        bool is_Empty();
        bool is_Full();
        void Display();


};

template <class T> void Stack <T> :: Push(T x)
{
    if(Stack :: is_Full())
    {
        cout << "Stack OverFlow" << endl;
        cout << top << endl;
    }
    else
    {
        top++;
        arr[top] = x;
        cout << "Value Inserted Successfully" << endl;
    }
}

template <class T> void Stack <T> ::  Pop()
{
    if(Stack :: is_Empty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        int x = arr[top];
        top--;
        cout << "Element deleted : " << x << endl;
    }
}

template <class T> void Stack <T> :: StackTop()
{
    if(Stack :: is_Empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << arr[top] << endl;
    }
}


template <class T> void Stack <T> :: Peek(int index)
{
    if(top == -1)
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    if(index < size && index > -1)
    {
        cout << arr[index];
    }
    else
    {
        cout << "Invalid Index" << endl;
    }
}

template <class T> bool Stack <T> :: is_Empty()
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

template <class T> bool Stack <T> :: is_Full()
{
    if(top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T> void Stack <T> :: Display()
{
    if(Stack :: is_Empty())
    {
        cout << "No elements to Display" << endl;
    }
    else if(top == 0)
    {
        cout << arr[top] << endl;
    }
    else
    {
        for(int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}


int main()
{   int n;
    cout << "Enter the size of the stack" << endl;
    cin >> n;
    Stack <int> s(n); // data type of stack storage can be changed here.
    cout << "*** Operation's Menu ***" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek at certain index" << endl;
    cout << "4. Peek at the top of the stack" << endl;
    cout << "5. Check whether the stack is empty" << endl;
    cout << "6. Check whether the stack is full" << endl;
    cout << "7. Display the Stack " << endl;
    cout << "8. Exit Program" << endl;
    label:
    cout << "Enter your choice" << endl;
    int ch2;
    cin >> ch2;
    switch(ch2)
    {
        case 1:
                int x;
                cout << "Enter an Integer" << endl;
                cin >> x;
                s.Push(x);
                goto label;
                break;
        case 2:
                s.Pop();
                goto label;
                break;
        case 3:
                int index;
                cout << "Enter the desired position" << endl;
                s.Peek(index-1);
                goto label;
                break;
        case 4:
                s.StackTop();
                goto label;
                break;
        case 5:
                if(s.is_Empty())
                {
                    cout << "Stack is empty" << endl;
                }
                else
                {
                    cout << "Stack is not empty" << endl;
                }
                goto label;
                break;
        case 6:
                if(s.is_Full())
                {
                    cout << "Stack is Full" << endl;
                }
                else
                {
                    cout << "Stack is not full" << endl;
                }
                goto label;
                break;
        case 7:
                s.Display();
                goto label;
                break;
        case 8:
                cout <<"Thank you !!!" << endl;
                return 0;
        default:
                cout << "Invalid Choice" << endl;
                goto label;
    };

    return 0;
}