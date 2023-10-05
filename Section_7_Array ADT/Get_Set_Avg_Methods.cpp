#include <iostream>
using namespace std;
void Display(int arr[], int len);
int Get(int arr[] , int len, int e);
void Set(int arr[] , int len , int e, int pos);
int Avg(int arr[] , int len);
struct Array
{
    int len , size;
    int arr[];
}A;
int main ()
{   
    A = {6 , 9 ,{1,2,3,4,5,6}};
    cout << "******Main Menu******" << endl;
    cout << "1. Display the Array" << endl << "2. Retrieve an element" << endl << "3. Replace an Element" << endl << "4. Average the Array" << endl << "5. Exit the Program" << endl;
    
    int n;
    label:
    while(n != 5)
    {
    cout << "Enter the choice via Sequence number" << endl;
    cin >> n;
    switch(n)
    {
        case 1 :
        Display(A.arr, A.len);
        break;
        
        case 2:
        cout << "Enter the index of the element from the array" << endl;
        int e;
        cin >> e;
        cout << Get(A.arr , A.len , e) << endl;
        break;

        case 3:
        cout << "Enter the element to replace and the position for replacement" << endl;
        int f, pos;
        cin >> f >> pos;
        Set(A.arr , A.len , f , pos);
        break;

        case 4 :
        cout << Avg(A.arr , A.len);
        break;
        
        case 5:
        cout << "Thank You" << endl;
        return 0;
        
        default:
        cout << "Enter the correct choice" << endl;
    }
    }
}

void Display(int arr[] , int len)
{   cout << "Displaying elements" << endl;
    for(int i = 0; i < len ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int Get(int arr[] , int len, int e)
{
    if(e >= len && e < 0)
    {   cout << "Invalid Index" << endl;
        return -1;
    }
    else
    {
        return arr[e];
    }
}



void Set(int arr[] , int len , int e, int pos)
{
    if(pos >= len && pos < 0)
    {   
        cout << "Invalid index" << endl;
    }
    else
    {
        arr[pos] = e;
        Display(arr, len);
    }


}

int Avg(int arr[] , int len)
{
    int sum = 0;
    for(int i = 0 ; i < len ; i++)
    {
        sum = sum + arr[i];
    }
    return sum/len;
}