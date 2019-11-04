#include<bits/stdc++.h>
using namespace std;
//Methods that are implemented are :
//loadFactor()
// add                   |       all keys
// remove                |       all values
// find                  |       size
// change_value          |       is Empty/Full
const int tablesize = 37;//Some constant number,preferably prime number

struct hash_node {
    int val, key;
    hash_node* next;
    hash_node* prev;
};
class HashMap {
public:
    hash_node **hashtable, **top;

  // HAshMap function Creates an empty hashtable
    HashMap()
    {
        hashtable = new hash_node*[tablesize];
        top = new hash_node*[tablesize];
        for (int i = 0; i < tablesize; i++) {
            hashtable[i] = NULL;
            top[i] = NULL;
        }
    }

    // Destructor
    ~HashMap()
    {
        delete[] hashtable;
    }

    //Hash function
    //Can be an arbitrary function according to the question asked
    int HashFunc(int key)
    {
        return key % tablesize;
    }

    //Finds the key in the hashmap in best case time of O(1) and worst case of O(n)
    int find(int key)
    {
        // Applying hashFunc to find
        int out_val=-1;
        int hash_val = HashFunc(key);
        bool flag = false;
        hash_node* entry = hashtable[hash_val];

        // if hashtable at that index has some
        // values stored
        if (entry != NULL) {
            while (entry != NULL) {
                if (entry->key == key) {
                    flag = true;
                }
                if (flag) {

                    out_val= entry->val ;
                }
                entry = entry->next;
            }
        }
        if (!flag)
            {;}
        return out_val;
    }

    // removing an element
    int remove(int key)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        hash_node* entry = hashtable[hash_val];
        if (entry->key != key || entry == NULL)
         {

            return -1;
        }
        while (entry != NULL) {
            if (entry->next == NULL) {
                if (entry->prev == NULL) {
                    hashtable[hash_val] = NULL;
                    top[hash_val] = NULL;
                    delete entry;
                    break;
                }
                else {
                    top[hash_val] = entry->prev;
                    top[hash_val]->next = NULL;
                    delete entry;
                    entry = top[hash_val];
                }
            }
            entry = entry->next;
        }
        return 0;
    }

    // inserting method
    int add(int key, int value)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        hash_node* entry = hashtable[hash_val];

        // if key has no value stored
        if (entry == NULL) {
            // creating new node
            entry = new hash_node;
            entry->val = value;
            entry->key = key;
            entry->next = NULL;
            entry->prev = NULL;
            hashtable[hash_val] = entry;
            top[hash_val] = entry;
        }

        // if some values are present
        else {
            // traversing till the end of
            // the list
            while (entry != NULL)
                entry = entry->next;

            // creating the new node
            entry = new hash_node;
            entry->val = value;
            entry->key = key;
            entry->next = NULL;
            entry->prev = top[hash_val];
            top[hash_val]->next = entry;
            top[hash_val] = entry;
        }
        return 1;
    }
};
int main()
{



return 0;
}
