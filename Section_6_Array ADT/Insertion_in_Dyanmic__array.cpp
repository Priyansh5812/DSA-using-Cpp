#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size , len;
}arr;

void Display()
{
    for(int i = 0 ; i < arr.len ; i++)
    {
        cout << arr.A[i]<<" ";
    }
    cout << endl;
}


void Insertion(int index , int x)
{   index--;
    if(arr.len == arr.size)
    {
        cout << "Array is Full Cannot insert";
    }
    else
    {
    for(int i = arr.len ; i > index ; i--)
    {
        arr.A[i] = arr.A[i-1];
    }
    arr.A[index] = x;
    arr.len++;
    Display();
    }
}


int main ()
{
    cout << "Enter the size of the array" << endl;
    cin >> arr.size;
    arr.A = new int[arr.size];
    cout << "Enter the no. of elements to be inserted" << endl;
    int n;
    label1:
    cin >> n;
    if(n <= arr.size)
    {   cout << "Enter the elements" << endl;
        for(int i = 0 ; i < n ; i++)
        {
        cin >> arr.A[i];
        arr.len++;
        }
    }
    else
    {   cout << "Enter the correct value" << endl;
        goto label1;
    }
    Display();
    int x , index ;
    cout << "Enter the element to insert and the position" << endl;
    cin >> x >> index;
    Insertion(index , x);
    return 0;
}