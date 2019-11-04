#include<bits/stdc++.h>
using namespace std;
struct node
{
  int val;
  node* next;
  node* prev;
};
node* makelist(int x)
{
  node* head= new node;
  head->val=x;
  head->next=NULL;
  head->prev=NULL;
  return head;
}
void add_first(int x,node* list)
{
  node* added=new node;
  added->val=x;
  added->next=list;
  added->prev=NULL;
  list->prev=added;
  list=added;
}

int main()
{
int a=2,b=3;
node* head=makelist(a);
add_first(b,head);


return 0;
}
