#include <iostream>
using namespace std;
int main()
{  int arr[10] = {2,4,6,8,10,12,14,18,20};
   int ft = arr[0], diff = arr[1] - arr[0], pos=-1;
   for(int i = 0 ; i < 10 ; i++)
   {    int a = arr[0] + (i * diff);

       if(a != arr[i])
       {
           pos=i;
           break;
       }
   }
   if(pos == -1)
   {
       cout << "Array is alright" << endl;
   }
   else
   {
       cout << arr[0]+ (pos * diff) << " is missing from the array in index no. " << pos << endl;
   }
    return 0;
}