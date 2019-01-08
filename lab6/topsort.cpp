#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector< vector<int> > graph;
vector<bool> used;
vector<int> ans;
int n;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (!used[to])
			dfs(to);
	}
	int res = v + 1;
	ans.push_back(res);
}

void topsort()
{
	for (int i = 0; i < n; i++)
        used[i] = false;
	ans.clear();
	for (int i = 0; i < n; i ++)
		if (!used[i])
			dfs(i);
}

int main()
{
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");
    int m;
    int x, y;
    fin >> n >> m;

    graph.resize(n);
    used.resize(n);

    for (int i = 0; i < m; ++i)
    {
        fin >> x >> y;
        x-=1;
        y-=1;
        graph[x].push_back(y);
    }

    topsort();


    for(int i = 0; i < ans.size(); i++)
        fout << ans[i] << " ";

    fout << endl;

    return 0;
}
