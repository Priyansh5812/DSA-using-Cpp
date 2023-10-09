#include <iostream>
using namespace std;
struct Array 
{
    int *a;         // contains the address of the allocated blocks of the memory in the heap.
    int size , len; // contains total size and no. of elements in the array.
} arr;

void LinearSearch(int key)
{   int pos = -1;
    for(int  i = 0 ; i < arr.len; i++)
    {
        if(key == arr.a[i])
        {
            pos= i;
        }
    }
    if(pos == -1)
    {
        cout <<"Element not found" << endl;
    }
    else
    {
        cout << "Element found at position " << pos+1 << endl;
    }

}
void Display (Array arr)
{
    cout << "Display all the elements" << endl;
    for(int  i = 0 ; i < arr.len ; i++)
    {
        cout << arr.a[i] << " ";
    }
    cout << endl <<"Elements in the Array = " << arr.len << endl;
    cout << "Size of the array = " << arr.size; 
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
    Display(arr);
    int key ;
    cout << endl <<"Enter the Key element from the above array" << endl;
    cin >> key;
    LinearSearch(key);
    delete [] arr.a;
    
    return 0;

}