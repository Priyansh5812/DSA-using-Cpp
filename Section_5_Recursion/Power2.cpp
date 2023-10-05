#include <iostream>
using namespace std;
int power(int a , int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(a == 0)
    {
        return 0;
    }
    else if(b < 0)
    {
        return 1 / power(a , -1 * b);
    }
    else
    {
        return power(a , --b) * a;
    }
}
int main ()
{   int n , m;
    cout << "Enter the number and its power" << endl;
    cin >> n >> m;
    cout << power(n , m) << endl;
    return 0;
}