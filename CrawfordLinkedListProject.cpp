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
    template <typename T>
    LinkedList<T> list;
    //Prompt the user to choose to add, remove, or display
    cout << "Enter 1 for Add to list" << endl;
    cout << "Enter 2 for remove from list" << endl;
    cout << "Enter 3 to display list" << endl;
    int input;
    cin >> input;
    switch (input)
    {
    case 1: //Call add element when 1 is inputted
        cout << "What value would you like to add?" << endl;
        T input2;
        list.add(cin >> input2);
        break;
    case 2: //Call remove element when 2 is inputted
        if(list.head != nullptr){
            cout << "The list is empty. Cannot remove elements" << endl;
        } else {
            cout << "Which value would you like to remove?" << endl;
            cin >> T input3;
            list.remove(input3);
        }
    case 3: //Call the display when 3 is inputted
        list.display();

    default:
        break;
    }
    

    return 0;

}