#include <iostream>
#include <vector>
using namespace std;


void Partition(vector<int>& arr , int l , int h , int k)
{

    vector<int> temp;

    for(int i =0 ;i < h ; i++)
    {
        if(arr[i] < arr[k])
        {
            temp.push_back(arr[i]);
        }
    }

    temp.push_back(arr[k]);

    for(int i =0 ;i < h ; i++)
    {
        if(arr[i] > arr[k])
        {
            temp.push_back(arr[i]);
        }
    }

    arr = temp;

}

int main()
{   //Inefficient, cannot work with arrays with duplicate elements
    vector<int> arr = {5,8,1,2,-1,0,6,3};
    int k = 3;
    Partition(arr , 0 , arr.size(), k);
    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}