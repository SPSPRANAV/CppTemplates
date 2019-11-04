#include<bits/stdc++.h>
using namespace std;
struct item {
    int key, priority;
    item * left, * right;
    item() { }
    item (int key, int priority) : key(key), priority(priority), left(NULL), right(NULL) { }
};
typedef item * node;

void split (node t, int key, node & left, node & right) {
    if (!t)
        left = right = NULL;
    else if (key < t->key)
        split (t->left, key, left, t->left),  right = t;
    else
        split (t->right, key, t->right, right),  left = t;
}

void insert (node & t, node it) {
    if (!t)
        t = it;
    else if (it->priority > t->priority)
        split (t, it->key, it->left, it->right),  t = it;
    else
        insert (it->key < t->key ? t->left : t->right, it);
}

void merge (node & t, node left, node right) {
    if (!left || !right)
        t = left ? left : right;
    else if (left->priority > right->priority)
        merge (left->right, left->right, right),  t = left;
    else
        merge (right->left, left, right->left),  t = right;
}

void erase (node & t, int key) {
    if (t->key == key)
        merge (t, t->left, t->right);
    else
        erase (key < t->key ? t->left : t->right, key);
}

node unite (node left, node right) {
    if (!left || !right)  return left ? left : right;
    if (left->priority < right->priority)  swap (left, right);
    node lt, rt;
    split (right, left->key, lt, rt);
    left->left = unite (left->left, lt);
    left->right = unite (left->right, rt);
    return left;
}
int main()
{



return 0;
}
