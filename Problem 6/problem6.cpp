#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct N {
    int c;
    int e;
    N* n;
    N(int coeff, int exp): c(coeff), e(exp), n(nullptr) {}
};

class P {
public:
    P(): h(nullptr) {}

    void addT(int c, int e) {
        N* newN = new N(c, e);
        if (!h) {
            h = newN;
        } else {
            N* curr = h;
            N* prev = nullptr;
            while (curr && curr->e > e) {
                prev = curr;
                curr = curr->n;
            }
            if (curr && curr->e == e) {
                curr->c += c;
                delete newN;
            } else {
                newN->n = curr;
                if (prev) {
                    prev->n = newN;
                } else {
                    h = newN;
                }
            }
        }
    }

    void print() const {
        N* curr = h;
        bool first = true;
        while (curr) {
            if (!first && curr->c > 0) {
                cout << " + ";
            }
            cout << curr->c;
            if (curr->e != 0) {
                cout << "x^" << curr->e;
            }
            curr = curr->n;
            first = false;
        }
        cout << endl;
    }

    static P add(const P& p1, const P& p2) {
        P res;
        N* a = p1.h;
        N* b = p2.h;

        while (a && b) {
            if (a->e > b->e) {
                res.addT(a->c, a->e);
                a = a->n;
            } else if (a->e < b->e) {
                res.addT(b->c, b->e);
                b = b->n;
            } else {
                res.addT(a->c + b->c, a->e);
                a = a->n;
                b = b->n;
            }
        }

        while (a) {
            res.addT(a->c, a->e);
            a = a->n;
        }

        while (b) {
            res.addT(b->c, b->e);
            b = b->n;
        }

        return res;
    }

private:
    N* h;
};

void parseP(const string& s, P& p) {
    int i = 0;
    int len = s.length();
    while (i < len) {
        bool neg = false;
        if (s[i] == '-') {
            neg = true;
            i++;
        }
        int c = 0;
        while (i < len && isdigit(s[i])) {
            c = c * 10 + (s[i] - '0');
            i++;
        }
        if (neg) c = -c;

        if (i < len && s[i] == 'x') {
            i++;
            if (i < len && s[i] == '^') {
                i++;
                int e = 0;
                while (i < len && isdigit(s[i])) {
                    e = e * 10 + (s[i] - '0');
                    i++;
                }
                p.addT(c, e);
            } else {
                p.addT(c, 1);
            }
        } else {
            p.addT(c, 0);
        }

        while (i < len && (s[i] == ' ' || s[i] == '+' || s[i] == '-')) {
            i++;
        }
    }
}

int main() {
    P p1, p2;
    string in1, in2;

    getline(cin, in1);
    parseP(in1, p1);

    getline(cin, in2);
    parseP(in2, p2);

    P res = P::add(p1, p2);

    res.print();

    return 0;
}
