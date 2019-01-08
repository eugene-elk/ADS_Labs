#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include<math.h>

using namespace std;

const int INF = 1000000000;



int main()
{
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");

    int n;
    int start, finish;
    fin >> n >> start >> finish;

    vector<int> d(n, INF);
    vector<bool> used(n, false);
    vector< vector<int> > matrix(n, vector<int>(n));

    start -= 1;
    finish -= 1;

    int in;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fin >> in;
            if(in == -1) in = 0;
            matrix[i][j] = 0;
        }
    }

    d[start] = 0;
    for(int i = 0; i < n; i++)
    {
        int v = 0;
        for(int j = 0; j < n; j++)
        {
            if((!used[j]) && ((v == 0)||(d[j] < d[v])))
                v = j;
        }
        if(d[v] == INF) break;
        used[v] = true;
        for (int i = 0; i < matrix[v].size(); i++){ // применяем алгоритм Дейкстры
            d[matrix[v][i]] = min(d[matrix[v][i]], (d[v]+matrix[v][i]));
        }
    }

    for(int i = 0; i < d.size(); i++)
    {
        fout << d[i] << " ";
    }

    return 0;
}
