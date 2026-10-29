#include <iostream>
#include <list>

using namespace std;

class QueueList {
private:    
    list<int> queue_list;
public:  
    bool isEmpty() {
        return queue_list.empty();
    }

    void enqueue(int item) {
        queue_list.push_back(item);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Loi: Queue rong!";
            return -1;
        }
        int val = queue_list.front();
        queue_list.pop_front();
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Loi: Queue rong!";
            return -1;
        }
        return queue_list.front();
    }

    int size() {
        return queue_list.size();
    }
};

int main() {
    QueueList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Phan tu o dau queue (Front): " << q.front() << endl;

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Front sau khi dequeue: " << q.front() << endl;
    cout << "Kich thuoc queue: " << q.size() << endl;

    return 0;
}
