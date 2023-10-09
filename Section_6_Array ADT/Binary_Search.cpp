#include <iostream>
using namespace std;
int BinarySearch(int l , int h , int key , int arr[]);
void Display(int arr[]);
int com = 0;
int main ()
{
    int arr[15]  = {4,8,10,15,18,21,24,27,29,33,34,37,39,41,43};
    cout << "Displaying Array" << endl;
    Display(arr);
    cout << "Enter the key element to be searched" << endl;
    int n;
    cin >> n;
    int index = BinarySearch(0 , 14 , n , arr);
    if(index == -1)
    {
        cout << "Element not Found" << endl;
        cout << "Total Comparisons Made " << com << endl; 

    }
    else
    {
        cout << "Element Found at Index " << index  << " at position " << index +1 << endl;
        cout << "Total Comparisons Made " << com << endl; 
    }
    return 0;
}


void Display(int arr[])
{
    for(int i = 0 ; i < 15 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int BinarySearch(int l , int h , int key, int arr[])
{
    if(l <= h)
    {   int mid = (l+h)/2;
        if(arr[mid] == key)
        {   
            return mid;
        }
        else if(key < arr[mid])
        {   com++;
            return BinarySearch(l , mid-1 , key , arr);
        }
        else if(key > arr[mid])
        {   com++;
            return BinarySearch(mid+1 , h , key , arr);
        }
    }
    else
    {
        return -1;
    }
}