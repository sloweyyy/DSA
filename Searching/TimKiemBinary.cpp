#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Item {
	string word;
	string meaning;
};

void loadData(char file[], Item dat[], int &n) {
	ifstream fi(file);
	if (!fi.is_open()) {
		cout << "Khong mo duoc file de tu dien" << endl;
		return;
	}
	string s;
	int b, e;
	n = 0;
	while(!fi.eof()) {
		getline(fi, s);
		b = s.find("\t");
		if (b < 0)
			continue;
		dat[n].word = s.substr(0, b);
		s = s.substr(b + 1);
		while ((b = s.find("|=")) > -1) {
			s.replace(b, 2, "\n");
		}
		dat[n].meaning = s;
		n++;
	}
	fi.close();
}

int linearSearch(string word, Item dat[], int n) {
	for (int i = 0; i < n; i++) {
        if (dat[i].word == word)
            return i;
    }
    return -1;
}

int binarySearch(string word, Item dat[], int n) {
	int l = 0, r = n-1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (dat[m].word == word) 
			return m;
		if (word < dat[m].word) 
			r = m - 1;
		else l = m + 1;
	}
	return -1;
}

int main() {
	Item *data = new Item[13375];
	int n;
	clock_t start;
	start = clock();
	cout << "Tai du lieu tu dien" << endl;
	loadData("D:/Code Workspace/DSA/Searching/computer.txt", data, n);
	cout << "Tong so tu vung: " << n << endl;
	cout << "Thoi gian tai du lieu: " << clock() - start << "ms" << endl;
	string word;
    /**/
	while (1) {
		cout << "Nhap tu can tra (EXIT de thoat): ";
		getline(cin,word);
		if (word == "EXIT")
			break;
		start = clock();
		int index = binarySearch(word, data, n);
        if (index == -1) {
            cout << word << endl;
        } else {
            cout << data[index].meaning << endl;
        }
        cout << "Thoi gian tim kiem: " << clock() - start << "ms" << endl;
		
	}
    /**/
	delete[] data;
	system("pause");
	return 0;
}