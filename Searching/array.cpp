#include<iostream>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	int** a;
	a = new int* [n];
	for(int i = 0; i<n; i++){
		a[i] = new int[m];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=0; j<m; j++){
			sum += a[i][j];
		}
		cout << sum << endl;
	}
	for(int i=0; i<n; i++){
		delete[] a[i];
	}
	delete[] a;
	return 0;
}