#include <iostream>
#include <vector>
using namespace std;

void Arrange(vector<int>& arr)
{
    int z = 0 , o = 0;
    for(auto i : arr)
    {
        switch(i)
        {
            case 0:
                z++;
                break;
            case 1:
                o++;
                break;
        }
    }
    int i = 0;
    while(z != 0 || o != 0)
    {
        if(z!= 0)
        {
            arr[i++]=0;
            z--;
            continue;
        }

        if(o!= 0)
        {
            arr[i++] = 1;
            o--;
            continue;
        }
    }

    while(i < arr.size())
    {
        arr[i++] = 2;
    }

}


int main()
{   
    vector<int> arr ={0, 1, 2, 0, 1, 2};

    Arrange(arr);

    for(auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}