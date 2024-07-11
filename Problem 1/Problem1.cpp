#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    int sum() const
    {
        int total = 0;
        Node* current = head;
        while (current != nullptr)
        {
            total += current->data;
            current = current->next;
        }
        return total;
    }
};
class Octopus
{
public:
    LinkedList left, right, top, bottom;

    void insert(char direction, int data)
    {
        switch (direction)
        {
        case 'L':
            left.insert(data);
            break;
        case 'R':
            right.insert(data);
            break;
        case 'T':
            top.insert(data);
            break;
        case 'B':
            bottom.insert(data);
            break;
        }
    }
    void determinant(){
        int  l_sum, r_sum, t_sum, b_sum;
        l_sum = left.sum();
        r_sum = right.sum();
        t_sum = top.sum();
        b_sum = bottom.sum();

        if (l_sum >= r_sum && l_sum >= t_sum && l_sum >= b_sum) 
            cout << "Left Link List Has Maximum Sum " << l_sum << endl;
        else if (r_sum >= l_sum && r_sum >= t_sum && r_sum >= b_sum)
            cout << "Right Link List Has Maximum Sum " << r_sum << endl;
        else if (t_sum >= l_sum && t_sum >= r_sum && t_sum >= b_sum)
            cout << "Top Link List Has Maximum Sum " << t_sum << endl;
        else
            cout << "Bottom Link List Has Maximum Sum " << b_sum << endl;
        

    }
};
int main(){
    Octopus octopus;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int number;
        char dir;
        cin>>dir;
        cin>>number;
        octopus.insert(dir, number);
    }
    octopus.determinant();
    return 0;
}