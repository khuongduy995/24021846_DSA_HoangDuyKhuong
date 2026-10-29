
#include <iostream>
#include <list>
using namespace std;

class StackList {
private:
    list<int> stack_data;

public:
    bool isEmpty() { //O(1)
        return stack_data.size() == 0;
    }

    void push(int item) { //O(1)
        stack_data.push_back(item);
    }

    int pop() {
        if (isEmpty()) { //O(1)
            cout << "Loi: Stack rong!";
            return -1;
        }

        int value = stack_data.back();
        stack_data.pop_back();
        return value;
    }

    int size() { //O(1)
        return stack_data.size();
    }

    int top() { //O(1)
        if (isEmpty()) {
            cout << "Loi: Stack rong!";
            return -1;
        }

        return stack_data.back();
    }
};

int main() {
    StackList st;

    st.push(10);
    st.push(20);
    st.push(30);

    int popped_item = st.pop();
    cout << "Da pop thanh cong phan tu: "
         << popped_item << endl;

    cout << "Phan tu o dinh: " << st.top() << endl;
    cout << "Kich thuoc stack hien tai: "
         << st.size() << endl;

    return 0;
}
