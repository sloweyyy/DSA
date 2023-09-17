#include<iostream>
#include<vector>

using namespace std;

void InputMatrix(vector<vector<int>>&, int);
void PrintVector(const vector<int>&); 
void AdjacencyList(const vector<vector<int>>&, int);

int main()
{
    int m;
    cin >> m;

    vector<vector<int>> arr(m, vector<int>(m));
    InputMatrix(arr, m);    

    AdjacencyList(arr, m);

    return 0;
}

void InputMatrix(vector<vector<int>>& arr, int m)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
}

void PrintVector(const vector<int>& vt)
{
    for(int i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
}

void AdjacencyList(const vector<vector<int>>& arr, int m)
{
    for(int i = 0; i < m; i++)
    {
        vector<int> res;
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1)
                res.push_back(j + 1);
        }   
        if(!res.empty())
        {
            cout << (i + 1) << "->";
            PrintVector(res);
            cout << "\n";
        }   
    }
}
