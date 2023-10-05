#include <iostream>
using namespace std;
int sum(int n)
{   if(n>0)
    {
        return sum(n-1)+n;
    }
    else
    {
        return 0;       
    }

    
}
int main()
{   int n;
    cout << "Enter the number" << endl;
    cin >> n;
    cout << sum(n)<< endl;
    return 0;
}