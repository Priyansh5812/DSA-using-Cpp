#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> arr1 , vector<int> arr2)
{
    int l1 = 0 , l2 = 0;
    vector<int> res;
    while(l1 < arr1.size() && l2 <= arr2.size())
    {
        if(arr1[l1] < arr2[l2])
        {
            res.push_back(arr1[l1++]);
        }
        else if(arr1[l1] > arr2[l2])
        {
            res.push_back(arr2[l2++]);
        }
        else
        {
            res.push_back(arr1[l1++]);
            res.push_back(arr2[l2++]);
        }
    }

    while(l1 < arr1.size())
    {
        res.push_back(arr1[l1++]);
    }

    while(l2 < arr2.size())
    {
        res.push_back(arr2[l2++]);
    }

    return res;
}

int main()
{   
    vector<int> arr1 ={1,2,5,8};
    vector<int> arr2 = {0,1,2,6};
    vector <int> res = Merge(arr1 , arr2); 
    for(int i =0 ; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}