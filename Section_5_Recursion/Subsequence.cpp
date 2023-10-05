#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Subsequence(string str , int n, vector<string> & arr, string temp)
{
    if(n == str.length()-1)
    {   
        arr.push_back(temp);
    }
    else
    {
        Subsequence(str , n+1, arr , temp);
        Subsequence(str , n+1, arr , temp+str[n+1]);
    }

}



int main()
{   
    vector<string> arr = {};
    string a;
    Subsequence("ABC" ,-1,arr , a);
    for(int i =0 ;i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total Subsequences : " << arr.size() << endl;
    return 0;
}