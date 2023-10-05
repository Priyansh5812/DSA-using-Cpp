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
void Deletion(int index)
{  index--;
   int x = arr.a[index];
   for(int i = index; i < arr.len-1 ; i++)
   {
       arr.a[i] = arr.a[i+1];
   }
   arr.len--;
   cout << "Deleted Element is : " << x << endl;
   Display();
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
    int i;
    cout << endl <<"Enter the position of the element to remove it" << endl;
    cin >>i;
    Deletion(i);
    return 0;
}