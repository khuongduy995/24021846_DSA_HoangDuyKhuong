
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }

        Node* temp = head;
        int value = temp->data;

        head = head->next;
        delete temp;

        return value;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }

        return head->data;
    }

    int size() {
        int count = 0;
        Node* p = head;

        while (p != NULL) {
            count++;
            p = p->next;
        }

        return count;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Dinh Stack: " << st.top() << endl;
    cout << "So phan tu: " << st.size() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Dinh moi: " << st.top() << endl;

    return 0;
}

