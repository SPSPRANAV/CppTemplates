#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    int key;
    Node* left;
    Node* right;
public:
    Node *newNode(int key){
        Node *a = ( Node*)malloc(sizeof( Node));
        a->key=key;
        a->left=NULL;
        a->right=NULL;
        return a;
    }

    Node *right_insert( Node *root, int key){
    	if(root == NULL) return newNode(key);
    	root->right =  right_insert(root->right, key);
    	return root;
    }

    Node *left_insert( Node *root, int key){
    	if(root == NULL) return newNode(key);
    	root->left =  left_insert(root->left, key);
    	return root;
    }

    void inorder( Node* root)
    {
        if (!root) return;
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }

    void preorder( Node* root) {
        if(root == NULL) return;
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder( Node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }

    bool find( Node* root, int key)
    {
        if (root == NULL)
            return false;

        if (root->key == key)
            return true;

        bool l = find(root->left, key);

        bool r = find(root->right, key);

        return l || r;
    }
};

int main(){
  Node *root = NULL;
	root = root->left_insert(root, 8);
	root = root->right_insert(root, 4);
	root = root->left_insert(root, 2);
	root = root->left_insert(root, 3);
	root = root->right_insert(root, 5);
	root->inorder(root);
	cout<<endl;
	root->preorder(root);
	cout<<endl;
	root->postorder(root);
	cout<<endl;
	cout<<root->find(root, 4)<<"\n";
	cout<<root->find(root,7)<<"\n";
}
