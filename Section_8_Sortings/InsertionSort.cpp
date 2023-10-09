#include <iostream>
#include <vector>
using namespace std;

void Insertion(vector<int>&arr)
{
    
}


int main()
{   
    vector<int>arr = {5,8,1,2,1,0,6,2};
    Insertion(arr);
    vector <int> :: iterator it = arr.begin();
    while(it != arr.end())
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}