// Find the index of First occurence in Sorted Array
#include <iostream>
#include <vector>
// #include "BinarySearch.cpp"
// using namespace Mine;



int GetFirstOccur(std :: vector <int> arr , int l , int h,int e)
{   
    #pragma region  OldCode
    // int res = BinarySearch(arr , 0 , arr.size()-1 , e);
    // if(res == -1)
    // {   
    //     std :: cout << "Value does not exists" << std :: endl;
    //     return res;
    // }

    // if(res == 0)
    // {
    //     return res;
    // }

    // while(arr[res-1] == arr[res]  && res != 0)
    // {   
    //     res = BinarySearch(arr , 0 , res-1 , e);
    //     std :: cout << "Checker : " << res << std :: endl;
    // }
    // return res;
    #pragma endregion  oldCode

    if(l > h)
    {
        return -1;
    }

    int mid = (l + h)/2;

    if(arr[mid] > e)
    {
        return GetFirstOccur(arr , l , mid-1, e);
    }

    else if(arr[mid] < e)
    {
        return GetFirstOccur(arr, mid+1 , h , e);
    }

    else 
    {
            if(mid == 0 || arr[mid-1] != arr[mid])
            {
                return mid;
            }
            else
            {
                return GetFirstOccur(arr , l , mid-1, e);
            }

    }
    
}




// int main()
// {   
//     std :: vector<int> arr ={1 ,10 ,10, 10 , 20 , 20 , 30 , 30 , 30 , 40};

//     if(Mine :: IsSorted(arr))
//     {
//         std :: cout << GetFirstOccur(arr , 0 , arr.size()-1, 20) << std :: endl;
//     }

//     return 0;
// }
