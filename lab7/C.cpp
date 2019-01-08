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
ifstream fin("pathbgep.in");
ofstream fout("pathbgep.out");

vector<vector<pii> > E;
vector<long long> used, dist;

int main()
{
	int st, end, M, N;
	int a, b, c;
	fin >> N >> M;
	E.assign(N,vector<pii>());
	
	for (int i = 0; i < M; i++ ){
		fin >> a >> b >> c;
		E[a - 1].push_back({b - 1, c});
		E[b - 1].push_back({a - 1, c});
	}
	
	dist.assign( N, inf );
	dist[0] = 0;
	used.assign(N, false);
	multimap<long long, int > mp;
	mp.insert({0, 0});
	while(!mp.empty()) {
		int v = mp.begin()->second;
		mp.erase(mp.begin());
		
		if(dist[v] == inf){
			for( int i = 0; i < N; i++ ){
				fout << dist[i] << " ";
			}
			return 0;
		}
		
		for( int j = 0; j < E[v].size(); j++ ) {
			int to = E[v][j].first, len = E[v][j].second;
			if (dist[v] + len < dist[to]) {
				dist[to] = dist[v] + len;
				mp.insert(make_pair (dist[to], to));
			}
		}
	}
	for( int i = 0; i < N; i++ ){
			fout << dist[i] << " ";
	}
	return 0;
}
