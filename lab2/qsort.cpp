#include <iostream>
#include <stdio.h>

using namespace std;

void qsort(int left, int right, int a[])
{
    if ((right - left) > 1)
    {
        int key = a[(left + right) / 2];
        int i = left;
        int j = right - 1;

        while (i < j)
        {
            while (a[i] < key) i++;
            while (a[j] > key) j--;
            if(i < j)
            {
                swap(a[i], a[j]);
                if (a[i] != key) i++;
                if (a[j] != key) j--;
            }
        }
        qsort(i + 1, right, a);
        qsort(left, i, a);
    }
}

int main()
{
    int a[100001];

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int num;
    cin >> num;
    for(int x = 0; x < num; x++)
    {
        cin >> a[x];
    }
    qsort(0, num, a);
    for(int x = 0; x < num; x++)
    {
        cout << a[x] << " ";
    }
}
