#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
    vector <int> a;
    int num;
    bool result = true;
    fin >> num;
    int x;
    a.push_back(0);
    for (int i = 1; i <= num; i++)
    {
        fin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= num; i++)
    {
        if (((2 * i <= num) && (a[i] > a[2 * i])) || ((2 * i + 1 <= num) && (a[i] > a[2 * i + 1])))
        {
            result = false;
            break;
        }
    }
    if (result)
        fout << "YES";
    else
        fout << "NO";
    return 0;
}
