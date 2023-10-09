#include <iostream>
using namespace std;
int main ()
{   int c = 0;
    int arr[10] = {10,20,30,39,50,60,70,80,90,100};
    for(int i = 1 ; i < 10 ; i++)
    {
        if(arr[i-1] > arr[i])
        {
            c++;
            break;
        }
    }
    if(c!=0)
    {
        cout << "Array is not Sorted" << endl;
    }
    else
    {
        cout <<"Array is Sorted" << endl;
    }
    return 0;
}