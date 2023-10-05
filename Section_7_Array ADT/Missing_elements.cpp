// using Hash Table
#include <iostream>
using namespace std;
int main ()
{
    int arr[10] = {2,4,8,10,12,14,16,20,22,28};
    int *ptr = new int[29];
    for(int i = 0 ; i < 10 ; i++)
    {   ptr[arr[i]] = 0;
        ptr[arr[i]]++;
    }
    for(int i = 0 ; i < 29 ; i+=2)
    {
        if(ptr[i] != 1)
        {
            cout << "Missing elements = " << i << endl;
        }
    }
    return 0;
    delete [] ptr;
    free(ptr);
}