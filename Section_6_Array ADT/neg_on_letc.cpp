#include <iostream>
using namespace std;
void Display(int arr[]);
void Swap(int arr[] , int i , int j);
int main ()
{
    int arr[10] = {-1,2,-3,4,-5,6,-7,8,-9,10};
    cout << "Displaying the elements" << endl;
    Display(arr);
    cout << "Arranging elements" << endl;
    int i,j;
    while(i<j)
    {
        while(arr[i] < 0) 
        {
            i++;
        }
        while (arr[j] >= 0)
        {
            j--;
        }
        if(i < j)
        {
        Swap(arr , i , j);
        }
    }
    Display(arr);
}
void Display(int arr[])
{
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
} 

void Swap(int arr[] , int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
