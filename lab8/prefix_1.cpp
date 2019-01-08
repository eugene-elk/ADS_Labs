#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string s;

    fin >> s;


	vector<int> res(s.length(), 0);
	for (int i = 1; i < s.length(); i++)
    {
		int j = res[i-1];
		while (j > 0 && s[i] != s[j])
        {
			j = res[j-1];
        }
		if (s[i] == s[j])
        {
            j++;
        }
		res[i] = j;
	}

	for(int i = 0; i < res.size(); i++)
        fout << res[i] << " ";
    return 0;
}
