#include <iostream>
using namespace std;
int main ()
{   int arr[8] = {2, 8, 1, 3, 6, 7, 5, 4};
int max = arr[0] , min = max;
    for(int i = 0 ; i < 8 ; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Min =" << min << endl << "Max = " << max << endl;
    return 0;
}