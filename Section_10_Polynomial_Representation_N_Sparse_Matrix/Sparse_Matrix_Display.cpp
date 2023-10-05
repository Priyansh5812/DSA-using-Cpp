#include <iostream>
using namespace std;

class Element
{
  public:
    int i , j , e;  
};

class Matrix
{
    public:
        int m , n , ne;
        Element * arr;
    Matrix(int rows , int cols , int noe): m(rows) , n(cols) , ne(noe)
    {
        arr = new Element[noe];
    }

    
};

void Create(Matrix * m)
{
    for(int  i = 0 ; i < m->ne; i++)
    {
        cout << "Enter the row no." << endl;
        cin >> m->arr[i].i;
        cout << "Enter the column no." << endl;
        cin >> m->arr[i].j;
        cout << "Enter the element" << endl;
        cin >> m->arr[i].e;
    }
}

void Display(Matrix *m)
{   
   cout << "3 Column Representation" << endl;
    for(int i = 0 ; i < m->ne; i++)
    {   
        cout << m->arr[i].i << " ";
        cout << m->arr[i].j << " ";
        cout << m ->arr[i].e << " ";    
    }
    cout << "Sparse Matrix Representation" << endl;
    int c = 0;
    for(int  i =0 ; i < m->m; i++)
    {
        for(int j =0; j < m->n ; j++)
        {
            if(i == m->arr[c].i && j == m->arr[c].j)
            {
                cout << m->arr[c].e << " ";
                c++;
            }

            else
            {
                cout << 0 << " ";
            }
        
        }
        
        cout << endl;
    }
}


int main()
{
int a , b , c;
cout << "Enter rows , columns and no. of non-zero elements" << endl;
cin >> a >> b >> c;
Matrix s(a , b , c);
Create(&s);
Display(&s);
}