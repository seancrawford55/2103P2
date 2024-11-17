#include <iostream>
using namespace std;

//Using a template allows us to add 
//any data type we need to the list
template <typename T>
struct Node{ 
    T data;
    Node* next;

    //Initializes the node with data type
    Node(T val) : data(val), next(nullptr) {}
};

//Class for linked list 
template <typename T>
class LinkedList{
    private:
    Node<T>* head; //Head of list is private to keep it safe

    public:
    LinkedList() : head(nullptr) {} //Initialize the head of linked list
    
    //Deletes entire list
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current ->next;
            delete temp;
        }
    }


    
}

int main(){

    return 0;

}