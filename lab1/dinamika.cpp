#include <iostream>
#include <stdio.h>

using namespace std;

int in_arr[1001][1001];
int res_arr[1001][1001];

int main()
{
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);
    int w, h;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
        {
            cin >> in_arr[i+1][j+1];
        }
    }
    res_arr[h][1] = in_arr[h][1];
    for(int i = h; i > 0; i--){
        for(int j = 1; j < w+1; j++)
        {
            res_arr[i][j] = max(res_arr[i+1][j], res_arr[i][j-1]) + in_arr[i][j];
        }
    }
    cout << res_arr[1][w];
    /*
    cout << "input array" << endl;
    for(int i = 1; i < h+1; i++){
        for(int j = 1; j < w+1; j++){
            cout << in_arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "output array" << endl;
    for(int i = 1; i < h+1; i++){
        for(int j = 1; j < w+1; j++){
            cout << res_arr[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
