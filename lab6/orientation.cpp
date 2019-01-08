#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    bool flag = true;
    int n;
    fin >> n;

    vector< vector<int> > graph(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fin >> graph[i][j];
            if((j < i) && (graph[i][j] != graph[j][i])) flag = false;
            if((i == j) && (graph[i][j] == 1)) flag = false;
        }
    }
    if (flag) fout << "YES" << endl;
    else fout << "NO" << endl;
    return 0;
}
