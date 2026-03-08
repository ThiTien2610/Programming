// A structure to represent people that will contain basic information and pointers to parents. 
// Implement some instances and show how to set pointers in a proper way

#include <iostream>
#include<string>

struct Person
{
    char name [300];
    int age;
    Person*mom;
    Person*dad;
};

int main()
{
    Person mom = { "Ha", 57, nullptr, nullptr }; 
    Person dad = { "Viet", 55, nullptr,nullptr};
    Person child = { "Tien", 20, nullptr,nullptr};

    child.mom = &mom;
    child.dad = &dad;

    std::cout<< "Child: " <<child.name<< ", age: " << child.age<< '\n';
    if (child.mom != nullptr)
        std::cout<< "Mom: "<< child.mom->name<< ", age: "<< child.mom-> age<< '\n';
    if (child.dad != nullptr)
        std::cout<< "Dad: "<< child.dad->name<< ", age: "<< child.dad-> age<< '\n';
        
    return 0;

}

