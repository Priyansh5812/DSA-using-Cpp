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
        arr = new Element[noe] ;
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


Matrix * Add(Matrix *m1 , Matrix *m2)
{
    if(  (m1->m != m2->m) || (m1->n != m2->n) )
    {   
    return NULL;
    }
    Matrix * m3  =new Matrix(m1->m , m1->n , m1->ne + m2->ne);
    int i = 0 , j = 0 , k = 0;
    while(i < m1 -> ne && j < m2 -> ne)
    {
        if(m1->arr[i].i < m2->arr[j].i)
        {
            m3->arr[k++] = m1 -> arr[i++];
        }
        else if(m1->arr[i].i > m2->arr[j].i)
        {
            m3->arr[k++] = m2 -> arr[j++];
        }
        else
        {
            if(m1->arr[i].j < m2->arr[j].j)
            {
                m3->arr[k++] = m1->arr[i++];
            }
            else if(m1->arr[i].j > m2->arr[j].j)
            {
                m3->arr[k++] = m2->arr[j++];
            }
            else
            {
                m3->arr[k] = m2->arr[j++];
                m3->arr[k++].e += m1->arr[i++].e;
            }
        }
    }
    if(m1->ne > m2->ne)
    {
      while(i < m1->ne)
      {
        m3->arr[k++] = m1->arr[i++];
      }
    }
    else if(m1 -> ne  < m2-> ne)
    {
        while(j < m2->ne)
        {
            m3->arr[k++] = m2->arr[j++];
        }
    }
    return m3;
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
    cout <<endl <<  "Sparse Matrix Representation" << endl;
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
cout << "Enter rows , columns and no. of non-zero elements of First matrix" << endl;
cin >> a >> b >> c;
Matrix s1(a , b , c);
Create(&s1);
cout << "Enter rows , columns and no. of non-zero elements of Second matrix" << endl;
cin >> a >> b >> c;
Matrix s2(a , b , c);
Create(&s2);
Matrix* sum =  Add(&s1 , &s2);
Display(&s1);
Display(&s2);
Display(sum);
}