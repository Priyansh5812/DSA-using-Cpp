#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {3,6,8,8,10,12,20,15,15,15};
    int *ptr = new int[20] {0}; // {0} initializes the dynamically allocated array to 0
    for(int i = 0 ; i < 10 ; i++)
    {
        ptr[arr[i]]++;
    }
    for(int i = 0 ; i < 20 ; i++)
    {
        if(ptr[i] > 1)
        {
            cout << "Duplicated Element = " << i << endl;
        }
    }
    delete [] ptr;
    free(ptr);
    return 0;
}