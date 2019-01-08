#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int graph[105][105];

struct coord
{
    int x, y;
} s, f;

vector<char> res;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> m >> n;

    char in;

    for(int i = 0; i < n + 2; i++)
    {
        graph[0][i] = -1;
        graph[m+1][i] = -1;
    }

    for(int j = 0; j < m + 2; j++)
    {
        graph[j][0] = -1;
        graph[j][n+1] = -1;
    }

    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            fin >> in;
            if(in == '.') graph[j+1][i+1] = 0;
            if(in == '#') graph[j+1][i+1] = -1;
            if(in == 'S'){
                s.x = i+1;
                s.y = j+1;
                graph[j+1][i+1] = 1;
            }
            if(in == 'T'){
                f.x = i+1;
                f.y = j+1;
                graph[j+1][i+1] = 0;
            }
        }
    }

    queue<coord> que;
    que.push(s);
    coord pos;
    while(!que.empty() && ((pos.x != f.x) || (pos.y != f.y)))
    {
        coord now = que.front();
        que.pop();
        if(graph[now.y+1][now.x] == 0)
        {
            graph[now.y+1][now.x] = graph[now.y][now.x] + 1;
            pos.x = now.x;
            pos.y = now.y+1;
            que.push(pos);
        }
        if(graph[now.y-1][now.x] == 0)
        {
            graph[now.y-1][now.x] = graph[now.y][now.x] + 1;
            pos.x = now.x;
            pos.y = now.y-1;
            que.push(pos);
        }
        if(graph[now.y][now.x+1] == 0)
        {
            graph[now.y][now.x+1] = graph[now.y][now.x] + 1;
            pos.x = now.x+1;
            pos.y = now.y;
            que.push(pos);
        }
        if(graph[now.y][now.x-1] == 0)
        {
            graph[now.y][now.x-1] = graph[now.y][now.x] + 1;
            pos.x = now.x-1;
            pos.y = now.y;
            que.push(pos);
        }
    }

    if(graph[f.y][f.x] == 0)
    {
        fout << "-1" << endl;
    }
    else
    {
        int curr = graph[f.y][f.x];
        while((f.y != s.y) || (f.x != s.x))
        {
            if(graph[f.y + 1][f.x] == curr - 1)
            {
                res.push_back('U');
                f.y = f.y + 1;
            }
            else if(graph[f.y - 1][f.x] == curr - 1)
            {
                res.push_back('D');
                f.y = f.y - 1;
            }
            else if(graph[f.y][f.x + 1] == curr - 1)
            {
                res.push_back('L');
                f.x = f.x + 1;
            }
            else if(graph[f.y][f.x - 1] == curr - 1)
            {
                res.push_back('R');
                f.x = f.x - 1;
            }
            curr -= 1;
        }
        reverse(res.begin(), res.end());
        fout << res.size() << endl;
        for(int i = 0; i < res.size(); i++)
            fout << res[i];
        fout << endl;
    }

    return 0;
}
