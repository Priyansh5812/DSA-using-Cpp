#include <iostream>
#include <vector>
using namespace std;

vector<int> Intersection(vector<int> arr1 , vector<int> arr2)
{
    vector<int> res;
    int i =0 , j = 0;
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {   
            if(res.size() == 0)
            {
                res.push_back(arr1[i++]);
                j++;
                continue;
            }

            if(arr1[i] != res[res.size()-1])
            {
                res.push_back(arr1[i++]);
                j++;
            }
            else
            {
                i++;
                j++;
            }

        }
    }

    return res;

}

int main()
{   
    vector<int> arr1 = {1,1,3,3,3};
    vector<int> arr2 = {1,1,1,1,3,5,7};
    vector<int> res = Intersection(arr1 , arr2);
    vector<int> :: iterator it = res.begin();
    while(it!= res.end())
    {
        cout << *it <<" ";
        it++;
    }
    return 0;
}