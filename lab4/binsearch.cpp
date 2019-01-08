#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> a;

int leftBound, rightBound;

void binsearch(int key)
{
    int m;
    int l = -1;
    int r = a.size();
    m = (l + r) / 2;
    while (l < r - 1)
    {
        m = (l + r) / 2;
        if(a[m] < key) l = m;
        else r = m;
    }
    //cout << l << " " << m << " " << r << endl;
    leftBound = r + 1;
    l = -1;
    r = a.size();
    m = (l + r) / 2;
    while (l < r - 1)
    {
        m = (l + r) / 2;
        if(a[m] <= key) l = m;
        else r = m;
    }
    //cout << l << " " << m << " " << r << endl;
    rightBound = l + 1;
}

int main()
{
    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");

    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        int in;
        fin >> in;
        a.push_back(in);
    }
    int n2;
    fin >> n2;
    int tofind;
    for(int i = 0; i < n2; i++)
    {
        fin >> tofind;
        binsearch(tofind);
        int res = rightBound - leftBound;
        if (res < 0)
            fout << "-1 -1" << endl;
        else
            fout << leftBound << " " << rightBound << endl;
    }
    return 0;
}
