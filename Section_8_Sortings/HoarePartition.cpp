#include <iostream>
#include <vector>
using namespace std;



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

    return 0;
}