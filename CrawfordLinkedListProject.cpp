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
            cout << value << " removed." << endl;
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;
        //Searching for the value inputted in the list
        while (current != nullptr && current ->data != value){
            prev = current;
            current = current->next;
        }

        //If the value is not found in the list
        if(current == nullptr){
            cout << value << " not found in list." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << value << " was removed." << endl;

    }

    //Function to traverse and display the entire linked list
    void display() const {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main(){
    LinkedList<int> list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.display();

    list.remove(20);
    list.display();

    list.remove(40);

    LinkedList<string> stringList;
    stringList.add("Hello");
    stringList.add("World");
    stringList.display();

    stringList.remove("World");
    stringList.display();

    return 0;

}