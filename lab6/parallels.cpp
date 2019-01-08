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
    bool flag = false;
    fin >> n >> m;

    vector< vector<int> > graph(n, vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        fin >> x >> y;
        graph[x-1][y-1] += 1;
        graph[y-1][x-1] += 1;
        if(graph[x-1][y-1] == 2) flag = true;
    }

    if (flag) fout << "YES" << endl;
    else fout << "NO" << endl;

    return 0;
}
