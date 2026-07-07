#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) { data = val; prev = nullptr; next = nullptr; }
};

void printDLL(DNode* head) {
    DNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    DNode* head = new DNode(11);
    DNode* second = new DNode(22);
    DNode* third = new DNode(33);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printDLL(head);

    return 0;
}
