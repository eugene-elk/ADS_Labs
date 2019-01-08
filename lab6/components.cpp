#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector< vector<int> > graph;

vector<bool> used;

void dfs(int node_index)
{
    used[node_index] = true;
    for (const auto& i : graph[node_index])
    {
        if (!used[i])
            dfs(i);
    }
}

int main()
{
    ifstream fin("components.in");
    ofstream fout("components.out");
    int n, m;
    int x, y;

    fin >> n >> m;


    for (int i = 0; i < m; i++)
    {
        fin >> x >> y;
        graph[x-1][y-1] = 1;
    }

    dfs(1);
}
