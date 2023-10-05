// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// } *first = NULL;

// void create(int arr[] , int n)
// {
//     struct Node *t , *last;
//     first = (struct Node *) malloc (sizeof(struct Node));
//     first->data  =arr[0];
//     first->next = NULL;
//     last = first;

//     for(int i = 1 ; i < n; i++)
//     {
//         t = (struct Node *) malloc (sizeof(struct Node));
//         t ->data = arr[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }

// void display(struct Node *ptr)
// {
//     while(ptr!= NULL)
//     {
//         printf("%d" , ptr->data);
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     int arr[] = {3,5,7,9,1}; // array to store the integers as the data elements in the linked list
//     create(arr , 5);
//     display(first);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node * next;
}*head = NULL;

void Append(struct Node * head , int x)
{
    struct Node *ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = (struct Node *) malloc (sizeof(struct Node));
    ptr = ptr->next;
    ptr->data  =x;
    ptr ->next = NULL;
}

void Display(struct Node * head)
{   printf("from Iterative Method \n");
    struct Node *ptr = head;
    while (ptr!=NULL)
    {
        printf("%d", ptr-> data ,"   " );
        ptr = ptr-> next;
    }
    printf(" \n");
}

void Rec_Display(struct Node * head)
{   
    if(head!=NULL)
    {   
        printf("%d", head -> data, "  ");
        Rec_Display(head-> next);
    }
}

int main()
{   head = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the data element of the head node");
    scanf("%d",& head -> data);
    head->next = NULL;
    int n;
    printf("how many nodes you want to append after the head node ? \n");
    scanf("%d",& n);
    for(int i =1 ;i <= n ; i++)
    {
      Append(head  ,i);
    }
    
    Display(head);
    struct Node * thead  =head; // temporary head
    printf("from Recursive Method\n");
    Rec_Display(thead);
    return 0;
}