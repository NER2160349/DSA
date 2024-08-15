//Insert a node at the beginning/end and delete
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node with a given value
    void deleteNode(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Print the linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
int main() {
    LinkedList list;

    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    list.printList();  // Expected: 1 -> 2 -> 3 -> nullptr

    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.printList();  // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    list.deleteNode(3);
    list.printList();  // Expected: 1 -> 2 -> 4 -> 5 -> nullptr

    list.deleteNode(1);
    list.printList();  // Expected: 2 -> 4 -> 5 -> nullptr

    return 0;
}

