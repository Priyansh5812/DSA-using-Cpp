// Find the index of First occurence in Sorted Array
#include <iostream>
#include <vector>
#include "BinarySearch.cpp"
using namespace Mine;


int GetLastOccur(std :: vector <int> arr , int l , int h, int e)
{   
    #pragma region oldCode
    /*int res = BinarySearch(arr , 0 , arr.size()-1 , e);
    if(res == -1)
    {   
        std :: cout << "Value does not exists" << std :: endl;
        return res;
    }

    if(res == arr.size()-1)
    {
        return res;
    }

    while(arr[res+1] == arr[res] && res != arr.size()-1)
    {   
        res = BinarySearch(arr , res+1 , arr.size()-1 , e);
        std :: cout << "Checker : " << res << std :: endl;
    }
    return res;*/
    #pragma endregion oldCode

    if(l > h)
    {
        return -1;
    }

    int mid = (l + h)/2;

    if(arr[mid] > e)
    {
        return GetLastOccur(arr , l , mid-1, e);
    }

    else if(arr[mid] < e)
    {
        return GetLastOccur(arr, mid+1 , h , e);
    }

    else 
    {
            if(mid == arr.size()-1 || arr[mid] != arr[mid+1])
            {
                return mid;
            }
            else
            {
                return GetLastOccur(arr , mid+1, arr.size()-1, e);
            }

    }
}




// int main()
// {   
//     std :: vector<int> arr ={1 ,10 ,10, 10 , 20 , 20 , 30 , 30 , 30 , 40};

//     if(Mine :: IsSorted(arr))
//     {
//         std :: cout << GetLastOccur(arr , 0 , arr.size()-1, 30) << std :: endl;
//     }

//     return 0;
// }
