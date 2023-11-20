#include <iostream>
#include <vector>
using namespace std;

//Quick sort using Hoare partition.
// The pivot should be arr[low].

int HoarePartition(vector<int>& arr , int l , int h)
{

    int i = l;
    int j = h;
    int p = arr[l];
    while(i < j)
    {
        
        do
        {
            i++;
        }while (arr[i] < p);
        
        do
        {
            j--;
        } while (arr[j]>p);
        
        if(i < j)
        {
            swap(arr[i] , arr[j]);
        }


    }

    swap(arr[j] , arr[l]);
    return j;

}



void QuickSort(vector<int>& arr , int l , int h)
{
    if(l < h) // There has to be at least 2 elements
    {
        int part = HoarePartition(arr , l , h );
        QuickSort(arr , l , part);
        QuickSort(arr , part+1 , h);
    }
}



int main()
{   
    vector<int>arr = {5,8,1,2,1,0,6,2};

    QuickSort(arr , 0 , arr.size());

    for(auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}