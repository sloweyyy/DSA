#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL)); 

    int n = 10; 
    ofstream file("testcase.txt"); 

    file << n << endl; 
    for (int i = 0; i < n; i++) {
        int x = rand() % 100; 
        int y = rand() % 100; 
        file << x << " " << y << endl; 
    }

    file.close(); 

    return 0;
}
