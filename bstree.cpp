#include <bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *tmp = new node();
	tmp->key = item;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key)
{

	if (node == NULL) return newNode(key);


	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

struct node * minkeynode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
		{
			 cout<<"The key required to be deleted is not present\n";
			 return root;
		 }

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            struct node *tmp = root->left;
            free(root);
            return tmp;
        }

        struct node* tmp = minkeynode(root->right);
        root->key = tmp->key;

        root->right = deleteNode(root->right, tmp->key);
    }
    return root;
}

void postorder( node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
void preorder( node* root) {
        if(root == NULL) return;
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }

int main()
{

	struct node *root = NULL;
	int q=-1;
	while(q!=0)
	{
		cin>>q;
		if(q==1)
		{
			int x;
			cin>>x;
			root = insert(root,x);
		}
		if(q==2)
		{
			int x;
			cin>>x;
			root = deleteNode(root,x);
		}
		if(q==3)
		{
			node* min = minkeynode(root);
			if(root!=NULL)
			cout<<root->key<<"\n";
			else
				cout<<"Tree is empty\n";
		}
		if(q==4)
		{
			inorder(root);
			cout<<endl;
		}
		if(q==5)
		{
			preorder(root);
			cout<<endl;
		}
		if(q==6)
		{
			postorder(root);
			cout<<endl;
		}
	}

	return 0;
}
