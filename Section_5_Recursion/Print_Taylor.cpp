#include <iostream>
using namespace std;
 void TaylorP(int x , int n , int lim)
{   
    static int p = 1 , f = 1;
    string r;
    if(n == 0)
    {
        r = "1";
        cout << r;
        TaylorP(x , n+1 , lim);
    }
    else if(n > 0 && n < lim)
    {
        p*=x;
        f*=n;
        string a = to_string(p);
        string b = to_string(f);
        if(n%2==0)
        {
            r = a + "/"+ b;
        }
        else
        {
            r = " + "+ a + "/"+ b +" + ";
        }
        cout << r ;
        TaylorP(x, n+1 , lim); 
    }
    else
    {
        p*=x;
        f*=n;
        string a = to_string(p);
        string b = to_string(f);
        
         if(n%2==0)
        {
            r = a + "/"+ b;
        }
        else
        {
            r = " + "+ a + "/"+ b;
        }
        cout << r ;
    }
    
}
int main ()
{   int a,b;
    cout << "Enter the number and the limit of the Taylor Series" << endl;
    cin >> a >> b;
    if(b==0)
    {   cout << 1;
        return 0;
    }
    else if(a < 0 || b < 0)
    {
        cout << "Invalid Input"<< endl;
        return 0;
    }
    else
    {   TaylorP(a , 0 , b);
        return 0;
    }

    
}