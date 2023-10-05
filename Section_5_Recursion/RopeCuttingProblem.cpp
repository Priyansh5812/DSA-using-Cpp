#include <iostream>
#include <vector>
using namespace std;

int cutRope(int n , vector<int> arr ,int l)
{
    vector<int> res;
    
    if(n < 0)
    {
        return -1;
    }
    if(n == 0)
    {
        return l;
    }
    else
    {
        l++;
        for(int i =0 ;i < arr.size(); i++)
        {
            res.push_back(cutRope(n-arr[i], arr , l));
        } 
    }

    //getting max
    int max = res[0];
    for(auto i : res)
    {
        max = (max < i)?(i):(max);
    }
    cout << "N = " << n << " max = " << max << endl; 
    return max;

    
}

int main()
{   
    vector<int> arr = {5,5,5};
    cout << "Final: " << cutRope(5 , arr , 0) << endl;
    return 0;
}