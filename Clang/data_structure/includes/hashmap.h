#ifndef HASHMAP_H
#define HASHMAP_H
unsigned long hash(const char *str);
void insert(const char *key, double data);
struct DataItem *search(const char *key);
struct DataItem *delete (struct DataItem *item);
void display();
#endif