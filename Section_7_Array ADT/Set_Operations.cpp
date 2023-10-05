#include <iostream>
using namespace std;

void Sort(int *arr , int size)
{   int flag = 0;
    for(int i =0; i < size-1; i++)
    {
        for(int j = 0 ; j < size-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            
        }
        if(flag == 0 && i == 0)
        {
            return;
        }
    }
}

int* Union(int * arr1 , int * arr2 , int s1 , int s2)
{  int *arr3 = new int[s1 + s2] {0}; 
   int  i = 0 , j = 0 , c = 0;
   while(i < s1 && j < s2)
   {
     if(arr1[i] < arr2[j])
     {
        arr3[c++] = arr1[i++]; 
     }
     else if(arr2[j] < arr1[i])
     {
        arr3[c++] = arr2[j++];
     }
     else
     {
        arr3[c++] = arr2[j++];
        i++;   
     }
   }
   while(i < s1)
   {
    arr3[c++] = arr1[i++]; 
   }
   while(j < s2)
   {
    arr3[c++] = arr2[j++];
   }
   return arr3;
}

int * Intersection(int * arr1 , int * arr2 , int s1 , int s2)
{
   int *arr3 = new int[s1 + s2] {0}; 
   int  i = 0 , j = 0 , c = 0;
   while(i < s1 && j < s2)
   {
    if(arr1[i] == arr2[j])
     {
        arr3[c++] = arr1[i++];
        j++; 
     }
     else if(arr2[j] < arr1[i])
     {
        j++;
     }
     else
     {
        j++; 
     }

   }
   
   return arr3;
}

int * Difference(int * arr1 , int * arr2 , int s1 , int s2)
{
int *arr3 = new int[s1 + s2] {0}; 
   int  i = 0 , j = 0 , c = 0;
   while(i < s1 && j < s2)
   {
        if(arr1[i] < arr2[j])
        {
            arr3[c++] = arr1[i++];
        }
        else if(arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++; j++;
        }
   }
   while(i < s1)
   {
    arr3[c++] = arr1[i++];
   }
   return arr3;
}

void Display(int * arr , int size)
{
    for(int i =0; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{   int arr1[4] = {9 , 8 , 7 , 4};
    int arr2[4] = {1 , 7 , 6 , 4};
    Sort(arr1 , 4);
    Sort(arr2 , 4);
    Display(arr1 , 4);
    Display(arr2 , 4);
    Display(Union(arr1 , arr2 , 4 , 4) , 8);
    Display(Intersection(arr1 , arr2 , 4 , 4) , 8);
    Display(Difference(arr1 , arr2 , 4 , 4) , 8);
    return 0;
}