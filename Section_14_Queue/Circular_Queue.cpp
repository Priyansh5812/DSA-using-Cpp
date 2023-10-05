#include <iostream>
using namespace std;
template <class T>
class Queue
{
    public:
        int size , rear , front;
        int * arr;


    Queue(int n) : size(n) , front(0) , rear(0)
    {
        arr = new T[size];
    }


    void Enqueue(T x)
    {
        if(isFull())
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            rear = (rear + 1) % size ;
            arr[rear] = x;
        }
    }


    T Dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else 
        {
            int temp = (front + 1) % size;
            front = (front + 1) % size;
            cout << "Value Dequeued " << arr[temp] << endl;
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
    bool isFull()
    {
        if((rear+1)%size == front)
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
            int temp = (front+1) % size;


            while(temp != (rear+1) % size)
            {
                cout << arr[temp] << " ";
                temp = (temp+1) %size;          
            }
            cout <<  endl;
        }
    }

};


int main()
{   
    int n;
    cout << "Enter the size of the Queue" << endl;
    cin >> n;
    Queue <int> *q = new Queue <int> (n+1);   
    q-> Enqueue(5);
    q-> Enqueue(10);
    q-> Enqueue(15);
    q-> Enqueue(20);
    q-> Enqueue(25);
    q-> Enqueue(30);
    q-> Display();
    return 0;
}