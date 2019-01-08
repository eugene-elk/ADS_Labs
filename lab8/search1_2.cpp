#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ifstream fin("search1.in");
	ofstream fout("search1.out");

    vector <int> res;

    string to_find, str;
    fin >> to_find >> str;

    int n = str.length();
    int m = to_find.length();

    for(int i = 0; i < n - m + 1; i++)
    {
        string tmp;
        tmp = "";
        for(int x = i; x < i + m; x++)
        {
            tmp.push_back(str[x]);
        }
        if(tmp == to_find)
        {
            res.push_back(i + 1);
        }
    }

    fout << res.size() << endl;
    for(int i = 0; i < res.size(); i++)
        fout << res[i] << " ";

    return 0;
}
