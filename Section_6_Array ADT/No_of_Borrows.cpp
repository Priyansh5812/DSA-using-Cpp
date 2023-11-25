#include <iostream>
#include<string.h>
#include <algorithm>
using namespace std;

int Borrows(string& a , string& b)
{   
    int c = 0;
    if(stoi(a) < stoi(b))
    {   
        cout << "Not Possible"<< endl;
        return -1;
    }

    int i = a.size()-1;
    int j = b.size()-1;
    while(i != -1)
    {
        if(a[i] < b[j]) // no borrow required
        {
            a[i-1] = (char) (stoi(to_string(a[i-1]))-1);
            c++;
        }
        i--;
        j--;

    }

    return c;

}


int main()
{   
    string a , b;
    cout << "Enter the nos" << endl;
    cin >> a >> b;
    cout << Borrows(a,b) << endl;
    cout << a << endl << b;
    return 0;
}