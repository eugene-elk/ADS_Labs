#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
    vector <int> a;
    int n, i, k = 0;
    fin >> n;
    int x;
    a.push_back(0);
    for (i = 1; i <= n; i++)
    {
        fin >> x;
        a.push_back(x);
    }
    for (i = 0; i <= n; i++)
    {
        if (2 * i <= n)
        if (a[i] > a[2 * i])
        {
            fout << "NO";
            k++;
            break;
        }
        if (2 * i + 1 <= n)
        if (a[i] > a[2 * i + 1])
        {
            fout << "NO";
            k++;
            break;
        }
    }
    if (k == 0)
    fout << "YES";
    return 0;
}
