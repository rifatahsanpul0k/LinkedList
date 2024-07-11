#include<bits/stdc++.h>
using namespace std;

struct List {
    int data;
    List* next;
};
typedef List Node;
Node* start = nullptr;

void menu() {
    cout << "\n1. Insert\n2. Delete\n3. Exit\n";
}

void display() {
    Node* temp = start;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertion(int item) {
    Node* temp, * newNode;
    newNode = new Node();
    newNode->data = item;
    newNode->next = nullptr;

    if (start == nullptr || item <= start->data) {
        newNode->next = start;
        start = newNode;
    } else {
        temp = start;
        while (temp->next != nullptr && temp->next->data < item) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deletion(int item) {
    Node* temp = start, * prev = nullptr;

    if (start == nullptr) return;

    if (start->data == item) {
        temp = start;
        start = start->next;
        delete temp;
    } else {
        while (temp != nullptr && temp->data != item) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        prev->next = temp->next;
        delete temp;
    }
}

int main() {
    int choice, i = 1, item;
    do {
        menu();
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter item to insert: ";
            cin >> item;
            insertion(item);
            display();
        } else if (choice == 2) {
            cout << "Enter item to delete: ";
            cin >> item;
            deletion(item);
            display();
        } else {
            i = 0;
        }
    } while (i);
    return 0;
}
