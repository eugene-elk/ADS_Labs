#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[30005];
int res[30005];

int main()
{
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n, m, x, y;
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        fin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int s = 1;
    queue<int> q;
    q.push(s);
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v = 0; v < graph[u].size(); v++)
        {
            if (!res[graph[u][v]] && graph[u][v]!=s)
            {
                res[graph[u][v]] = res[u] + 1;
                q.push(graph[u][v]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        fout << res[i] << " ";

    return 0;
}
