#include <iostream>
#include <vector>
using namespace std;

void LomutoPartition(vector<int>& arr)
{
    int p = arr[arr.size()-1];
    int j = 0 , i = j-1;
    while(j < arr.size())
    {
        if(arr[j] <= arr[arr.size()-1])
        {   
            i++;
            swap(arr[i] , arr[j]);
        }
        j++;
    }
    swap(arr[i+1] , arr[arr.size()-1]);
}

int main()
{   
    /*
        Lomuto Partition always takes the last element as pivot
        We tend to maintain a window of smaller elements and increase it.
        As soon as we traversed the array, we swap the last element with the element just after the end of the window.
    
    */

    vector<int> arr = {5,8,1,2,1,0,6,2};
    LomutoPartition(arr);
    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}