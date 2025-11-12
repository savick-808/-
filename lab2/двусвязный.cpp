#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

class DoubleLinkedList {
private:
    Node *head;
    Node *tail;
public:
    DoubleLinkedList() : head(NULL), tail(NULL) {}

    void insertAtEnd(int val) {
        Node *newNode = new Node;
        newNode->value = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void traverseForward() {
        Node *current = head;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};