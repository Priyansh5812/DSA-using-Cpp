#include <iostream>
using namespace std;

class Queue
{
    public:
        int data;
        Queue * next;
};
void Enqueue(int x , Queue* & front , Queue* & rear)
{
    Queue * t = new Queue();
    if(t == NULL)
    {
        cout << "Queue is Full" << endl;
        return;
    }

    t-> data = x;
    t-> next = NULL;
    if(front == NULL)
    {
        front = rear = t;
        cout << "Insertion Sucessfull1" << endl;
    }
    else
    {
        rear -> next = t;
        rear = rear -> next;
        cout << "Insertion Sucessfull2" << endl;
    }
}
int Dequeue(Queue * & front , Queue * & rear)
{
    if(front == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {   if(front == rear)
        {
            rear = NULL;
            delete front;
            front = NULL;
        }
        else
        {
            Queue * temp = front;
            front = front -> next;
            delete temp;
        }
    }
}

void Display(Queue * &front , Queue * &rear)
{
    if(front == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else if(front == rear)
    {   
        cout << front -> data << endl;

    }
    else
    {
        Queue * t = front;
        while(t!= NULL)
        {   
            cout << t-> data << " ";
            t = t-> next;
        }
        cout << endl;
    }
}

int main()
{   Queue * rear , * front;
    rear = front = NULL;
    Enqueue(5 , front , rear);
    Enqueue(10, front ,rear);
    Enqueue(15 , front , rear);
    Enqueue(20, front ,rear);
    Display(front ,rear);
    return 0;
}