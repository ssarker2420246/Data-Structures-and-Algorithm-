#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char val) { data = val; next = nullptr; }
};

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
    Node* head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('c');

    printList(head);

    return 0;
}
