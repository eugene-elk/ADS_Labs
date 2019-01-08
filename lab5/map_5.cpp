#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct collision_list
{
    string key;
    string value;
    collision_list* parent;
    collision_list* child;
};

vector<collision_list *> table(10000000);

int getNum(string key)
{
    const int p = 31;
    unsigned long long res = 0; //HASH
    long long p_pow = 1;
    for (int i = 0; i < key.length(); i++)
    {
        res = res + ((key[i] - 'a' + 1) * p_pow);
        p_pow *= p;
    }
    return (res%10000000);
}

string result(collision_list *to_find, string key) {
    if (to_find == NULL)
    {
        return "none";
    }
    else if (to_find->key == key)
    {
        return (to_find->value);
    }
    else
    {
        return (result(to_find->child, key));
    }
}

void addCollision(collision_list *collision, string key, string value)
{
    if (collision->key == key) collision->value = value;
    else if (collision->child == NULL)
    {
        collision_list *node = new(collision_list);
        node->key = key;
        node->value = value;
        node->parent = collision;
        node->child = NULL;
        collision->child = node;
    }
    else addCollision(collision->child, key, value);
}

void addNew(string key, string value) {
    int num = getNum(key);
    if (table[num] == NULL)
    {
        collision_list *node = new(collision_list);
        node->key = key;
        node->value = value;
        node->parent = NULL;
        node->child = NULL;
        table[num] = node;
    }
    else addCollision(table[num], key, value);
}

void del(collision_list *to_delete, string key) {
    if (to_delete != NULL)
    {
        if (to_delete->key == key)
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
        else
            del(to_delete->child, key);
    }
}

int main()
{
    ifstream fin("map.in");
    ofstream fout("map.out");
    string command;
    string key, value;
    while(fin >> command)
    {
        if(command == "put"){
            fin >> key >> value;
            addNew(key, value);
        }
        if(command == "get"){
            fin >> key;
            fout << result(table[getNum(key)], key) << endl;
        }
        if(command == "delete"){
            fin >> key;
            del(table[getNum(key)], key);
        }
    }
}
