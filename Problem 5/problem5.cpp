#include<bits/stdc++.h>
using namespace std;
#include<string.h>
struct Node {
    char alphabet;
    int frequency;
    Node* next;
    
    Node(char a) : alphabet(a), frequency(0), next(nullptr) {}
};

class AlphabetList {
private:
    Node* head;
    
public:
    AlphabetList() {
        head = nullptr;
        for (char ch = 'z'; ch >= 'a'; --ch) {
            Node* newNode = new Node(ch);
            newNode->next = head;
            head = newNode;
        }
    }

    void updateFrequency(const std::string& str) {
        Node* current = head;
        while (current) {
            current->frequency = 0;
            current = current->next;
        }
        
        for (char ch : str) {
            current = head;
            while (current) {
                if (current->alphabet == ch) {
                    current->frequency++;
                    break;
                }
                current = current->next;
            }
        }
    }

    void printFrequencies() {
        Node* current = head;
        while (current) {
            std::cout << current->alphabet << " : " << current->frequency << std::endl;
            current = current->next;
        }
    }

    ~AlphabetList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    AlphabetList alphabetList;
    std::string input;
    
    std::cout << "Enter the string: ";
    std::cin >> input;

    alphabetList.updateFrequency(input);
    alphabetList.printFrequencies();

    return 0;
}
