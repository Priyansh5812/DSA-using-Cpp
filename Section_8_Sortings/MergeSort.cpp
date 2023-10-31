#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> & arr , int l , int m , int h)
{   
    int l1 = l , h1 = m;
    int l2 = m+1 , h2 = h;
    vector<int> res;
    while(l1 <= h1 && l2 <= h2)
    {
        if(arr[l1] < arr[l2])
        {
            res.push_back(arr[l1++]);
        }
        else if(arr[l1] > arr[l2])
        {
            res.push_back(arr[l2++]);
        }
        else
        {
            res.push_back(arr[l1++]);
            res.push_back(arr[l2++]);
        }
    }

    while(l1 <= h1)
    {
        res.push_back(arr[l1++]);
    }

    while(l2 <= h2)
    {
        res.push_back(arr[l2++]);
    }

    for(int i = 0 ; i < res.size() ; i++)
    {
        arr[l++] = res[i];
    }
}


void MergeSort(vector<int> &arr , int l ,int h)
{
    if(l<h)
    {   
        int m = (l+h)/2;
        MergeSort(arr, l , m);
        MergeSort(arr, m+1 , h);
        Merge(arr , l , m , h);
    }

}   


int main()
{   
    vector<int> arr = {5,8,1,2,9,0,6,2};
    MergeSort(arr , 0 , arr.size()-1);

    for(int i =0 ;i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}