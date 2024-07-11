#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *prev;
    Node *next;

    Node(int k) : key(k), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *dummy;

public:
    DoublyLinkedList()
    {
        dummy = new Node(-1); // Use -1 as the dummy node key, you can choose another value as well
        dummy->next = dummy;
        dummy->prev = dummy;
    }

    void jInsert(int key_of_x, int key_of_y)
{
    Node *newNode = new Node(key_of_x);
    Node *current = dummy->next;

    // Search for node y
    while (current != dummy)
    {
        if (current->key == key_of_y)
        {
            cout << "INSERT after " << key_of_y << "\n";

            // Insert node x after node y
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;

            return;
        }
        current = current->next;
    }
    cout<<"INSERT after dummy node.\n";
    // If node y is not found, insert after dummy
    newNode->next = dummy->next;
    newNode->prev = dummy;
    dummy->next->prev = newNode;
    dummy->next = newNode;
}

    void deleteNode(int key)
    {
        Node *current = dummy->next;

        // Search for the node with the given key
        while (current != dummy)
        {
            if (current->key == key)
            {
                // Unlink the node from the list
                current->prev->next = current->next;
                current->next->prev = current->prev;

                // Delete the node
                delete current;
                return;
            } 
            current = current->next;
        }

        cout <<"Delete Not Possible"<< endl;
    }
    void searchIN(int key)
    {
        Node *current = dummy->next;

        // Search for the node with the given key
        while (current != dummy)
        {
            if (current->key == key)
            {
                cout << "Node with key " << key << " found." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Node with key " << key << " not found." << endl;
    }

    void printList()
    {
        Node *current = dummy->next;
        while (current != dummy)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~DoublyLinkedList()
    {
        Node *current = dummy->next;
        while (current != dummy)
        {
            Node *toDelete = current;
            current = current->next;
            delete toDelete;
        }
        delete dummy;
    }
};


    

    int main()
    {
        DoublyLinkedList* list;
        list = new DoublyLinkedList();
        string input;
        int x, y;
        while (1)
        {
        
            cin >> input;

            if (input == "ins")
            {
                cin >> x >> y;
                list->jInsert(y,x);
            }
            else if (input == "del")
            {
                int key;
                cin>>key;
                list->deleteNode(key);

            }
            else if (input == "sch")
            {
                int searchKey;
                cin>>searchKey;
                list->searchIN(searchKey);
            }
            else if (input == "shw")
            {
                list->printList();
            }
            else
                return 0;
        }
    }
