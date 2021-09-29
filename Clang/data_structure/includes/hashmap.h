#ifndef HASHMAP_H
#define HASHMAP_H
#define SIZE 10000
struct DataItem
{
    double data;
    char key[];
};
struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;
unsigned long hash(const char *str);
void insert(const char *key, double data);
struct DataItem *search(const char *key);
struct DataItem *delete (struct DataItem *item);
void display();
#endif