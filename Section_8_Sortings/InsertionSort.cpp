#include <iostream>
#include <vector>
using namespace std;

void Insertion(vector<int>&arr)
{
    for(int i =1 ; i < arr.size(); i++)
    {   int t = arr[i];
        bool isplaced = false;
        for(int j = i-1 ; j>= 0; j--)
        {
            if(arr[j] > t)
            {
                arr[j+1] = arr[j];
            }

            else
            {
                arr[j+1] = t;
                isplaced = true;
                break;
            }
        }

        if(!isplaced)
        {
            arr[0] = t;
        }
    }
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