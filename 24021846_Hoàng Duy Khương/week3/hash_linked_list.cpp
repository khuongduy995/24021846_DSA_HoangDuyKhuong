#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int data;
    Node *next;
};

Node *table[SIZE] = {NULL};

int hambam(int x)  {
	if(x >= 0){
		return x % SIZE;
	}else{
	return -(x % SIZE);
	}
}

void insert(int x) { //O(1)
    int index = hambam(x);

    Node *p = new Node;
    p->data = x;
    p->next = table[index];

    table[index] = p;
}

bool search(int x) { //O(n)
    int index = hambam(x);
    Node *p = table[index];

    while (p != NULL) {
        if (p->data == x)
            return true;

        p = p->next;
    }

    return false;
}

void display() { //O(n)
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
      int n,x;
    cout << "Nhap so phan tu";
    cin >> n;
    
    cout << "Nhap mang";
    
    for(int i = 0; i < n; i++){
    	cin >> x;
    	insert(x);
	}
    display();

    cout << "Nhap so can tim";
    cin >> x;
    if(search(x)){
    	cout << "Tim thay " << x;
	} else {
		cout << "Khong tim thay";  
	}
    return 0;
}
