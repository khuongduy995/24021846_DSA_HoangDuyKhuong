#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class QueueLinkedList {
private:
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    QueueLinkedList() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Loi: Queue rong!";
            return -1;
        }
        Node* temp = frontNode;
        int val = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Loi: Queue rong!";
            return -1;
        }
        return frontNode->data;
    }

    int size() {
        return count;
    }
};

int main() {
    QueueLinkedList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Phan tu o dau queue: " << q.front() << endl;

    cout << "Xoa: " << q.dequeue() << endl;
    cout << "Front sau khi dequeue: " << q.front() << endl;
    cout << "Kich thuoc queue: " << q.size() << endl;

    return 0;
}
