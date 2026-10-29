#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int data;
    Node *next;
};

Node *table[SIZE] = {NULL};

int hashFunction(int x) {
    return x % SIZE;
}

void insert(int x) {
    int index = hashFunction(x);

    Node *p = new Node;
    p->data = x;
    p->next = table[index];

    table[index] = p;
}

bool search(int x) {
    int index = hashFunction(x);
    Node *p = table[index];

    while (p != NULL) {
        if (p->data == x)
            return true;

        p = p->next;
    }

    return false;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";

        Node *p = table[i];

        while (p != NULL) {
            cout << p->data << " -> ";
            p = p->next;
        }

        cout << "NULL" << endl;
    }
}

int main() {
    insert(12);
    insert(22);
    insert(32);
    insert(15);

    display();

    if (search(22))
        cout << "Tim thay 22";
    else
        cout << "Khong tim thay 22";

    return 0;
}
