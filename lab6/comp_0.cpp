#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<bool> used;
vector<int> comp;
int num_of_comp = 0;

void dfs(int v)
{
    used[v] = true;
    comp[v] = num_of_comp;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

int main()
{
    ifstream fin("components.in");
    ofstream fout("components.out");
    int n, m;
    int x, y;
    fin >> n >> m;
    g.resize(n);
    used.resize(n);
    comp.resize(n);

    for (int i = 0; i < m; ++i)
    {
        fin >> x >> y;
        x-=1;
        y-=1;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < g.size(); i++)
    {
        if (!used[i])
        {
            num_of_comp += 1;
            dfs(i);
        }
    }
    fout << num_of_comp << endl;
    for (int i = 0; i < comp.size(); i++)
    {
        fout << comp[i] << " ";
    }
    return 0;
}
