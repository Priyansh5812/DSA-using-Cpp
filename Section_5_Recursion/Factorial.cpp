#include <iostream>
using namespace std;
int fact(int n)
{
    if(n > 0)
    {
        return fact(n-1) * n;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n;
    cout << "Enter a number to find its factorial" << endl;
    cin >> n;
    cout << fact(n) <<endl;
    return 0;
}