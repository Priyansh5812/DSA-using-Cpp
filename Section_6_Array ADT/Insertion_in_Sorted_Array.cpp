#include <iostream>
using namespace std;

void Display(int arr[]);
void Insertion(int e, int arr[]);
int main ()
{
   int arr[15] = {10,20,30,40,50,60,70,80,90,100};
    cout << "Displaying the array" << endl;
    Display(arr);
    cout << "Enter the element to be inserted in the array" << endl;
    int e; 
    cin >> e;
    Insertion (e , arr);
    cout << "Insertion Successful" << endl;
    cout << "Displaying New Array"  << endl;
    Display(arr); 
    return 0;
}

void Display(int arr[])
{
    for(int i = 0 ;i < 15; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl;
}
void Insertion(int e , int arr[])
{   
    int i = 9;
    while(arr[i] > e)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = e; 
}