#include <iostream>
#include <stdio.h>

using namespace std;

float arr[10000];
int nums[10000];

int main()
{
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
    int s;
    float t1;
    int t2;
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        cin >> arr[i];
        nums[i] = i + 1;
    }
    for (int i = s - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t1;
                t2 = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t2;
            }
        }
    }
    cout << nums[0] << " " << nums[s/2] << " " << nums[s-1];
}
