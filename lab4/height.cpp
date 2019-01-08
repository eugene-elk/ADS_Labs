#include <iostream>
#include <fstream>

using namespace std;

int a[200001][3];

int res = -1;

void findh(int k, int h)
{
    if (a[k][1] != 0)
        findh(a[k][1], h + 1);
    else
    {
        if (h > res) res = h;
    }
    if (a[k][2] != 0)
        findh(a[k][2], h + 1);
    else
    {
        if (h > res) res = h;
    }
}

int main()
{
    ifstream fin("height.in");
    ofstream fout("height.out");
    int n;

    fin >> n;

    for(int i = 1; i <= n; i++)
    {
        fin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    if(n != 0){
        findh(1, 1);
        fout << res;
    }
    else
    {
        fout << 0;
    }
    return 0;
}
