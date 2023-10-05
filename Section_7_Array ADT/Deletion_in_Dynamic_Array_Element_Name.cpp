#include <iostream>
using namespace std;
struct Array 
{
    int *a;         // contains the address of the allocated blocks of the memory in the heap.
    int size , len; // contains total size and no. of elements in the array.
} arr;


void Display ()
{
    cout << "Display all the elements" << endl;
    for(int  i = 0 ; i < arr.len ; i++)
    {
        cout << arr.a[i] << " ";
    }
    cout << endl <<"Elements in the Array = " << arr.len << endl;
    cout << "Size of the array = " << arr.size; 
}
void Deletion(int e)
{   int c=0;
    int index = 0;
    for(int i = 0 ; i < arr.len; i++)
    {
        if(e == arr.a[i])
        {
            index = i;
            c++;
        }
    }
    if(c==1)
    {
        c = arr.a[index];
        for(int  i = index ; i < arr.len -1 ; i++)
        {
            arr.a[i] = arr.a[i+1];
        }
        arr.len--;
        Display();
    }
    else
    {
        cout << "element not found"<< endl;
    }
}

int main ()
{
    cout << "Enter the size of an array" << endl;
    cin >> arr.size;
    arr.a = new int[arr.size];
    arr.len = 0;
    
    cout << "Enter the number of elements to be inserted" << endl;
    int n;
    label:
    cin >> n;
    if(n <= arr.size)
    {   cout << "Enter the elements" << endl;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr.a[i];
            arr.len++;
        }
    }
    else
    {   
        cout << "Enter the correct value" << endl;
        goto label;
    } 
    Display();
    cout << endl << "Enter the element from the above array to be removed" << endl;
    int x; 
    cin >> x;
    Deletion(x);
    return 0;
}