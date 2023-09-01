#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Dinh {
    int chiso;   
    int trongso;  

    Dinh(int i, int w) : chiso(i), trongso(w) {}
};

class DoThi {
private:
    int sodinh;               
    vector<vector<Dinh>> List; 

public:
    DoThi(int n) : sodinh(n) {
        List.resize(sodinh);
    }

    void Add(int u, int v, int trongso) {
        List[u].push_back(Dinh(v, trongso));
        List[v].push_back(Dinh(u, trongso));
    }

    void DFS(int first, int last) {
        vector<bool> checkvisit(sodinh, false);
        vector<int> Duong;
        stack<int> stack;

        stack.push(first);
        checkvisit[first] = true;

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();
            Duong.push_back(current);

            if (current == last) {
                cout << "Duong di DFS: ";
                for (int dinh : Duong) {
                    cout << dinh << " ";
                }
                cout << endl;
                return;
            }

            for (const Dinh& DinhLienKe : List[current]) {
                if (!checkvisit[DinhLienKe.chiso]) {
                    stack.push(DinhLienKe.chiso);
                    checkvisit[DinhLienKe.chiso] = true;
                }
            }
        }

        cout << "Khong tim thay duong di DFS tu " << first << " den " << last << endl;
    }

    void BFS(int first, int last) {
        vector<bool> checkvisit(sodinh, false);
        vector<int> Duong;
        queue<int> queue;

        queue.push(first);
        checkvisit[first] = true;

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            Duong.push_back(current);

            if (current == last) {
                cout << "Duong di BFS: ";
                for (int dinh : Duong) {
                    cout << dinh << " ";
                }
                cout << endl;
                return;
            }

            for (const Dinh& DinhLienKe : List[current]) {
                if (!checkvisit[DinhLienKe.chiso]) {
                    queue.push(DinhLienKe.chiso);
                    checkvisit[DinhLienKe.chiso] = true;
                }
            }
        }

        cout << "Khong tim thay duong di BFS tu " << first << " den " << last << endl;
    }
};

int main() {
    int m, n;
    cout << "Nhap so dinh: ";
    cin >> m;
    cout << "Nhap so canh: ";
    cin >> n;

    DoThi dothi(m);

    cout << "Nhap thong tin canh:" << endl;
    for (int i = 0; i < n; i++) {
        int a, b, w;
        cout << "Canh " << i << ": ";
        cin >> a >> b >> w;
        dothi.Add(a, b, w);
    }

    int first, last;
    cout << "Nhap dinh bat dau: ";
    cin >> first;
    cout << "Nhap dinh ket thuc: ";
    cin >> last;

    dothi.DFS(first, last);
    dothi.BFS(first, last);

    return 0;
}
