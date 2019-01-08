#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct oneWay
{
    string key;
    string value;
    oneWay* parent;
    oneWay* child;
};

vector<oneWay *> table(10000000);

int getNum(string key)
{
    const int p = 31;
    long long res = 0; //HASH
    long long p_pow = 1;
    for (int i = 0; i < key.length(); i++)
    {
        res += (key[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return (res%100000);
}

void addInList(oneWay *current, string key, string value)
{
    if (current->key == key)
    {
        current->value = value;
    }
    else if (current->child == NULL)
    {
        oneWay *node = new(oneWay);
        node->key = key;
        node->value = value;
        node->parent = current;
        node->child = NULL;
        current->child = node;
    }
    else
    {
        addInList(current->child, key, value);
    }
}

void add(string key, string value) {
    int where = getNum(key);
    if (table[where] == NULL)
    {
        oneWay *node = new(oneWay);
        node->key = key;
        node->value = value;
        node->parent = NULL;
        node->child = NULL;
        table[where] = node;
    }
    else
    {
        addInList(table[where], key, value);
    }
}

string getValue(oneWay *where, string key) {
    if (where == NULL)
    {
        return "none";
    }
    else if (where->key == key)
    {
        return (where->value);
    }
    else
        return (getValue(where->child, key));
}

void kill(oneWay *where, string key) {
    if (where != NULL)
    {
        if (where->key == key)
        {
            if ((where->parent == NULL) && (where->child == NULL))
            {
                table[getNum(key)] = NULL;
            }
            else if (where->parent == NULL)
            {
                where->child->parent = NULL;
                table[getNum(key)] = where->child;
            }
            else if (where->child == NULL)
            {
                where->parent->child = NULL;
            }
            else
            {
                where->parent->child = where->child;
                where->child->parent = where->parent;
            }
        }
        else
            kill(where->child, key);
    }
}

int main()
{
    ifstream fin("map.in");
    ofstream fout("map.out");
    string command;
    string key, value;
    int temp;
    while(fin >> command)
    {
        if(command == "put"){
            fin >> key >> value;
            add(key, value);
        }
        if(command == "get"){
            fin >> key;
            temp = getNum(key);
            fout << getValue(table[temp], key) << endl;
        }
        if(command == "delete"){
            fin >> key;
            kill(table[getNum(key)], key);
        }
    }
}
