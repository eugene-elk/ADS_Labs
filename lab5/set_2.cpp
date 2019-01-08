#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct collision_list
{
    int key;
    bool value;
    collision_list* parent;
    collision_list* child;
};

vector<collision_list *> table(100000);

int getNum(int key)
{
    int res = abs(key);
    res = res%(100000);
    return res;
}

bool result(collision_list *where, int key) {
    if (where == NULL) return false;
    else if (where->key == key) return (where->value);
    else return (result(where->child, key));
}

void addCollision(collision_list *collision, int key)
{
    if (collision->key == key) collision->value = true;
    else if (collision->child == NULL)
    {
        collision_list *node = new(collision_list);
        node->key = key;
        node->value = true;
        node->parent = collision;
        node->child = NULL;
        collision->child = node;
    }
    else addCollision(collision->child, key);
}

void addNew(int key) {
    int num = getNum(key);
    if (table[num] == NULL)
    {
        collision_list *node = new(collision_list);
        node->key = key;
        node->value = true;
        node->parent = NULL;
        node->child = NULL;
        table[num] = node;
    }
    else addCollision(table[num], key);
}

void del(collision_list *to_delete, int key) {
    if (to_delete != NULL)
    {
        if (to_delete->key != key)
            del(to_delete->child, key);
        else
        {
            if ((to_delete->parent == NULL) && (to_delete->child == NULL))
                table[getNum(key)] = NULL;
            else if (to_delete->parent == NULL)
            {
                to_delete->child->parent = NULL;
                table[getNum(key)] = to_delete->child;
            }
            else if (to_delete->child == NULL)
                to_delete->parent->child = NULL;
            else
            {
                to_delete->parent->child = to_delete->child;
                to_delete->child->parent = to_delete->parent;
            }
        }
    }
}

int main()
{
    ifstream fin("set.in");
    ofstream fout("set.out");
    string command;
    int key;
    while(fin >> command)
    {
        if(command == "insert"){
            fin >> key;
            addNew(key);
        }
        if(command == "exists"){
            fin >> key;
            if(result(table[getNum(key)], key)) fout << "true" << endl;
            else fout << "false" << endl;
        }
        if(command == "delete"){
            fin >> key;
            del(table[getNum(key)], key);
        }
    }
}
