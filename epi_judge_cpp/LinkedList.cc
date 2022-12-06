 // this file implements a linked list
 // in order to define a linked list, we must make a class that defines a linked list node

 #include <iostream>

// class members are private by default, which means we cant access them outside the class.
// if we want to access outside of the class we need to use the public access modifier
class Node{
    public:
    int value;
    Node* next; // need to define a node pointer 
};
void printLinkedList(Node* head);

 int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    second->value = 2;
    third->value = 3;

    head->next = second;
    second->next = third;
    third->next = NULL;

    printLinkedList(head);

    return 0;
 }

 void printLinkedList(Node* head){
    while(head != NULL){
        std::cout << head->value << std::endl;
        head = head->next;
    }
 }