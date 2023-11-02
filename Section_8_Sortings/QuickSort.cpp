#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& arr , int l , int h)
{
    int p = arr[l];
    int i = l , j = h;

    while(i < j)
    {
        do
        {
            i++;
        }while(arr[i] <= p);

        do
        {
            j--;
        }while(arr[j] > p);

        if(i < j)
        {
            swap(arr[i] , arr[j]);
        }
        
    }

    swap(arr[j] , arr[l]);
    return j;

}


void QuickSort(vector<int>& arr, int l , int h)
{
    if(l < h)
    {
        int j = Partition(arr , l , h);
        QuickSort(arr , l , j);
        QuickSort(arr , j+1 , h);
    }

}

int main()
{   
    vector<int> arr = {5,8,1,2,1,0,6,2};
    QuickSort(arr , 0 , arr.size());
    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}