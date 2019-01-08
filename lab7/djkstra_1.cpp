#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include<math.h>

using namespace std;

const long long inf = 2000000000000;

int main()
{
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");

    int N, start, finish;
    fin >> N >> start >> finish;

    vector<vector<long long> > graph(N,vector<long long>(N, inf));

    for(int i = 0; i < N; i++)
    {
		for(int j = 0; j < N; j++)
		{
			fin >> graph[i][j];
			if(graph[i][j] < 0) graph[i][j] = inf;
		}
	}

    vector<long long> dist(N, inf);
    vector<bool> used(N, false);
    dist[start - 1] = 0;

    for(int i = 0; i < N; i++)
    {
		int v = -1;
		for(int j = 0; j < N; j++)
		{
			if(!used[j] && (v == -1 || dist[j] < dist[v])){
				v = j;
			}
		}
		used[v] = 1;

		for(int j = 0; j < N; j++){
			dist[j] = min(dist[j], dist[v] + graph[v][j]);
		}
	}
    if (dist[finish - 1] >= inf) fout << -1;
    else fout << dist[finish - 1];
    return 0;
}
