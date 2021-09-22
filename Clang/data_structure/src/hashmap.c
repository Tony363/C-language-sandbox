#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000

struct DataItem
{
    double data;
    char key[];
};

struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;

int hashCode(int key)
{
    return key % SIZE;
}

unsigned long hash(const char *str)
{
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        hash = ((int)(*str - '0') + hash) + c; /* hash * 33 + c */

    return hash;
}

struct DataItem *search(const char *key)
{
    //get the hash
    int hashIndex = hash(key);

    //move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (strcmp(hashArray[hashIndex]->key, key) == 0)
            return hashArray[hashIndex];

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(const char *key, double data)
{
    struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
    item->data = data;
    strcpy(item->key, key);
    //get the hash
    int hashIndex = hash(key);
    //move in array until an empty or deleted cell
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != "")
    {
        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem *delete (struct DataItem *item)
{
    char *key = item->key;

    //get the hash
    int hashIndex = hash(key);

    //move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (strcmp(hashArray[hashIndex]->key, key) == 0)
        {
            struct DataItem *temp = hashArray[hashIndex];

            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display()
{
    int i = 0;
    printf("{\n");
    for (i = 0; i < SIZE; i++)
    {

        if (hashArray[i] != NULL)
            printf("\t%s:%lf,\n", hashArray[i]->key, hashArray[i]->data);
    }
    printf("}\n");
}

// int main()
// {
//     dummyItem = (struct DataItem *)malloc(sizeof(struct DataItem));
//     dummyItem->data = 0;
//     strcpy(dummyItem->key, "");

//     insert("twenty", 20.0);
//     insert("seventy", 70);
//     insert("fourty-two", 80);
//     insert("twenty-five", 25);
//     insert("fourty-four", 44);
//     insert("thirty-two", 32);
//     insert("eleven", 11);
//     insert("seventy-eight", 78);
//     insert("ninety-seven", 97);

//     display();
//     item = search("twenty");

//     if (item != NULL)
//     {
//         printf("Element found: %lf\n", item->data);
//     }
//     else
//     {
//         printf("Element not found\n");
//     }

//     delete (item);
//     item = search("ninety-seven");

//     if (item != NULL)
//     {
//         printf("Element found: %lf\n", item->data);
//     }
//     else
//     {
//         printf("Element not found\n");
//     }
//     return 0;
// }