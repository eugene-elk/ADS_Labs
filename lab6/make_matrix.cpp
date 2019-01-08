#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    int x, y;

    fin >> n >> m;

    vector< vector<int> > graph(n, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        fin >> x >> y;
        graph[x-1][y-1] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fout << graph[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}
