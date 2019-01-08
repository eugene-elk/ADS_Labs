#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    int num;
    cin >> num;
    int arr[num];
    for(int i = 0; i < num; i++)
        arr[i] = i + 1;
    for(int i = 2; i < num; i++)
    {
        cout << i << " " << i/2 << endl;
        swap(arr[i], arr[i/2]);
    }
    for(int i = 0; i < num; i++)
        cout << arr[i] << " ";
    return 0;
}
