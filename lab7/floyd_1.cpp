#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include<math.h>

using namespace std;
const int inf = 1000000;
int main()
{
	ifstream fin("pathsg.in");
	ofstream fout("pathsg.out");

	int N, M;
    fin >> N >> M;

    vector<vector<int> > graph(N,vector<int>(N, inf));

    int x, y, z;
	for(int i = 0; i < M; i++)
    {
		fin >> x >> y >> z;
		graph[x - 1][y - 1] = z;
	}

    for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    for(int i = 0; i < N; i++)
    {
		for(int j = 0; j < N; j++)
		{
			if(i == j) graph[i][i] = 0;
			fout << graph[i][j] << " ";
		}
		fout << endl;
	}
}
