include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
unsigned long long maxdva = int(pow(2,64));
struct my {
    string key;
    string value;
    my *parent;
    my *child;
};

vector<my*> table(10000000);

int Num(string str) {
    unsigned long long answer = 0;
    for (int i = 0; i < str.length(); i++) {
        answer = (answer + int(str[i]) * int(pow(31, i))) % maxdva;
    }
    return (answer % 10000000);
}

void addlist(my* now, string k, string v){
    if (now->key == k){
        now->value = v;
    } else
    if (now->child == NULL){
        my* node = new(my);
        node->key = k;
        node->value = v;
        node->parent = now;
        node->child = NULL;
        now->child = node;
    } else {
        addlist(now->child, k, v);
    }
}

void add(string k, string v){
    int place = Num(k);
    if (table[place] == NULL){
        my* now = new(my);
        now->key = k;
        now->value = v;
        now->parent = NULL;
        now->child = NULL;
        table[place] = now;
    } else{
        addlist(table[place], k, v);
    }
}


void del(my* now, string k){
    if (now != NULL){
        if (now->key == k){
            if ((now->parent == NULL) && (now->child == NULL)){
                table[Num(k)] = NULL;
            } else
            if ((now->parent != NULL) && (now->child == NULL)){
                now->parent->child = NULL;
            } else
            if ((now->parent != NULL) && (now->child != NULL)){
                now->parent->child = now->child;
                now->child->parent = now->parent;
            } else
            if ((now->parent == NULL) && (now->child != NULL)){
                now->child->parent = NULL;
                table[Num(k)] = now->child;
            }
        } else del(now->child, k);
    }
}

string get(my* now, string k){
    if (now == NULL) {
        return "none";
    } else
    if (now->key == k){
        return (now->value);
    } else return (get(now->child, k));
}

int main(){
    ifstream cin ("map.in");
    ofstream cout ("map.out");
    string c;
    while (cin >> c){
        string k, v;
        if (c == "put"){
            cin >> k;
            cin >> v;
            add(k, v);
        } else
        if (c == "delete") {
            cin >> k;
            del(table[Num(k)] , k);
        } else
        if (c == "get"){
            cin >> k;
            cout << get(table[Num(k)], k) << endl;
        }
    }
    return 0;
}
