#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int a[200001][3];
bool exist[200001];
vector<int> sort_tree;

void inorderTraversal(int k)
{
    if(exist[k])
    {
        inorderTraversal(a[k][1]);
        sort_tree.push_back(a[k][0]);
        inorderTraversal(a[k][2]);
    }
}

bool issorted() {
    for (int i = 0; i <= sort_tree.size() - 2; i++)
        if (sort_tree[i] >= sort_tree[i + 1])
            return false;
    return true;
}


int main()
{
    ifstream fin("check.in");
    ofstream fout("check.out");
    int n;

    fin >> n;
    for(int i = 0; i <= 200001; i++)
        exist[i] = false;
    for(int i = 1; i <= n; i++)
    {
        fin >> a[i][0] >> a[i][1] >> a[i][2];
        exist[i] = true;
    }

    if(n == 0)
        fout << "YES";
    else
    {
        inorderTraversal(1);
        bool res = issorted();
        if (res)
            fout << "YES";
        else
            fout << "NO";
    }
    return 0;
}
