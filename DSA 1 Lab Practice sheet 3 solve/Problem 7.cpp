#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
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
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);

    head = insertAtEnd(head, 44);
    printList(head);

    return 0;
}
