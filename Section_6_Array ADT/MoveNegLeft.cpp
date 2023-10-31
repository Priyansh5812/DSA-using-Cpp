#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    vector<int> arr = {5,-8,1,-2,-1,0,-6,2};
    int i =0; //finds +ve
    int j = arr.size()-1; // finds -ve
    while(i < j)
    {   //both negative

        if(arr[i] < 0)
        {
            i++;
            continue;
        }

        if(arr[j] >= 0)
        {
            j--;
            continue;
        }


        swap(arr[i++], arr[j--]);
    }

    for(auto i : arr)
    {
        cout << i << " ";
    }


    return 0;
}