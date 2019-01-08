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
const int inf = 2000000;
int dpx[4] = {0, 1, 0, -1};
int dpy[4] = {1, 0, -1, 0};
#define ALL(v)		v.begin(),v.end()
#define as(v,N)		v.assign(N,0)
#define as2(v,N,M)	v.assign(N,VI(M,0))
#define pb(a) 		push_back(a)

void FW(VVI &E, int N){
	for( int k = 0; k < N; k++ ){
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < N; j++ ){
				E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
			}
		}
	}
}

int main(){
	ifstream fin("pathsg.in");
	ofstream fout("pathsg.out");
	int N, M;
	VVI E;
	fin >> N >> M;
	E.assign(N,VI(N, inf));

	int a, b, c;
	for( int i = 0; i < M; i++ ){
		fin >> a >> b >> c;
		E[a - 1][b - 1] = c;
	}

	FW(E, N);

	for( int i = 0; i < N; i++ ){
		for( int j = 0; j < N; j++ ){
			if( i == j ){
				E[i][i] = 0;
			}
			fout << E[i][j] << " ";
		}
		fout << endl;
	}

}

