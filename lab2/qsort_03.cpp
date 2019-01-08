#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<string> a;

void qsort1(int left, int right)
{
    int x = (rand()%(right - left + 1)) + left;
    string key = a[x];
    //int key = a[(left + right) / 2];
    int i = left;
    int j = right;
    while(i <= j)
    {
        while(a[i] < key) i++;
        while(a[j] > key) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
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
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int num;
    string y;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> y;
        a.push_back(y);
    }
    int x = 0;
    qsort1(x, num - 1);
    for(int i = 0; i < num; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
