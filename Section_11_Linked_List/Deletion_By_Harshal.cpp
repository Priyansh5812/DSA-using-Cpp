#include <iostream>
using namespace std;
 
 
class Node
{
public:
  int data;
  Node *next;
};
 
 
void Append (Node * head, int n)
{
  Node *ptr = head;
  for (int i = 1; i < n; i++)
    {
      ptr->next = new Node;
      ptr = ptr->next;
      cout << "Enter the data element" << endl;
      cin >> ptr->data;
      ptr->next = NULL;
}} 
 
 
void DeleteOnlyIfAtStart (Node * &head, int x)
{
  Node *ptr = NULL;
  if(head==NULL)
  {
      return;
  }
  if (head->data == x)
    {
      ptr = head;
      head = head->next;
      cout << ptr->data << " Value deleted sucessfully" << endl;
      free (ptr);
    }
    else
    {
      ptr =head ;
      Node *q = ptr , *temp;
    while(ptr!=NULL)
    {
        if(ptr-> data == x)
        {
            q -> next = ptr -> next;
            Node * temp = ptr;
            ptr = ptr -> next;
            delete temp;
            //free(temp);
            break;
        }
        q = ptr;
        ptr = ptr-> next;
    }
    }
}
 
void DeleteOnlyIfAtStartUsingDoublepointer(Node **headp, int x){
    
    if(*headp==NULL){
        return;
    }
     Node *ptr = NULL;
    if(  (*headp)->data ==x  ){
        
      ptr = (*headp);
      (*headp) = (*headp)->next;
      cout << ptr->data << " Value deleted sucessfully" << endl;
      free (ptr);
        
    }
    
    
    
    
    
}
 
 
 
void
Display (Node * head)
{
  Node *ptr = head;
  while (ptr != NULL)
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  cout << endl;
}
 
 
 
int main ()
{
  Node *head;
  Node *ptr;
  int n, d;
  cout << "Enter the total no. of nodes to be created" << endl;
  cin >> n; //assuming n>=1
  
  head = new Node;
  cout << "Enter the data element of the head node" << endl;
  cin >> head->data;
  head->next = NULL;
  Append (head, n);
  Display (head);
  cout << "Enter the data element to be deleted (it will be deleted only if it is at first location )" << endl;
  cin >> d;
  DeleteOnlyIfAtStart(head, d);
//  DeleteOnlyIfAtStartUsingDoublepointer(&head,d);
  Display (head);
}