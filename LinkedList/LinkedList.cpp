// C++ Program for Impleneting a LinkedList

#include <iostream>
using namespace std;

// Structure for a node in a Linked List

struct Node {
    int data;
    Node* next;
    <#struct fields#>
};

class LinkedList {
    // Pointer to the first node in the list
    
    Node* head;
    
public:
    // constructor initalizes head to NULL value
    LinkedList(): head(NULL) {}
    
    // function that inserts a node at the beginning
    void insertAtBeginning(int value){
        Node* newNode = new Node(); // new is used to dynammically allocate memory for Node and return a pointer to that memory, newNode holds the address of the newly connected Node Object
        // in python we access the value and next attribute using .val and .next, however in c++ when you have a pointer to an object we use ->, which we uses to access the member property pointed to by newNode
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    // Function to insert a new Node at the end of the linked list
    void insertAtEnd(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        // if the list is empy, update the head to the new node
        if (!head){
            head = newNode;
            return;
        }
        // traverse to the last node
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        // update last node's next to the new node
        temp->next = newNode;
    }
    void insertAtPosition (int value, int position){
        if (position < 1){
            cout << "Position should be greater that 0" << endl;
            return;
        }
        // if position == 1 than the user wants to insert at the beginning of the node, therefore call the insertAtBeginning function
        if(position == 1){
            insertAtBeginning(value);
            return;
        }
        Node* newNode = head;
        newNode->data = value;
        
        Node* temp = head;
        
        // traverse to the node before the desired postion
        for (int i = 1; i < postion - 1 and temp; ++i){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        delete temp; // c++ requires explicit memory maintence. delete pointer as it affects memory
    }
    // function to delete the first node of the Linked List
    void deleteFromBeginning(){
        if(!head){
            cout <<"The list is empty">> endl;
            return;
        }
        Node* temp = head; // creates a temp pointer that points to head
        head = head->next; // move head pointer to the next node (new head after deletion)
        delete temp; // deletes the first node
        
    }
    // function to delete a node at a specific position
    void deleteAtPosition(int position){
        if(position < 1){
            cout << "Position must must be greater or equal to 1.">> endl;
            return;
        }
        if(poistion == 1){
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        for(int i = 1; i < position - 1 and temp;){
            temp = temp->next; // move to one postion before desired position
        }
        if(!temp or not temp->next){
            cout <<"Postion is out of range">> endl;
            return;
        }
       
        
        Node* nodeToDelete = temp->next; // save the node we want to delete
        temp->next = temp->next->next; // update the pointer two times (skipping the node that will be deleted, pointing to the node after deleted one
        delete nodeToDelte; // delete the node
    }
    
    //function to delete from the end of the LinkedList
    void deleteFromEnd(){
        if(!head){
            cout<<"List is Empty"<<endl;
            return;
        }
        // if there is only one Node
        if(not head->next){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        // traverse to the second to last node
        while(temp->next->next){
            temp = temp->next;
        }
        delete temp->next; // delete the last ndoe
        temp->next = NULL; // set the pointer of the new last node to NULL
        
    }
    
    void display(){
        if (!head){
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << end;
    }
    
};

int main(){
    // initialize new linked list
    LinkedList list1;

        // Insert elements at the end
        list1.insertAtEnd(10);
        list1.insertAtEnd(20);

        // Insert element at the beginning
        list1.insertAtBeginning(5);

        // Insert element at a specific position
        list1.insertAtPosition(15, 3);

        cout << "Linked list after insertions: ";
        list1.display();

        // Delete element from the beginning
        list1.deleteFromBeginning();
        cout << "Linked list after deleting from beginning: ";
        list1.display();

        // Delete element from the end
        list1.deleteFromEnd();
        cout << "Linked list after deleting from end: ";
        list1.display();

        // Delete element from a specific position
        list1.deleteFromPosition(2);
        cout << "Linked list after deleting from position 2: ";
        list1.display();

        return 0;
}
