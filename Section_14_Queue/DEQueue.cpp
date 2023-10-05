#include <iostream>
using namespace std;

class Queue
{
    public:
        int front , rear , size;
        int * arr;

        Queue(int n) : front(-1) , rear(-1) , size(n)
        {
            arr = new int[size];
        }
    void Enqueue_front(int x)
    {
        if(isFrontFull())
        {
            cout << "Queue Full on front side" << endl;
        }
        else
        {
            arr[front] = x;
            front --;
        }
    }

    void Enqueue_rear(int x)
    {
        if(isRearFull())
        {
            cout << "Queue Full on rear side" << endl;
        }
        else
        {
            arr[++rear] = x;
        }
    }




    void Dequeue_front()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {    
            front++;
            cout << "Value Dequed " << arr[front] << endl;
        }
    }

    int Dequeue_rear()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            rear--;
        }
    }


    bool isEmpty()
    {
        if(front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFrontFull()
    {
        if(front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isRearFull()
    {
        if(rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Display()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            for(int temp = front+1 ; temp <= rear ; temp++)
            {
                cout << arr[temp] << " ";
            }
            cout << endl;
        }

    }

};

int main()
{   int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    Queue * q = new Queue(n);
    q->Enqueue_rear(5);
    q->Enqueue_rear(10);
    q->Enqueue_rear(15);
    q->Enqueue_rear(20);
    q->Display();
    q->Dequeue_front();
    q->Display();
    return 0;
}
