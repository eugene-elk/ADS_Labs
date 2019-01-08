#include<iostream>
#include<math.h>
#include<vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> >g;
int used[100005];
vector<int> to;
int start  = -1,  ende = -1;

bool dfs(int v)
{
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++)
    {
        int p = i;

        if(used[p] == 0)
        {
            to[p] = v;
            if(dfs(p)) return 1;
        }
        else
        if(used[p] == 1)
        {
            start = p;
            ende = v;
            return true;
        }

    }
    used[v] = 2;
    return false;
}

int main()
{
      freopen("cycle.in", "r", stdin);
      freopen("cycle.out", "w", stdout);

    int n , m;
    cin >> n >> m;
    to.resize(n , -1);
    g.resize(n);
    if(n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        if(dfs(i)) break;
    if(start == -1)
    {
        cout << "NO" << "\n";
        return 0;
    }
    else
    {
        cout << "YES" << "\n";
        vector<int> ans;
        ans.push_back (start);
        //cout << ende << " " << start;
        for (int v=ende ; v!=start; v= to[v])
        {
          ans.push_back (v);
        }
        ans.push_back (start);
        reverse (ans.begin(), ans.end());
        for (int i=0; i < ans.size() - 1; i++)
            cout << ans[i] + 1 << " ";
        cout << "\n";

    }
    return 0;
}
