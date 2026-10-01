#include <iostream>
#include <cmath>

using namespace std;

int timUCLN(int x, int y) {
    x = abs(x);
    y = abs(y);
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

void rutGonPhanSo(int &a, int &b) {
    if (b == 0) return;
    
    int ucln = timUCLN(a, b);
    a /= ucln;
    b /= ucln;
    
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

int main() {
    int a, b;
    cout << "Nhap tu so a: ";
    cin >> a;
    cout << "Nhap mau so b: ";
    cin >> b;

    if (b == 0) {
        cout << "Mau so khong the bang 0!" << endl;
    } else {
        rutGonPhanSo(a, b);
        
        cout << "Phan so sau khi rut gon: ";
        if (b == 1) {
            cout << a << endl;
        } else {
            cout << a << "/" << b << endl;
        }
    }

    return 0;
}
//do phuc tap thoi gian: O(log(min(|a|,|b|)))
//do phuc tap bo nho: O(1)
