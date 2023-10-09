#include <iostream>
#include <windows.h>
using namespace std;
struct Array 
{
    int *a;         // contains the address of the allocated blocks of the memory in the heap.
    int size , len; // contains total size and no. of elements in the array.
} arr;

int com = 0;

int LinearSearch(int key)
{   int pos = -1;
    for(int  i = 0 ; i < arr.len; i++)
    {   com++;
        if(key == arr.a[i])
        {   
            pos = i;
            break;
        }
    }
    return pos;

}

void Display ()
{
    
    for(int  i = 0 ; i < arr.len ; i++)
    {
        cout << arr.a[i] << " ";
    }
    
}


void swap(int index)  // Move to Head/Front Technique
{
    int temp = arr.a[index];
    arr.a[index] = arr.a[0];
    arr.a[0] = temp;
    
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
    cout << "Display all the elements" << endl; 
    Display();
    cout << endl <<"Elements in the Array = " << arr.len << endl;
    cout << "Size of the array = " << arr.size; 
    int key ;
    label1:
    com = 0;
    cout << endl << "Enter the Key element from the above array" << endl;
    cin >> key;
    int in = LinearSearch(key);
    if(in == -1)
    {
        cout <<"Element not found" << endl;
    }
    else
    {
        cout << "Element found at Index " << in << endl << " and at position " << in+1 << endl;
        cout << "Total Comparisons made = " << com << endl;
        swap(in);
        cout << "New Optimized Array" << endl;
        Display();
    }


    char ch;
    cout << endl << "Retry ? (y/n)" << endl;
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
    {
        goto label1;
    }


    delete [] arr.a;  
    return 0;
}