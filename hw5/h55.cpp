// A structure to represent the nodes of a singly linked list. 
// Implement a value field and a pointer to the next node in this structure.
// Create a list and implement an algorithm for traversing the list from start to finish

#include<iostream>

struct node
{
    int value;
    node* next;
};

int main()
{
    node *n;
    node *temp;
    node *head;

    n= new node;
    n-> value=1;
    temp=n;
    head=n;

    n= new node;
    n-> value=2;
    temp-> next =n;
    temp= n;

    n= new node;
    n-> value=3;
    temp-> next =n;
    temp= n;

    n= new node;
    n-> value=4;
    temp-> next =n;
    temp= n ;
    
    temp-> next =nullptr;

    std::cout<<"List from the start to finish:";
    node* current=head;
    while(current!= nullptr)
    {
        std::cout<< current-> value<<" ";
        current= current-> next;
    }
    return 0;
}

    
