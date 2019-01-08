#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > g;
int res[100005];

int main()
{
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n, m, u, v;
    fin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        fin >> u >> v;
        u -= 1;
        v -= 1;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int s = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++)
        {
            if (!res[v] && v!=s)
            {
                res[v] = res[u] + 1;
                q.push(v);
            }
        }

    }

    for (int i = 0; i < n; i++)
        fout << res[i] << "  ";

    return 0;
}
