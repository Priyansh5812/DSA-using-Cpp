#include <iostream>
#include <vector>
using namespace std;

void GetSubsets(vector <int> arr , int n , vector <vector <int>>& res , vector <int> temp , int &c , int req)
{
    if(n == arr.size()-1)
    {   int sum = 0;
        for(auto i : temp)
        {
            sum += i;
        }
        if(sum == req)
        {
            c++;
            res.push_back(temp);
        }
    }
    else
    {
        GetSubsets(arr , n+1 , res , temp , c , req);
        temp.push_back(arr[n+1]);
        GetSubsets(arr , n+1 , res , temp, c , req);
    }
}

int main()
{   vector<int> arr = {10 , 20 , 15};
    vector<vector<int>> subsets = {};
    vector<int> temp;
    int c = 0;
    GetSubsets(arr , -1 , subsets,temp,c, 0);
    cout << "Total Count : " << c << endl;

    if(subsets.size() == 0)
    {
        cout << "There are no subsets" << endl;
        return 0;
    }

    cout << "The Subsets are : " << endl;
    for(auto i : subsets)
    {   cout << "{ " ;
        for(auto j : i)
        {
            cout << j << " " ;
        }
        cout << "}" << endl;
    }
    return 0;
}