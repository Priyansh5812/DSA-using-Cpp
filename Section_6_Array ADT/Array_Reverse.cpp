#include <iostream>
using namespace std;
int main ()
{   int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << "Before Reversing" << endl;
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] << " ";
    }
    
    for(int i = 0 , j = 9; i <=j ; i++ , j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
     cout <<endl << "After Reversing" << endl;

    for(int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}