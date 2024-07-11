#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList
{
private:
    Node *dummy;

public:
    DoublyCircularLinkedList()
    {
        dummy = new Node(0); // Dummy node with a default value
        dummy->next = dummy;
        dummy->prev = dummy;
    }

    ~DoublyCircularLinkedList()
    {
        // Destructor to clean up memory
        Node *current = dummy->next;
        while (current != dummy)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete dummy;
    }
    void insert(int val)
    {
        Node *newNode = new Node(val);
        Node *current = dummy->next;
        cout << dummy << endl;
        // Find the correct position to insert
        while (current != dummy && current->data < val)
        {
            cout << current->data << endl;
            current = current->next;
        }

        // Insert the new node before the current node
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    void showAll()
    {
        Node *current = dummy->next;
        while (current != dummy)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node *search(int val)
    {
        Node *current = dummy->next;
        while (current != dummy && current->data != val)
        {
            current = current->next;
        }
        return (current != dummy) ? current : nullptr;
    }

    void deleteNode(int val)
    {
        Node *target = search(val);
        if (target)
        {
            target->prev->next = target->next;
            target->next->prev = target->prev;
            delete target;
        }
    }

    int length()
    {
        int len = 0;
        Node *current = dummy->next;
        while (current != dummy)
        {
            len++;
            current = current->next;
        }
        return len;
    }
};
int main()
{
    DoublyCircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(15);
    list.showAll(); // Output: 10 15 20

    Node *node = list.search(15);
    if (node)
        std::cout << "Found: " << node->data << std::endl; // Output: Found: 15

    list.deleteNode(15);
    list.showAll(); // Output: 10 20

    std::cout << "Length: " << list.length() << std::endl; // Output: Length: 2

    return 0;
}
