#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> pii;
const long long inf = 2000000000000;
const double PI = 3.14159265;
int dpx[4] = {0, 1, 0, -1};
int dpy[4] = {1, 0, -1, 0};
#define dsize(N)	cout.precision(N)
#define ALL(v)		v.begin(),v.end()
#define FORR(a,b,c)	for(int a=b;a<c;a++)
#define FOR(a,b)    FORR(a,0,b)
#define as(v,N)		v.assign(N,0)
#define as2(v,N,M)	v.assign(N,VI(M,0))
#define pb(a) 		push_back(a)
#define sz(v)       v.size()
#define mp(a,b)		make_pair(a,b)
#define in(a)       cin >> a
#define in2(a,b)	cin >> a >> b
#define in3(a,b,c)	cin >> a >> b >> c
#define inv(v,N)	FOR(i,N) in(v[i])
#define out(a)		cout << a
#define out2(a,b)	cout << a << " " << b
#define out3(a,b,c)	cout << a << " " << b << " " << c
#define outs(a)		cout << a << " "
#define outv(v,N)	FOR(i,N) outs(v[i])
#define f           first
#define s           second
ifstream fin("pathmgep.in");
ofstream fout("pathmgep.out");

vector<vector<long long> > E;
vector<long long> used, dist;

int main()
{
	int st, end, M, N;
	int a, b, c;
	fin >> N >> st >> end;
	E.assign(N,vector<long long>(N, inf));

	for (int i = 0; i < N; i++ ){
		for( int j = 0; j < N; j++ ){
			fin >> E[i][j];
			if( E[i][j] < 0 ){
				E[i][j] = inf;
			}
		}
	}

	dist.assign( N, inf );
	dist[st - 1] = 0;
	used.assign(N, false);

	for(;;) {
		int v = -1;
		for(int j = 0; j < N; j++){
			if(!used[j] && (v == -1 || dist[j] < dist[v])){
				v = j;
			}
		}
		if (dist[v] == inf || v == -1){
			if (dist[ end - 1 ] >= inf ){
				fout << -1;
			}
			else{
				fout << dist[end - 1];
			}
			return 0;
		}
		used[v] = 1;

		for( int i = 0; i < N; i++){
			dist[i] = min(dist[i] , dist[v] + E[v][i]);
		}
	}
}
