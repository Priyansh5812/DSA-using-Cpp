#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> & arr , int l , int h)
{
    int i = l;
    int j = h;
    int pivot = arr[l];

    while(i < j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        
        do
        {
            j--;
        } while (arr[j] > pivot);

        if(i < j)
        {
            swap(arr[i] , arr[j]);
        }

    }
    swap(arr[j] , arr[l]);
    return j;
}


void GetKthElement(vector<int>& arr , int l , int h , int k)
{

    if(l < h)
    {
        
    }

}




int main()
{   
    vector<int> arr = {5,8,1,2,0,3,9,8};

    return 0;
}