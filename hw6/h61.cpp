// Implement the List class to represent a singly linked list. 
// Implement the Node struct to represent the nodes of a singly linked list as a private nested struct within the List class.
// Implement one field of type int in the Node struct to store the value of the current list node and one field of type Node * to store the address of the next list node.
// Implement two private fields of type Node * in the List class to store the addresses of the first and last list nodes. 
// Do not create fields to store the current list size or user-defined constructors in the List class.
// Implement the public member function empty in the List class to check whether there is at least one node in the list. 
// In the List class, implement the public member function show to print the values ​​of all current nodes in the list to the standard character output stream std::cout. 
// In the List class, implement the public member functions push_front and push_back to insert new nodes with user-defined values ​​to the beginning and end of the list, respectively. Use the new operator to dynamically allocate memory.
// In the List class, implement the public member functions pop_front and pop_back to remove nodes from the beginning and end of the list, respectively. Use the delete operator to free memory.
// Implement a custom destructor in the List class that correctly frees the memory allocated when creating list nodes.
// Perform full testing for all implemented member functions of the List class.

#include<iostream>
class List
{
    private:
        struct node
        {
            int value;
            node* next;
        };
        
        node* head= nullptr;
        node* tail= nullptr;
    public:

        bool empty() const
        {
            return head == nullptr;
        }
        
        void show() const
        {
            node* current=head;
            while(current!= nullptr)
            {
                std::cout<<current-> value<<" ";
                current= current-> next;
            }
        }

        void push_front(int value)
        {
            node* temp = new node;
            temp-> value = value ;
            temp-> next=head;
            head= temp;

            if (tail== nullptr)
                tail =temp;
        }
        void push_back(int value)
        {
            node* temp = new node;
            temp-> value = value ;
            temp-> next=nullptr;


            if (tail !=nullptr)
            {   
                tail-> next=temp;
                tail=temp;
            }
            else
            {
                head=tail=temp;
            }
        }
        void pop_front() 
        {
            if(empty())
            {
                std::cout<<"The list is already empty.\n";
                return;
            }
            else if (head== tail)
            {
                delete head;
                head =nullptr;
                tail =nullptr;
            }
            else
            {
                node* temp =head;
                head = head ->next;
                delete temp;
            }
        }
        void pop_back() 
        {
            if(empty())
            {
                std::cout<<"The list is already empty.\n";
                return;
            }
            else if (head== tail)
            {
                delete head;
                head =nullptr;
                tail =nullptr;
            }
            else
            {
                node* temp =head;
                while(temp->next!=tail)
                {
                    temp = temp->next;
                }
                delete tail;
                tail=temp;
                tail-> next=nullptr;
            }
        }
        ~List()
        {
            node* temp;
            while (head != nullptr)
            {
                temp=head;
                head=head->next;
                delete temp;
            }
            tail= nullptr;
        }
};
int main()
{ 
    List list_1;
    std::cout<< "Is the list empty?";
    std::cout<< (list_1.empty()? "Yes": "No")<<'\n';

    list_1.push_back(26);
    list_1.push_front(10);
    list_1.push_back(20);
    list_1.push_front(05);

    std::cout<< "The list:"<<'\n';
    list_1.show();
    std::cout<<'\n';

    list_1.pop_front();
    std::cout<< "The list after remove ele from the front:"<<'\n';
    list_1.show();
    std::cout<<'\n';

    list_1.pop_back();
    std::cout<< "The list after remove ele from the back:"<<'\n';
    list_1.show();
    std::cout<<'\n';
    std::cout<< "Is the list empty?"<<'\n';
    std::cout<< (list_1.empty()? "Yes": "No")<<'\n';

    
    list_1.pop_back();
    list_1.pop_front();
    std::cout<< "The list after remove all elements:"<<'\n';
    list_1.show();
    std::cout<< "Is the list empty?"<<'\n';
    std::cout<< (list_1.empty()? "Yes": "No")<<'\n';
    return 0;
}
