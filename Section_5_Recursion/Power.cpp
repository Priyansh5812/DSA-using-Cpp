#include <iostream>
using namespace std;
int power(int n)
{   static int x = n;
    if(x == 0)
    {
        return 1;
    }
    else
    {   --x;
        return  power(n) *n;
    }
}
int main ()
{   int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << power(n) << endl;

    return 0;
}