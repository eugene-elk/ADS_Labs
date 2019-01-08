#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

vector <int> stek;

int main()
{
    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    string in;
    int result;
    int x_in, x1, x2;
    while (fin >> in)
    {
        if ((in == "+") || (in == "-") || (in == "*"))
        {
            x1 = stek[stek.size() - 1];
            x2 = stek[stek.size() - 2];
            if (in == "+")
                stek[stek.size() - 2] = x2 + x1;
            if (in == "-")
                stek[stek.size() - 2] = x2 - x1;
            if (in == "*")
                stek[stek.size() - 2] = x2 * x1;
            stek.pop_back();
        }
        else
        {
            x_in = atoi(in.c_str());
            stek.push_back(x_in);
        }
    }
    fout << stek[0];
    return 0;
}
