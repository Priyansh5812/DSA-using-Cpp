#include <iostream>
#include <vector>
#include "IndexOfFirstOccuring.cpp"
#include "IndexOflastOccuring.cpp"



int GetCount(std :: vector <int> arr , int e) 
{   

    int lastIndex = GetLastOccur(arr , 0 , arr.size()-1 , e);
    int firstIndex = GetFirstOccur(arr , 0 , arr.size()-1 , e);
    return (firstIndex == -1)?(0):((lastIndex-firstIndex) + 1);
}


int main()
{   
    std :: vector<int> arr ={1 ,10 ,10, 10 , 20 , 20 , 30 , 30 , 30 , 40};
    std :: cout << GetCount(arr , 20) << std :: endl;
    return 0;
}