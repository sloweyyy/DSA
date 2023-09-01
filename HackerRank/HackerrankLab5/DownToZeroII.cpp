#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define NSIZE 1000000

vector<vector<int>> ar(NSIZE + 1);

bool primes[NSIZE + 1];
int cache[NSIZE], dcache[NSIZE];

void gen_primes()
{
    for (int i = 2; i <= NSIZE; i++)
    {
    }

    for (int i = 1; i <= NSIZE; i++)
    {
        bool prime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        primes[i] = prime;
    }
}

void get_a(int n)
{
    if (primes[n])
        return;
    if (dcache[n] != -1)
        return;
    else
        dcache[n] = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int v = n / i;
            if (v == 1 || i == 1)
                continue;
            v = v > i ? v : i;
            ar[n].push_back(v);
        }
    }
}

int w[NSIZE];
void fill_cache(int steps, int number, int start)
{
    int indx = start;
    int st = 1;

    if (cache[start] != -1)
        st = cache[start] + 1;

    while (1)
    {
        int pos = w[indx];
        cache[pos] = st++;

        indx = pos;
        if (st == steps + 1)
            break;
    }
}

int *q;
int qpos = 0;
int qend = 0;
int steps = 0;
int cal_steps(int v)
{
    for (int i = 0; i <= v; i++)
        w[i] = -1;

    qpos = 0;
    qend = 0;
    steps = 0;
    q[qend++] = v;
    q[qend++] = -1;

    while (1)
    {
        int val = q[qpos++];
        if (val == -1)
        {
            steps++;
            q[qend++] = -1;
            val = q[qpos++];
        }

        if (val == 0)
        {
            return steps;
        }

        get_a(val);
        for (int i = 0; i < ar[val].size(); i++)
        {
            if (w[ar[val][i]] == -1)
                w[ar[val][i]] = val;
            int tmp_val = ar[val][i];
            q[qend++] = tmp_val;
        }

        val -= 1;
        q[qend++] = val;
    }

    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    q = new int[NSIZE * 19];
    int n, v;
    cin >> n;
    int max = n;
    for (int i = 0; i < NSIZE; i++)
    {
        cache[i] = -1;
        dcache[i] = -1;
    }
    gen_primes();
    while (n--)
    {
        cin >> v;
        if (v == 0)
        {
            cout << "0" << endl;
            continue;
        }
        cout << cal_steps(v) << endl;
    }
    return 0;
}
