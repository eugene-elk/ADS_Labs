#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

vector<string> countries;
map <string, int> cnt;
map <string, vector<string> > names;

void qsort1(int left, int right)
{
    int x = (rand()%(right - left + 1)) + left;
    string key = countries[x];
    //int key = a[(left + right) / 2];
    int i = left;
    int j = right;
    while(i <= j)
    {
        while(countries[i] < key) i++;
        while(countries[j] > key) j--;
        if(i <= j)
        {
            swap(countries[i], countries[j]);
            i++;
            j--;
        }
    }
    if(i < right)
        qsort1(i, right);
    if(left < j)
        qsort1(left, j);
}

int main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int num;
    cin >> num;
    string country, name;
    for(int i = 0; i < num; i++)
    {
        cin >> country >> name;
        names[country].push_back(name);
        cnt[country]++;
        if(cnt[country] == 1) countries.push_back(country);
    }
    int x = 0;
    qsort1(x, countries.size() - 1);
    for(int i = 0; i < countries.size(); i++)
    {
        cout << "=== " << countries[i] << " ===" << endl;
        for(int j = 0; j < cnt[countries[i]]; j++)
            cout << names[countries[i]][j] << endl;
    }
    return 0;
}
