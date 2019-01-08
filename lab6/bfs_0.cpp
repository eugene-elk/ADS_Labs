#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n, m;
    int x, y;
    fin >> n >> m;

    vector< vector<int> > graph(n, vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        fin >> x >> y;
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }

    int s = 0;
    queue<int> q;
    q.push(s);
    vector<char> used(n);
    vector<int> res(n, 0);
    used[s] = true;
    while (q.size() != 0)
    {
        int v = q.front();
        for (int i = 0; i < graph[v].size(); ++i)
        {
            if (!used[i] && graph[v][i])
            {
                used[i] = true;
                q.push(i);
                res[i] = res[v] + 1;
            }
        }
        q.pop();
    }
    for (int i = 0; i < n; i++)
        fout << res[i] << "  ";

    return 0;
}
