#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int T_S = 200;

class HashTableEntry {
   public:
      char k;
      string v;
      HashTableEntry(char k, string v) {
         this->k = k;
         this->v = v;
      }
};

int main(void){
    HashTableEntry **t;
    t = new HashTableEntry * [T_S];
    for (int i = 0; i< T_S; i++) {
        char c = i;
        t[i] = new HashTableEntry('T',"ony");
    }
    cout << t[0]->k << t[0]->v << endl;
    return 0;
}