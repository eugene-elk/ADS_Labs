#include <iostream>
#include <fstream>

using namespace std;

double res;

void binsearch(int n, double a)
{
    double l = 0;
    double r = a;
    for (int i = 0; i < 100; i++)
    {
        double now = (l + r) / 2;
        double h0 = a;
        double h1 = now;
        int c = 0;
        if (h0 <= 0) c += 1;
        if (h1 <= 0) c += 1;
        for (int i = 0; i < n - 2; i++)
        {
            res = (2 * h1) + 2 - h0;
            if (res <= 0) c += 1;
            h0 = h1;
            h1 = res;
        }
        if (c >= 1) l = now;
        else r = now;
    }
}

int main()
{
    ifstream fin("garland.in");
    ofstream fout("garland.out");
    int n;
    double a;
    fin >> n >> a;

    binsearch(n, a);

    fout << fixed;
    fout.precision(2);
    fout << res;

    return 0;
}
