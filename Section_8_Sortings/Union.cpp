#include <iostream>
#include <vector>
using namespace std;

vector<int> Union(vector<int> arr1 , vector<int> arr2)
{
    vector<int> res;
    int i = 0 , j = 0;
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {   
            if(res.size() == 0)
            {
            res.push_back(arr1[i++]);
            }
            else
            {
                if(res[res.size()-1] == arr1[i])
                {
                    i++;
                }
                else
                {
                     res.push_back(arr1[i++]);
                }
            }
        }

        else if(arr2[j] < arr1[i])
        {   
            if(res.size() == 0)
            {
                res.push_back(arr2[j++]);
            }
            else
            {
                if(res[res.size() -1] == arr2[j])
                {
                    j++;
                }
                else
                {
                    res.push_back(arr2[j++]);
                }
            }
            
        }

        else
        {
            if(res.size()==0)
            {
                res.push_back(arr1[i++]);
                j++;
            }
            else
            {
                if(res[res.size()-1] == arr1[i])
                {
                    i++;
                }
                else
                {
                    res.push_back(arr1[i++]);
                }

                j++;
            }
        }
    
    }

    while(i < arr1.size())
    {
        if(res[res.size()-1] != arr1[i])
        {
            res.push_back(arr1[i]);
        }
        i++;
    }

        while(j < arr2.size())
    {
        if(res[res.size()-1] != arr2[j])
        {
            res.push_back(arr1[j]);
        }
        j++;
    }

    return res;

}


int main()
{   
    vector<int> arr1 = {1 , 2 , 5 , 8};
    vector<int> arr2 = {0 , 1 , 2 , 6};
    vector<int> res = Union(arr1 , arr2);
    vector<int> :: iterator it = res.begin();
    while(it!= res.end())
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}