#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector <int> arr;
long long result;

void mergeSort(int left, int right)
{
    if ((right - left) < 2)
        return;
    /*
    if ((right - left) == 2)
    {
        if(arr[left] > arr[right - 1])
        {
            swap(arr[left], arr[right - 1]);
            result += 1;
        }
        return;
    }
    */
    mergeSort(left, (left + right)/2);
    mergeSort((left + right)/2, right);
    vector<int> t;
    int left1 = left;
    int right1 = (left + right)/2;
    int left2 = (left + right)/2;
    int right2 = right;
    while(t.size() < right - left)
    {
        if((left1 >= right1) || ((left2 < right) && (arr[left2] < arr[left1])))
        {
            t.push_back(arr[left2]);
            left2 += 1;
            result += (right1 - left1);
        }
        else
        {
            t.push_back(arr[left1]);
            left1 += 1;
        }
    }
    for(int i = left; i < right; i++)
    {
        arr[i] = t[i - left];
    }
}

int main()
{
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    result = 0;
    int num;
    int y;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> y;
        arr.push_back(y);
    }
    int x = 0;
    mergeSort(x, num);
    /*
    for(int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    */
    cout << result;
    return 0;
}
