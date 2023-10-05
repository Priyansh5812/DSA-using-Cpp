#include <iostream>
using namespace std;

int arr[50]; // declaration
int fib(int n)
{
    if(n <=1)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        if(arr[n-2] == -1)
        {
            arr[n-2] = fib(n-2);
        }
        if(arr[n-1] == -1)
        {
            arr[n-1] == fib(n-1);
        }
            arr[n] = arr[n-2] + arr[n-1];
        return arr[n-1] + arr[n-2];
    }
}

int main ()
{   int n;
    cout << "Enter the limit of the fiboncacci series" << endl;
    cin >> n;
    for(int i = 0 ; i < 50 ; i++)
    {
        arr[i] = -1; //initialization
    }
    cout << fib(n) << endl;
    cout << "The fibonacci Series" << endl;
    for(int i = 0;i <= n; i++)
    {   cout << arr[i] << " ";
    }
    return 0;
}
