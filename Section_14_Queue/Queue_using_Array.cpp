#include <iostream>
using namespace std;
template <class T>
class Queue
{
    public:
        int front , rear , size;
        T * arr;
        Queue(int n) : front(-1) , rear(-1) , size(n)
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
                rear++;
                arr[rear] = x;
            }
        }

        void Dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {   cout << "Value Dequeued " << arr[front+1] << endl;
                front++;
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
            if(rear == size -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }




        T QueueFront()
        {
            return arr[front+1];
        }

        T QueueRear()
        {
            return arr[rear];
        }

        void Display()
        {
            for(int i = front+1; i <= rear; i++)
            {
                cout << arr[i] << " "; 
            }
            cout << endl;
        }
};

int main()
{   int n;
    cout << "Enter the size of Queue" << endl;
    cin >> n;
    Queue <int> q(n);
    //Queue <int>* qe = new Queue <int> (n); 
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.Display();
    q.Dequeue();
    q.Display();
    return 0;
}