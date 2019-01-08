#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> que;

int main()
{
    ifstream fin("queue.in");
    ofstream fout("queue.out");
    int num, x;
    char todo;
    int len = 0;
    fin >> num;
    for (int i = 0; i < num; i++)
    {
        fin >> todo;
        if (todo == '+'){
            fin >> x;
            que.push_back(x);
        }
        if (todo == '-'){
            fout << que[0] << endl;
            que.erase(que.begin());
        }
    }
    return 0;
}
