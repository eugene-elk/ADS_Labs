#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("search1.in");
    ofstream fout("search2.out");

    string to_find, str, str2;
    fin >> to_find >> str;

    str2 = to_find + str;

    vector<int> res(str2.length(), 0);
	for (int i = 1; i < str2.length(); i++)
    {
		int j = res[i-1];
		while (j > 0 && str2[i] != str2[j])
        {
			j = res[j-1];
        }
		if (str2[i] == str2[j])
        {
            j++;
        }
		res[i] = j;
	}

    vector<int> res2;
    for(int i = 0; i < res.size(); i++)
    {
        if(res[i] == to_find.length()) res2.push_back(i - (2*to_find.length()) + 2);
    }

    fout << res2.size() << endl;
    for(int i = 0; i < res2.size(); i++)
    {
        fout << res2[i] << " ";
    }

}
