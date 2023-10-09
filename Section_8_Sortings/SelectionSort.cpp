#include <iostream>
#include <vector>
using namespace std;

void Selection(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {    
        int min = i;
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[min] , arr[i]);
    }
}

int main()
{   
    vector<int> arr = {5,8,1,2,1,0,6,2};
    Selection(arr);
    vector <int> :: iterator it = arr.begin();
    while(it != arr.end())
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}