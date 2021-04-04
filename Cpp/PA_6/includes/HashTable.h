#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class HashTableEntry {
   public:
      char k;
      string v;
      HashTableEntry(char k, string v);
    ~HashTableEntry();
};

class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable();
      int HashFunc(int k);
      void Insert(char k, string v);
      string SearchKey(char k);
      void Remove(char k);
      ~HashMapTable();
};

#endif