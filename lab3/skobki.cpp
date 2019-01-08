#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector <char> stek;

int main()
{
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    string in;
    while(fin >> in)
    {
        bool result = true;
        for(int i = 0; i < in.length(); i++)
        {
            if ((in[i] == '(') || (in[i] == '['))
                stek.push_back(in[i]);
            if (((in[i] == ')') || (in[i] == ']')) && (stek.size() < 1))
            {
                result = false;
                break;
            }
            if (in[i] == ')')
            {
                if (stek[stek.size() - 1] == '(')
                    stek.pop_back();
                else{
                    result = false;
                    break;
                }
            }
            if (in[i] == ']')
            {
                if (stek[stek.size() - 1] == '[')
                    stek.pop_back();
                else{
                    result = false;
                    break;
                }
            }
        }
    if(stek.size() > 0) result = false;
    if (result)
        fout << "YES" << endl;
    else
        fout << "NO" << endl;
    stek.clear();
    }
    return 0;
}
