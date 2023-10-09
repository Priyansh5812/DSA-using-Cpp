#include <iostream>
#include <vector>
using namespace std;


void Bubble(vector<int> &arr)
{
    for(int i = 0 ; i < arr.size(); i++)
    {
        for(int j =0 ; j < arr.size()-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}


int main()
{   

    vector<int> arr = {5,8,1,2,1,0,6,2};
    Bubble(arr);
    vector <int> :: iterator it =arr.begin();
    while(it != arr.end())
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}