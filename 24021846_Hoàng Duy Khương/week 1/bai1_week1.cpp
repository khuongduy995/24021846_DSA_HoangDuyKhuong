#include <iostream>
#include <vector>
using namespace std; 

long long tinhTong(const vector<int>& a) {
    long long tong = 0;
    for (int x : a) {
        tong += x;
    }
    return tong;
}

int main(){
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	
	vector<int> a(n);
	cout << "Nhap cac phan tu cua mang: ";
	for(int i =0; i < n;i++){
		cin >> a[i];
	}
	cout << "Tong cac phan tu trong day = " << tinhTong(a) <<endl;
	
	return 0;
}

//do phuc tap thoi gian: O(n)
//do phuc tap bo nho: O(n)
