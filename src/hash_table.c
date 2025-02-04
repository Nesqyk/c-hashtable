#include <stdlib.h>
#include <string.h>



// I have no clue why I'm learning hashtables.
//
#include "hash_table.h"


static ht_item* ht_new_item(const char *k, const char *v) 
{
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(k);
    return i;
}

ht_hash_table* ht_new() 
{
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));
    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t) ht->size, sizeof(ht_item));
    return ht;
}

void ht_del_item(ht_item *i)
{
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table *ht)
{
    for(int i = 0 ; i  < ht->size; i ++)
    {
        ht_item* item =  ht->items[i];
        if(item != NULL)
        {
            ht_del_item(item);
        }
    }

    free(ht->items);
    free(ht);
}


/*
function hash(string, a, num_buckets):
    hash = 0
    string_len = length(string)
    for i = 0, 1, ..., string_len:
        hash += (a ** (string_len - (i+1))) * char_code(string[i])
    hash = hash % num_buckets
    return hash
*/

static int hash(const char* s, const int i, const int m)
{
    
}
