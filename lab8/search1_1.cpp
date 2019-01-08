#include <iostream>
#include <fstream>
#include <string>
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

    queue<char> tmp;
    queue<char> tmp2;

    for(int i = 0; i < str.size(); i++)
    {
        tmp.push(str[i]);
    }

    for(int i = 0; i < to_find.size(); i++)
    {
        tmp2.push(to_find[i]);
    }

    int i = 1;
    int n = to_find.length();

    while(n <= str.length())
    {
        if (tmp == tmp2) res.push_back(i);
        i += 1;
        tmp.pop();
        tmp.push(str[n]);
        n += 1;
    }

    fout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        fout << i << " ";

    return 0;
}


