#include <iostream>
#include <vector>
using namespace std;

<<<<<<< HEAD
int main()
{   /*
        Partition metjod which is generally used in Quick Sort.
    */

   vector<int>arr = {5,8,1,2,1,0,6,2};
   

=======

void Partition(vector<int>& arr , int l , int h)
{

    int i = l;
    int j = h;
    int pivot = arr[l];
    while(i<j)
    {
        do
        {
            i++;
        } while(arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);
        
        if(i < j)
        {
            swap(arr[i] ,arr[j]);
        }

    }
    swap(arr[j] , arr[l]);
}


int main()
{   
    vector <int> arr = {5,8,1,2,1,0,6,2};
    Partition(arr , 0 , arr.size());
    for(auto i : arr)
    {
        cout << i << " ";
    }
>>>>>>> 3c6c29f822aa4dcc14f2aa5f7d96cb646011fa1d
    return 0;
}