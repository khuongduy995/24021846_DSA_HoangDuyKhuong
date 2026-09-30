#include <iostream>

using namespace std;

long long giaiThua(int n){
	long long result = 1;
	for(int i = 1; i <= n; i++){
		result = result*i;
	}
	return result;
}
int main(){
	int n;
	cout << "Nhap so giai thua: ";
	cin >> n;
	if(n < 0){
		cout << "Khong ton tai giai thua so am!";
		return 0;
	}else if(n == 0){
		cout << "Ket qua = 0";
		return 0;
	}
	cout << "Ket qua = " <<giaiThua(n) <<endl;
	
	return 0;
}
// Do phuc tap thuat toan: O(n)
// Do phuc tap bo nho: O(1)
