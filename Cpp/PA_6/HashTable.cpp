#include <iostream>
#include <HashTable.h>
using namespace std;

const int T_S = 200;

HashTableEntry::HashTableEntry(char k, string v) {
    this->k = k;
    this->v = v;
}
HashTableEntry::~HashTableEntry(){
    
}

HashMapTable::HashMapTable() {
    t = new HashTableEntry * [T_S];
    for (int i = 0; i< T_S; i++) {
        t[i] = NULL;
    }
}
int HashMapTable::HashFunc(int k) {
    return k % T_S;
}
void HashMapTable::Insert(char k, string v) {
    int h = HashFunc((int)k);
    while (t[h] != NULL && t[h]->k != k) {
        h = HashFunc(h + 1);
    }
    if (t[h] != NULL)
        delete t[h];
    t[h] = new HashTableEntry(k, v);
}
string HashMapTable::SearchKey(char k) {
    int h = HashFunc((int)k);
    while (t[h] != NULL && t[h]->k != k) {
        h = HashFunc(h + 1);
    }
    if (t[h] == NULL)
        return "NONE";
    else
        return t[h]->v;
}
void HashMapTable::Remove(char k) {
    int h = HashFunc((int)k);
    while (t[h] != NULL) {
        if (t[h]->k == k)
            break;
        h = HashFunc(h + 1);
    }
    if (t[h] == NULL) {
        cout<<"No Element found at key "<<k<<endl;
        return;
    } else {
        delete t[h];
        // cout <<"wtf"<< (t[h] == NULL) << endl;
    }
    cout<<"Element Deleted"<<endl;
}
HashMapTable::~HashMapTable() {
    for (int i = 0; i < T_S; i++) {
        if (t[i] != NULL){
            delete t[i];
        }
    }
    delete[] t;
}