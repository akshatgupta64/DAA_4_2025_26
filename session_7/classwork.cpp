#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;

    Node(int data) {
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtEnd(Node*& head, int val) {
    Node* t = new Node(val);

    if (head == nullptr) {
        head = t;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = t;
    t->prev = temp;
}

void insertAtMid(Node*& head, int value, int pos) {
    Node* t = new Node(value);

    if (pos == 1) {
        t->next = head;
        if (head != nullptr)
            head->prev = t;
        head = t;
        return;
    }

    Node* temp = head;
    while (pos > 2 && temp->next != nullptr) {
        temp = temp->next;
        pos--;
    }

    t->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = t;

    temp->next = t;
    t->prev = temp;
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    Node* temp = head;

    // delete head
    if (head->val == value) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        return;
    }

    while (temp != nullptr) {
        if (temp->val == value) {
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            if (temp->prev != nullptr)
                temp->prev->next = temp->next;

            delete temp;
            return;
        }
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(10);

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtEnd(head, 60);

    deleteNode(head, 50);
    deleteNode(head, 10);

    insertAtMid(head, 90, 1);

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
