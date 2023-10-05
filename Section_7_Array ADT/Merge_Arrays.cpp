#include <iostream>
using namespace std;
struct Array 
{
    
    int size ,len;
    int arr[];
}A,B;
int main ()
{   A = {5,5,{3,8,16,20,25}};
    B = {5,5,{4,10,12,22,23}};
    int C[10];
    int i =0 , j = 0 , k = 0;
    while(i < A.len && j < B.len)
    {
        if(A.arr[i] < B.arr[j])
        {
            C[k] = A.arr[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B.arr[j];
            j++;
            k++;
        }
    }
    int q=0;
    while(q < 10)
    {
        cout << C[q] << " ";
        q++;
    }
    cout << endl;

    return 0;
}