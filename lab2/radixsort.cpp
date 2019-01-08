#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector <string> a;

int num, len, k;

void radixsort()
{
    map <char, vector<string> > podschet;
    for(int i = len - 1; i > len - 1 - k; i--)
    {
        for(int j = 0; j < num; j++)
        {
            podschet[a[j][i]].push_back(a[j]);
        }
        int x = 0;
        for(char r = 'a'; r <= 'z'; r++)
        {
            for(int v = 0; v < podschet[r].size(); v++)
            {
                a[x] = podschet[r][v];
                x++;
            }
        }
        podschet.clear();
    }
}

int main()
{
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");

    fin >> num >> len >> k;
    string in;
    for(int i = 0; i < num; i++)
    {
        fin >> in;
        a.push_back(in);
    }
    radixsort();
    for(int i = 0; i < num; i++)
    {
        fout << a[i] << endl;
    }
    return 0;
}
