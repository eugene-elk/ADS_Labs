#include <iostream>
#include <stdio.h>

using namespace std;

int arr[10000];

int main()
{
    freopen("smallsort.in", "r", stdin);
    freopen("smallsort.out", "w", stdout);
    int s;
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    int key;
    for(int j = 1; j < s; j++)
    {
        key = arr[j];
        int i = j - 1;
        while((i >= 0) && (arr[i] > key))
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
    for(int i = 0; i < s; i++){
        cout << arr[i] << " ";
    }
}
