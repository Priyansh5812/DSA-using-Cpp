#include <iostream>
#include <array>
using namespace std;

void insertion(int*arr , int n)
{
    for(int i =0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
}
void Display(int* arr , int n)
{
    cout << "Displaying all the elements in the array" << endl;
    for(int i =0 ; i < n ; i++)
    {
        cout <<  arr[i]  << endl;
    }
}
int main()
{   
    
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements in the array" << endl;
    insertion(arr , n);
    Display(arr , n);
    return 0;
}