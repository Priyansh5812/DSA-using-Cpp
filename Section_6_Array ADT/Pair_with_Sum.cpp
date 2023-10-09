#include <iostream>
using namespace std;
int main ()
{
    int arr[10] = {6,3,8,10,16,7,5,2,9,14};
    cout << "Enter the target Sum" << endl;
    int sum;
    cin >> sum;
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j =i+1 ; j < 10 ; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                cout << "Pair is " << arr[i] << " and " << arr[j] << endl;
            }
        }
    } 
}
// complexity = O(n2).