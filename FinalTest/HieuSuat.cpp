#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

int graph[MAX_SIZE][MAX_SIZE];
int computers[MAX_SIZE];
bool visited[MAX_SIZE];

void dfs(int node, int M, int& total_power) {
    visited[node] = true;
    total_power += computers[node];
    for (int i = 0; i < M; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, M, total_power);
        }
    }
}

void find_max_power_group(int M, int N, int& max_power, int* max_power_group) {
    max_power = 0;
    int group_size = 0;

    for (int i = 0; i < M; i++) {
        if (!visited[i]) {
            int total_power = 0;
            dfs(i, M, total_power);
            if (total_power > max_power) {
                max_power = total_power;
                group_size = 1;
                max_power_group[0] = i;
            }
            else if (total_power == max_power) {
                max_power_group[group_size] = i;
                group_size++;
            }
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        cin >> computers[i];
    }

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }

    int max_power = 0;
    int* max_power_group = new int[MAX_SIZE];
    find_max_power_group(M, N, max_power, max_power_group);

    for (int i = 0; i < M; i++) {
        if (max_power_group[i] != 0) {
            cout << max_power_group[i] << endl;
        }
    }

    delete[] max_power_group;

    return 0;
}
