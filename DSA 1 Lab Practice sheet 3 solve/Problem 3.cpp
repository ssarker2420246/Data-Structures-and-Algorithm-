#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

int countOccurrences(Node* head, int key) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(7);
    head->next->next = new Node(4);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(4);

    cout << countOccurrences(head, 4) << endl;

    return 0;
}
