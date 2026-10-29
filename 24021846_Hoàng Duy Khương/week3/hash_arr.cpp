
#include <iostream>
using namespace std;

const int SIZE = 10;

int table[SIZE];
bool used[SIZE] = {false};

int hashFunction(int x) {
    return x % SIZE;
}

void insert(int x) {
    int index = hashFunction(x);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (used[pos] == false) {
            table[pos] = x;
            used[pos] = true;
            return;
        }

        if (table[pos] == x) {
            cout << x << " da ton tai!\n";
            return;
        }
    }

    cout << "Bang bam da day!\n";
}

bool search(int x) {
    int index = hashFunction(x);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (used[pos] == false)
            return false;

        if (table[pos] == x)
            return true;
    }

    return false;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";

        if (used[i])
            cout << table[i];
        else
            cout << "Trong";

        cout << endl;
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

