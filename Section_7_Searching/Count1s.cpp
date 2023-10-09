#include <iostream>
#include <vector>
#include "IndexOfFirstOccuring.cpp"


int GetNo_1s(std :: vector <int> arr)
{   
    int ind = GetFirstOccur(arr , 0 , arr.size()-1 , 1);

    return (ind == -1)?(0):(arr.size()-ind);


}


int main()
{
    std :: vector <int> arr = {0,0,0,0,1,1,1,1,1,1,1,1};

    std :: cout << GetNo_1s(arr);


    return 0;
}