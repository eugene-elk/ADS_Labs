#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> stek;

int main()
{
    ifstream fin("stack.in");
    ofstream fout("stack.out");
    int num, x;
    char todo;
    int len = 0;
    fin >> num;
    for (int i = 0; i < num; i++)
    {
        fin >> todo;
        if (todo == '+'){
            fin >> x;
            stek.push_back(x);
        }
        if (todo == '-'){
            fout << stek[stek.size() - 1] << endl;
            stek.pop_back();
        }
    }
    return 0;
}
