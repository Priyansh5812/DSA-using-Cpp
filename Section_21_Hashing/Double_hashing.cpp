#include <iostream>
using namespace std;
class DHashing
{
    private:
        int size;
        int * ht;
    public:
        DHashing(int n) : size(n)
        {
            ht = new int[size] {0};
        }

        bool is_Prime(int n)
        {   int c = 0;
            for(int i = 1 ; i <= n ; i++)
            {
                if(n%i==0)
                {
                    c++;
                }
            }
            if(c==2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    int Nearest_Prime(int n)
    {
        int i = n-1 , j = n+1;
        if(is_Prime(n))
        {
            return n;
        }
        else
        {
        while(i!= 0 && j!= n*10)
        {
            if(is_Prime(i))
            {
                return i;
            }
            else
            {
                i--;
            }

            if(is_Prime(j))
            {
                return j;
            }
            else
            {
                j++;
            }
        }
        }
        
        return 0;
    }

    void Store(int key)
    {
        int h1 = key % 10;
        int h2 = Nearest_Prime(size)-(key % Nearest_Prime(size));
        
        if(ht[h1] == 0)
        {
            ht[h1] = key;
        }
        else
        {
            for(int i = 1;i < i+1; i++)
            {
                int h3 = (h1 + (i*h2)) % 10;
                if(ht[h3]==0)
                {
                    ht[h3] = key;
                    break;
                }
            }
        }
    }

    void Display()
    {
        for(int i = 0; i < size ; i++)
        {
            cout << ht[i] << " ";
        }
        cout << endl;

    }
};
int main()
{   int arr[7] = {26 , 30 , 45 , 23 , 25 , 43 , 74};
    DHashing h(14); // always have size double to the original array.
    for(int i = 0; i < 7 ; i++)
    {
        h.Store(arr[i]); 
    }
    
    h.Display();
    return 0;
}