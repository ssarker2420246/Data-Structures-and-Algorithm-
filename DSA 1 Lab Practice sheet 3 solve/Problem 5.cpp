#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

void searchList(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Yes" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "No" << endl;
}

int main() {
    Node* head = new Node(8);
    head->next = new Node(3);
    head->next->next = new Node(12);
    head->next->next->next = new Node(5);

    searchList(head, 12);

    return 0;
}
