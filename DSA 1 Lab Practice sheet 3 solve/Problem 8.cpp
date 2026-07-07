#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

void insertAfterValue(Node* head, int target, int newVal) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node* newNode = new Node(newVal);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);

    insertAfterValue(head, 10, 15);
    printList(head);

    return 0;
}
