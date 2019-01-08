#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<bool> h_table(2000000001);

int main()
{
    ifstream fin("set.in");
    ofstream fout("set.out");
    string command;
    int num;
    while(fin >> command)
    {
        fin >> num;
        num += 1000000000;
        if(command == "insert") h_table[num] = true;
        if(command == "delete") h_table[num] = false;
        if(command == "exists") {
            if(h_table[num]) fout << "true" << endl;
            else fout << "false" << endl;
        }
    }
    return 0;
}
