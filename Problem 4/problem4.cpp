#include<bits/stdc++.h>
#include <string.h>

using namespace std;

struct Node {
    int count;
    char ch;
    Node* next;
    Node(int c, char ch): count(c), ch(ch), next(nullptr) {}
};

class BinaryImage {
public:
    BinaryImage(int rows, int cols): rows(rows), cols(cols) {
        image.resize(rows);
    }

    void addRow(int rowIndex, const string& row) {
        Node* dummy = new Node(0, ' ');
        Node* current = dummy;
        char currentChar = row[0];
        int count = 0;

        for (char ch : row) {
            if (ch == currentChar) {
                count++;
            } else {
                current->next = new Node(count, currentChar);
                current = current->next;
                currentChar = ch;
                count = 1;
            }
        }
        current->next = new Node(count, currentChar);
        image[rowIndex] = dummy->next;
    }

    void printMirrorImage() const {
        for (const Node* row : image) {
            printMirrorRow(row);
            cout << endl;
        }
    }

private:
    int rows, cols;
    vector<Node*> image;

    void printMirrorRow(const Node* row) const {
        if (!row) return;

        // Store segments to print in reverse order
        vector<pair<int, char>> segments;
        const Node* current = row;
        while (current) {
            segments.emplace_back(current->count, current->ch);
            current = current->next;
        }

        // Print in reverse order
        for (auto it = segments.rbegin(); it != segments.rend(); ++it) {
            cout << string(it->first, it->second);
        }
    }
};

int main() {
    int rows, cols;
    cin >> rows >> cols;
    BinaryImage image(rows, cols);

    for (int i = 0; i < rows; ++i) {
        string row;
        cin >> row;
        image.addRow(i, row);
    }

    image.printMirrorImage();

    return 0;
}
