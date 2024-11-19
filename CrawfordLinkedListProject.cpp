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
    Node<T>* head; //Head of list pointer

    public:
    LinkedList() : head(nullptr) {}
    
    //Deletes entire list
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current ->next;
            delete temp;
        }
    }

    //Function to add a Node to the end of the list
    void add(T value){
        Node<T>* newNode = new Node<T>(value);

        if(!head){
            head = newNode; //When the list is empty adds the node at the head
        } else {
            Node<T>* temp = head;
            while (temp ->next){
                temp = temp->next; //Move to the last node 
            }
            temp->next = newNode; //Link to the new node
        }
    }

    //Function to remove a Node with a specific value
    void remove(T value){
        if (!head) return; //When the list is empty this function does nothing

        //Edge case for when head node holds data
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

    }
};

int main(){

    return 0;

}