#include <iostream>
#include <vector>
using namespace std;


//First line with an integer n, denoting the number days with the value of the stack
// Next n days, telling the price of the stock on that very day.

int FindmaxProfit(vector<int> arr)
{   
    int min = arr[1];
    int profit = 0;

    for(int i =2 ;i < arr.size(); i++)
    {   
        int diff = arr[i] - min;
        profit = std :: max(profit , diff);
        min = std :: min(arr[i] , min);
    }
    cout << min << endl;
    return profit;
}


int main()
{
    vector<int> arr = {7,1,9,2,11,1,9,2};
    cout << FindmaxProfit(arr);
}