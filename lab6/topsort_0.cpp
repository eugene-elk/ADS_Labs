#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector <int> color(100001, 0);
vector <int> ans;
int count;
bool f = true;
int m, n, a, b;

void dfs(int i, vector< vector <int> > &ver)
{
    color[i] = 1;
    if (ver[i].size() > 0 ){
        for (int j = 0; j < ver[i].size(); ++j){
            if (color[ver[i][j]] == 0) dfs(ver[i][j], ver);
            if (color[ver[i][j]] == 1){
                f = false;
                return;
            }
        }
    }
    color[i] = 2;
    ans.push_back(i);
}

int main()
{
    ifstream cin ("topsort.in");
    ofstream cout ("topsort.out");
    cin >> n >> m;
    vector < vector<int> > ver(n+1);
    for (int i = 0; i < m; ++i){
        cin >> a >> b;
        ver[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i){
        if (color[i] == 0){
            dfs(i, ver);
        }
    }

    if (f == false){
        cout << "-1" << endl;
    } else
        for (int i = n - 1; i >= 0; --i){
            cout << ans[i] << " ";
        }
    cout << endl;

}
