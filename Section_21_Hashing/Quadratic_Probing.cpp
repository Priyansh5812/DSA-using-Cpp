#include <iostream>
using namespace std;

class Hash
{   public:
    int size;
    int * arr;
    Hash(int n): size(n)
    {arr = new int[n] {0};}
    void Store(int x)
    {   int res_ind = x% 10;
        if(arr[res_ind] == 0)
        {
            arr[res_ind] = x;
        }
        else
        {   int i = 1;
            int res_ind1 = (x + (i*i)) % 10;
            while(res_ind1 != res_ind)
            {
                if(arr[res_ind1] == 0)
                {
                    arr[res_ind1] = x;
                    break;
                }
                i++;
                res_ind1 = (x + (i*i)) % 10;
            }
            
        }
            
    }
    void Display()
    {
        for(int i = 0 ;i < size ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Search(int x)
    {
        int res_ind = x % 10;
        if(arr[res_ind] == x)
        {
            cout << "Value Found" << endl;
            return;
        }
        else
        {   int i = 1;
            int res_ind2 = (x + i) %10;
            while(res_ind2 != res_ind)
            {
                if(arr[res_ind2] == x)
                {
                    cout << "Value Found" << endl;
                    return;
                }
                i++;
                res_ind2 = (x+i) %10;
            }
            cout << "Value Not Found" << endl;
        }
    }
    
};


int main()
{   Hash * p = new Hash(10);
    p-> Store(9);
    p-> Store(19);
    p-> Store(69);
    p-> Store(45);
    p-> Store(21);
    p-> Display();
    p->Search(69);
    return 0;
}