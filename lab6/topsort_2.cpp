#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > graph;
vector<int> used;
vector<int> ans;
int n;
bool flag;

bool dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < graph[v].size(); i++)
    {
		int to = graph[v][i];
        if(used[to] == 0)
        {
            if(dfs(to)) return true;
        }
        else
        if(used[to] == 1)
        {
            return true;
        }
	}
	int res = v + 1;
	ans.push_back(res);
	used[v] = 2;
	return false;
}

void topsort()
{
	for (int i = 0; i < n; i++)
        used[i] = false;
	ans.clear();
	for (int i = 0; i < n; i ++)
        if (!used[i])
        {
			flag = dfs(i);
            if (flag) break;
        }
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

    if(!flag)
    {
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            fout << ans[i] << " ";
        fout << endl;
    }
    else
        fout << "-1" << endl;

    return 0;
}
