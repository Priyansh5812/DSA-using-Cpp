#include <iostream>
#include <vector>
namespace Mine
{
struct Res
{
    bool res;
    int ind;
};
// checking whether the array is sorted or not
bool IsSorted (std :: vector <int> & arr)
{
    if(arr.size() == 1)
    {
        return true;
    }
    
    std :: vector <int> :: iterator it , it1;


    for(it = arr.begin(), it1 = arr.begin()+1 ; it1 != arr.end(); it++ , it1++)
    {
        if(*it > *it1)
        {
            return false; 
        }

    }

    return true;

}
// iterative version of binary Search
Res BinarySearch_Itr(std :: vector <int> &arr , int x)
{
    Res res;
    res.res = false;
    res.ind = -1;
    
    int l = 0;
    int h = arr.size()-1;

    while(l <= h)
    {
        int mid = (l+h)/2;
        //std :: cout << mid <<  " " << arr[mid] << std :: endl;
        if(arr[mid] == x)
        {
            res.res = true;
            res.ind = mid;
            return res;
        }
        else
        {
            if(arr[mid] < x)
            {
                l = mid+1;
            }
            else
            {
                h = mid - 1;
            }
        }

    }
    return res;

}
// Recursive version of Binary Search
Res BinarySearch_Rec(std :: vector<int> &arr , int l , int h , int x)
{
    if(l > h) // base case
    {
        return {false , -1};
    }
    else
    {
        int mid  = (l+h)/2;
        if(arr[mid] == x)
        {
            return {true , mid};
        }
        
        return BinarySearch_Rec(arr, 
        (arr[mid] < x) ? (mid + 1):(l),
        (arr[mid] < x) ? (h):(mid - 1),
        x);

    }
}
};
int main()
{   
    std :: vector<int> arr = {2,4,6,8,10,13};

    if(Mine :: IsSorted(arr))
    {
        Mine :: Res r = Mine :: BinarySearch_Rec(arr , 0 , arr.size() -1 , 13);
        
        std :: cout << r.res << std :: endl << r.ind << std :: endl;
    }
    else
    {
        std :: cout << "Array not sorted" << std :: endl;
    }

    return 0;
}