// Enhance your previous implementation of the class List from HW 6 using class templates.

#include<iostream>

template<typename T>
class List
{
    private:
        struct node
        {
            T value;
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

        void push_front(const T& value)
        {
            node* temp = new node;
            temp-> value = value ;
            temp-> next=head;
            head= temp;

            if (tail== nullptr)
                tail =temp;
        }
        void push_back(const T& value)
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
    List<int> list_1;
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